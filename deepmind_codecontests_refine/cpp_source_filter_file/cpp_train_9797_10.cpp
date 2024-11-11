#include <bits/stdc++.h>
int main() {
  int n, k;
  std::cin >> n >> k;
  if (n <= 2 * k + 1) {
    std::cout << 1 << "\n" << n / 2 << std::endl;
    return 0;
  }
  int p = (n - 2 * k + 2) / (2 * k + 1);
  int q = (n - 2 * k + 2) % (2 * k + 1);
  std::cout << p + 1 << std::endl;
  int pt = (q <= k) ? 1 : (q - k + 1);
  for (int i = 0; i != p + 1; ++i) {
    std::cout << pt + i * (2 * k + 1) << " ";
  }
  std::cout << std::endl;
}
