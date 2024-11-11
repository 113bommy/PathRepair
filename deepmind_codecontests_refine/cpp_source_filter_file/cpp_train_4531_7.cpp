#include <bits/stdc++.h>
int64_t bins(int64_t n) {
  int64_t l = 1, r = 1000 * 1000 * 1000;
  while (l < r) {
    int64_t mid = (l + r) / 2;
    if (3 * mid * mid - 3 * mid + 1 >= n) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int64_t n;
  std::cin >> n;
  ++n;
  if (n == 1) {
    std::cout << "0 0" << std::endl;
    return 0;
  }
  int64_t k = bins(n);
  n -= (3 * (k - 1) * (k - 1) - 3 * (k - 1) + 1);
  if (n <= k - 1) {
    std::cout << 2 * k - n - 2 << " " << 2 * n << std::endl;
    return 0;
  }
  n -= (k - 1);
  if (n <= k - 1) {
    std::cout << k - 1 - 2 * n << " " << 2 * k - 2 << std::endl;
    return 0;
  }
  n -= (k - 1);
  if (n <= k - 1) {
    std::cout << -k + 1 - n << " " << 2 * k - 2 - 2 * n << std::endl;
    return 0;
  }
  n -= (k - 1);
  if (n <= k - 1) {
    std::cout << -2 * k + 2 + n << " " << -2 * n << std::endl;
    return 0;
  }
  n -= (k - 1);
  if (n <= k - 1) {
    std::cout << -k + 1 + 2 * n << " " << -2 * k + 2 << std::endl;
    return 0;
  }
  n -= (k - 1);
  std::cout << k - 1 + 1 << " " << -2 * k + 2 + 2 * n << std::endl;
  return 0;
}
