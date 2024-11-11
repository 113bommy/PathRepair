#include <bits/stdc++.h>
int main() {
  uint16_t num;
  std::cin >> num;
  std::cin.ignore(10000, '\n');
  std::string str;
  std::getline(std::cin, str);
  uint32_t pos_r = str.find("R");
  if (pos_r != std::string::npos) {
    uint32_t pos_l = str.find("L");
    if (pos_l != std::string::npos) {
      std::cout << pos_r + 1 << " " << pos_l;
    } else {
      std::cout << pos_r + 1 << " " << str.find_last_of("R") + 2;
    }
  } else {
    std::cout << str.find_last_of("L") + 1 << " " << str.find("L") + 1;
  }
  return 0;
}
