#include <bits/stdc++.h>
int main(int argc, const char* argv[]) {
  std::uint16_t x[3];
  std::cin >> x[0];
  std::cin >> x[1];
  std::cin >> x[2];
  if (x[0] <= x[1]) {
    if (x[1] <= x[2]) {
      std::cout << x[2] - x[0] << std::endl;
      return 0;
    }
    if (x[2] <= x[0]) {
      std::cout << x[1] - x[2] << std::endl;
      return 0;
    }
    std::cout << x[1] - x[0] << std::endl;
  } else {
    if (x[0] <= x[2]) {
      std::cout << x[2] - x[0] << std::endl;
      return 0;
    }
    if (x[2] <= x[1]) {
      std::cout << x[0] - x[2] << std::endl;
      return 0;
    }
    std::cout << x[0] - x[1] << std::endl;
  }
}
