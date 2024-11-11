#include <bits/stdc++.h>
int main() {
  std::string s;
  std::getline(std::cin, s);
  size_t k = 0;
  for (char c : s) switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      case '1':
      case '3':
      case '5':
      case '7':
      case '9':
        ++k;
        break;
    }
  std::cout << k;
}
