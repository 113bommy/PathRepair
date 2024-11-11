#include <bits/stdc++.h>
int main() {
  int64_t n, x, y;
  std::cin >> n >> x >> y;
  if (n > y || n > x) {
    std::cout << -1;
    return 0;
  }
  if (n == 1 && ((pow(y, 2) >= x))) {
    std::cout << y;
    return 0;
  }
  if ((pow(y - n + 1, 2) + n - 1) < x) {
    std::cout << -1;
    return 0;
  }
  std::cout << y - n + 1 << std::endl;
  for (int xx = 0; xx < n - 1; ++xx) {
    std::cout << 1 << std::endl;
  }
  return 0;
}
