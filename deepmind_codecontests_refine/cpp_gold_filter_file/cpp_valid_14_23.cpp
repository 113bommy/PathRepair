#include <bits/stdc++.h>
constexpr int N = 2005;
int T, n, k;
int a[N], f[N][N];
int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(nullptr);
  std::cin >> T;
  while (T--) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i], a[i] = i - a[i];
    for (int i = 1; i <= n; ++i)
      for (int j = 0; j <= i; ++j) {
        f[i][j] = f[i - 1][j];
        if (a[i] == j) ++f[i][j];
        if (j) f[i][j] = std::max(f[i][j], f[i - 1][j - 1]);
      }
    bool ok = false;
    for (int i = 0; i <= n; ++i)
      if (f[n][i] >= k) {
        std::cout << i << '\n';
        ok = true;
        break;
      }
    if (!ok) std::cout << "-1\n";
  }
  return 0;
}
