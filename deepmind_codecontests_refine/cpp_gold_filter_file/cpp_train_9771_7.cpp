#include <iostream>
 
int main() {
char c;
std::cin >> c;
std::cout << ((c == 'a' || c == 'i' || c=='u'||c=='e'||c=='o') ? "vowel" : "consonant") << std::endl;
return 0;
}