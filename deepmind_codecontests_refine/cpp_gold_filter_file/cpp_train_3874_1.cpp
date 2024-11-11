#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using ll = int64_t;
using ull = uint64_t;
void AdjustStreams() {
  std::cin.tie(nullptr);
  std::cout.sync_with_stdio(false);
  std::cin.sync_with_stdio(false);
}
int main() {
  AdjustStreams();
  ll t;
  std::cin >> t;
  for (int i = 0; i < t; ++i) {
    ll a[3];
    std::cin >> a[0] >> a[1] >> a[2];
    std::sort(a, a + 3);
    if (a[2] <= a[0] + a[1]) {
      std::cout << (a[0] + a[1] + a[2]) / 2 << std::endl;
    } else {
      std::cout << a[0] + a[1] << std::endl;
    }
  }
  return 0;
}
