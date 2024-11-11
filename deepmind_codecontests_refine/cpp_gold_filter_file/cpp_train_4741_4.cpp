#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::cout << (2 * (n / 3)) + ((n % 3 != 0) ? 1 : 0);
  return 0;
}
