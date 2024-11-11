#include <bits/stdc++.h>
int main() {
  bool f = false;
  std::cout << "? 0 0" << std::endl;
  int t;
  std::cin >> t;
  int a = 0, b = 0, x, y;
  for (int i = 1; i >= 0; --i) {
    std::cout << "? " << (a ^ (1 << i)) << " " << b << std::endl;
    std::cin >> x;
    std::cout << "? " << a << " " << (b ^ (1 << i)) << std::endl;
    std::cin >> y;
    if (x == y) {
      ((t == 1) ? a : b) ^= 1 << i;
      t = x;
    } else if (x == -1) {
      a ^= 1 << i;
      b ^= 1 << i;
    }
  }
  std::cout << "! " << a << " " << b << std::endl;
  return 0;
}
