#include <bits/stdc++.h>
int main() {
  size_t n;
  std::cin >> n;
  std::cout << n / 3 * 2 + (n % 3 > 0) << std::endl;
}
