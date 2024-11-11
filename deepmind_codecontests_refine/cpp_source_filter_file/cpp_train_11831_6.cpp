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
      case '0':
      case '2':
      case '4':
      case '6':
      case '8':
        ++k;
        break;
    }
  std::cout << k;
}
