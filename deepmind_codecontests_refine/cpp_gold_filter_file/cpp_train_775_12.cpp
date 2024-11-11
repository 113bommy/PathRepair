#include <bits/stdc++.h>
int main() {
  int n1, n2, k1, k2;
  while (std::cin >> n1 >> n2 >> k1 >> k2) {
    if (n1 < 1 || n1 > 50 || n2 < 1 || n2 > 50 || k1 < 1 || k1 > 50 || k2 < 1 ||
        k2 > 50)
      return 0;
    while (true) {
      n1 -= 1;
      if (n1 <= 0) {
        std::cout << "Second\n";
        break;
      }
      n2 -= 1;
      if (n2 <= 0) {
        std::cout << "First\n";
        break;
      }
    }
  }
  return 0;
}
