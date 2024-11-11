#include <iostream>
#include <string>
int main() {
std::string S;
std::cin >> S;
for(int i=0;i<S.size()-8;i++)
 std::cout << S[i];
std::cout << std:endl;