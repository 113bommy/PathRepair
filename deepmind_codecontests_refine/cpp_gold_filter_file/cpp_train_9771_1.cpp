#include <bits/stdc++.h>
int main() {
char c; std::cin >> c;
std::cout << (std::string("aiueo").find(c) != std::string::npos ? "vowel" : "consonant") << "\n";
}