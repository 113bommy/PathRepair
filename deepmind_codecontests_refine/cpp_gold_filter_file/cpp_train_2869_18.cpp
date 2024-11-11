#include <bits/stdc++.h>
int main() {
  int T;
  std::cin >> T;
  while (T--) {
    std::string temp;
    std::cin >> temp;
    temp.length() > 10 ? std::cout << temp[0] << temp.length() - 2
                                   << temp[temp.length() - 1] << std::endl
                       : std::cout << temp << std::endl;
  }
  return 0;
}
