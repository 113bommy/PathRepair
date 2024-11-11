#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int a, b;
  std::cin >> a >> b;
  if (a == b) {
    std::cout << a / b << " "
              << "0" << std::endl;
  } else if (a > b) {
    std::cout << b << " " << (a - b) / 2 << std::endl;
  } else {
    std::cout << a << " " << (b - a) / 2 << std::endl;
  }
  return 0;
}
