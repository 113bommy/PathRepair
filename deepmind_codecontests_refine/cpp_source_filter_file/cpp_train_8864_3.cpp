#include <bits/stdc++.h>
constexpr int Log = 20, M = 500000;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  std::vector<std::pair<int, int>> a(n);
  for (auto &[l, r] : a) {
    std::cin >> l >> r;
  }
  std::sort(a.begin(), a.end(),
            [&](const std::pair<int, int> &a, const std::pair<int, int> &b) {
              return a.second > b.second;
            });
  std::vector<std::vector<int>> next(M, std::vector<int>(Log, -1));
  int p = M;
  for (auto [l, r] : a) {
    p = std::min(p, r - 1);
    for (; p >= l; p--) {
      next[p][0] = r;
    }
  }
  for (int j = 1; j < Log; j++) {
    for (int i = 0; i < n; i++) {
      if (next[i][j - 1] != -1 && next[i][j - 1] != M) {
        next[i][j] = next[next[i][j - 1]][j - 1];
      }
    }
  }
  while (q--) {
    int x, y;
    std::cin >> x >> y;
    int ans = 0;
    for (int j = Log - 1; j >= 0; j--) {
      if (next[x][j] != -1 && next[x][j] < y) {
        ans += 1 << j;
        x = next[x][j];
      }
    }
    if (next[x][0] >= y) {
      std::cout << ans + 1 << "\n";
    } else {
      std::cout << -1 << "\n";
    }
  }
  return 0;
}
