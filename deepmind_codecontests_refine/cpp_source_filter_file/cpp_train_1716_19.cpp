#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(0);
  long long c, h1, h2, w1, w2, ans = 0;
  std::cin >> c >> h1 >> h2 >> w1 >> w2;
  for (long long i = 0; i < 10000000; i++) {
    if (h1 * i <= c) ans = std::max(ans, h1 * i + (c - w1 * i) / w2 * h2);
    if (h2 * i <= c) ans = std::max(ans, h2 * i + (c - w2 * i) / w1 * h1);
  }
  std::cout << ans << std::endl;
  return 0;
}
