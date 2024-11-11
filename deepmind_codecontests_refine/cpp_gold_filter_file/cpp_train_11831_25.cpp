#include <bits/stdc++.h>
int main() {
  std::string src;
  std::cin >> src;
  size_t ret = 0;
  for (const auto c : src) {
    switch (c) {
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
        ret += 1;
        break;
    }
  }
  std::cout << ret << '\n';
  return 0;
}
