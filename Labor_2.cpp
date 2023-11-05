#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <unordered_map>
#include <random>
#include <ctime>
#include <Windows.h>

void demoAnalysis();
void randomAnalysis();
void inputAnalysis();
void rangePrint();
void iterationPrint();
void forLoopPrint();
void analyseGrades();
void printAvgGrade();
void printMedian();
void printMode();
void cocktailSort(std::vector<int>& input);

const std::string NAMES_LIST[] = {
    "Платон",
    "Андрей",
    "Ксения",
    "Диана",
    "Алиса",
    "Виктория",
    "Василиса",
    "Илья",
    "Степан",
    "Евгений",
    "Кирилл",
    "Максим",
    "Вероника",
    "Артемий",
    "София",
    "Тимур",
    "Полина",
    "Максим",
    "Кирилл",
    "Даниил",
    "Илья",
    "Алина",
    "Евгения",
    "Лидия",
    "Артём",
    "Даниил",
    "Артём",
    "Захар",
    "Арина",
    "Семён",
    "Алиса",
    "Даниил",
    "Алиса",
    "Анастасия",
    "Екатерина",
    "Герман",
    "Елизавета",
    "Вероника",
    "Дмитрий",
    "София",
    "Платон",
    "Никита",
    "Елизавета",
    "София",
    "Василиса",
    "Мария",
    "Георгий",
    "Александр",
    "Фёдор",
    "Василиса",
    "Николай",
    "Алиса",
    "Михаил",
    "Анна",
    "Маргарита",
    "Захар",
    "София",
    "Мирон",
    "Алина",
    "Виктория",
    "Артём",
    "Василиса",
    "Полина",
    "Анастасия",
    "Максим",
    "Тимофей",
    "Екатерина",
    "Кирилл",
    "Арсений",
    "Ксения",
    "Богдан",
    "Милана",
    "Алиса",
    "Мария",
    "Ксения",
    "Василиса",
    "Милана",
    "Владислава",
    "Александр",
    "Валерия",
    "Роман",
    "Максим",
    "Тимофей",
    "Владислав",
    "Матвей",
    "Дарья",
    "Даниил",
    "Ксения",
    "Алёна",
    "Алиса",
    "Сергей",
    "Алиса",
    "Иван",
    "Владимир",
    "Тимофей",
    "Михаил",
    "Диана",
    "Александр",
    "Арсений",
    "София"
}; // Словарь случайных имен 

std::vector<std::string> names = {};  
std::vector<int> grades = {};         

int main()
{
    srand(time(NULL));                
    setlocale(LC_ALL, "rus");         
    SetConsoleOutputCP(1251);         
    SetConsoleCP(1251);               
    char* input = new char;           

    //// ПУНКТ 1

    while (true) {                                                          
        system("cls");                                                       
        printf("Выберите способ инициализации вектора:\n\n"                    
            "1. Демонстрационный анализ на предустановленных значениях.\n"
            "2. Анализ на случайных значениях\n"
            "3. Ввод и анализ значений\n\n"
            "Введите выбор и нажмите Enter: ");
        std::cin >> *input;                     // Принимаем выбор пользователя и записываем в переменную input

        if (!isdigit(*input)) continue;         // Если пользователь ввел что-то не то - запрашиваем повторно
        if (0 < ((int)*input - 48) < 4) break;  // Иначе - выходим из цикла ввода
    }

    int choice = (int)*input - 48;  // Преобразуем введённый символ в число

    switch (choice) {       
    case 1:
        demoAnalysis();     // Демонстрационный анализ с предустановленными значениями
        break;
    case 2:
        randomAnalysis();   // Анализ на случайных значениях
        break;
    case 3:
        inputAnalysis();    // Анализ на основе данных пользователя
        break;
    }
    system("pause");         
}

void demoAnalysis() {  
    names = { "Владислав", "Андрей", "Георгий", "София", "Александр", "Дмитрий", "Светлана", "Николай", "Мохаммед", "Алоис" }; // Предустановленные имена
    grades = { 38,83,41,48,32,50,26,52,50,65 };  

    system("cls");    
    rangePrint();      
    analyseGrades();  
}

void randomAnalysis() {  
    std::cout << "Введите размер выборки: ";  
    int setSize = 1;                          
    std::cin >> setSize;                     

    for (int i = 0; i < setSize; i++) {              
        names.push_back(NAMES_LIST[rand() % 100]);   
        grades.push_back(rand() % 101);             
    }

    system("cls");    
    rangePrint();      
    analyseGrades();   
}

void inputAnalysis() { // Функция анализа на пользовательских данных

    printf("Введите значения в консоль.\n"); 
    printf("Вводить в формате [имя оценка], без квадратных скобок. Введите [0 0] без скобок для начала анализа.\n");

    std::string name; 
    int grade;        

    while (true) {    
        std::cin >> name >> grade;              // Сохраняем введённые данные в буфера
        if (name == "0" && grade == 0) break;   // Если пользователь ввёл [0 0] - выходим из цикла ввода
        names.push_back(name);                  // Сохраняем имя из буфера в вектор
        grades.push_back(grade);                // Сохраняем оценку из буфера в вектор
    }

    if (names.size() == 0 || grades.size() == 0) {                          
        printf("Не было введено значений, программа завершает работу...");  
        return;                                                             
    }

    system("cls");    
    rangePrint();     
    analyseGrades();  
}
//// КОНЕЦ ПУНКТА 1

//// ПУНКТ 2
void rangePrint() { // Функция вывода данных через range-based for-loop

    std::map<std::string, int> buffer;  //у нас нет какого-то красивого пути итерировать таким способом по двум векторам одновременно,
    //поэтому придется соединить их в таблицу-буфер

    std::transform(names.begin(), names.end(), grades.begin(), std::inserter(buffer, buffer.end()), [](std::string a, int b) {
        return std::make_pair(a, b); // Заполняем таблицу парами имя-оценка, где имя - это ключ
        });

    for (auto& [a, b] : buffer) std::cout << a << ' ' << b << '\n'; 
    std::cout << '\n';                                             
}

void iterationPrint() { // Функция вывода через итератор
    for (auto [n, g] = std::tuple{ names.begin(), grades.begin() }; n != names.end() && g != grades.end(); n++, g++) // Создаём пару итераторов и идём по ним в цикле 
        std::cout << *n << ' ' << *g << '\n'; 
    std::cout << '\n';                       
}

void forLoopPrint() { 
    for (int i = 0; i < (((names.size()) < (grades.size())) ? (names.size()) : (grades.size())); i++) 
        std::cout << names[i] << ' ' << grades[i] << '\n'; 
    std::cout << '\n'; 
}
//// КОНЕЦ ПУНКТА 2

//// ПУНКТ 3 + 4
void analyseGrades() { // Функция анализа и вывода результатов (по факту сокращение для читаемости кода)
    printAvgGrade();   // Нахождение среднего
    printMedian();     // Нахождение медианы
    printMode();       // Нахождение моды
}

void printAvgGrade() { 
    double avg = 0.0;  
    for (auto i : grades) avg += (double)i; 
    avg /= grades.size();                
    std::cout << "Среднее значение оценок: " << avg << '\n'; 
}

void printMedian() { 
    std::vector<int> sortedGrades = grades; 
    cocktailSort(sortedGrades);             

    double median = (sortedGrades.size() % 2 == 0) ?                                                                     // Выбираем медиану
        ((double)sortedGrades.at(sortedGrades.size() / 2) + (double)sortedGrades.at(sortedGrades.size() / 2 - 1)) / 2 :  // Если количество элементов четное - находим среднее между двумя центральными элементами
        sortedGrades.at(std::floor(sortedGrades.size() / 2));                                                            // Иначе - берём центральный элемент
    std::cout << "Медиана: " << median << '\n'; 
}

void printMode() { // Функция нахождения моды
    std::unordered_map<int, int> gradesHashmap;  
    for (auto i : grades) gradesHashmap[i] += 1; 

    int maxFreq = 0;                            
    for (auto& [a, b] : gradesHashmap)           
        if (b > maxFreq)
            maxFreq = b;

    std::vector<int> freqGrades;                 
    for (auto& [a, b] : gradesHashmap)           
        if (b == maxFreq)
            freqGrades.push_back(a);

    std::cout << "Моды: ";
    for (auto i : freqGrades)
        std::cout << i << ' ';
    std::cout << '\n';       
    std::cout << "Ученики, оценка которых соответствует моде (модам):\n";
    for (int i = 0; i < names.size(); i++) {
        if (std::find(freqGrades.begin(), freqGrades.end(), grades.at(i)) != freqGrades.end()) {
            std::cout << names.at(i) << ' ' << grades.at(i) << '\n';
        }
    }
}
//// КОНЕЦ ПУНКТА 3 + 4

//// ПУНКТ 3*
void cocktailSort(std::vector<int>& input)
{
    bool swapped = true;
    int start = 0;
    int end = input.size() - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (input[i] > input[i + 1]) {
                std::swap(input[i], input[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i) {
            if (input[i] > input[i + 1]) {
                
                std::swap(input[i], input[i + 1]);
               
                swapped = true;
            }
        }
        ++start;
    }
}