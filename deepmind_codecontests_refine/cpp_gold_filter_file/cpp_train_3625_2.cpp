#include <iostream>
#include <algorithm>
#include <cctype>

int main() {
    std::string S;
    std::cin >> S;

    bool cond1 = S[0] == 'A';
    bool cond2 = std::count(S.begin() + 2, S.end() - 1, 'C') == 1;
    bool cond3 = std::count_if(S.begin(), S.end(), isupper) == 2;
    std::cout << (cond1 && cond2 && cond3 ? "AC" : "WA") << std::endl;
}
