#include <bits/stdc++.h>
const int N = 100005;
int n, a[N], b[N], base[30];
std::vector<std::pair<int, int>> ans0, ans1;
void operate(int x, int y, std::vector<std::pair<int, int>>& ans = ans0,
             int* a = ::a) {
  ans.emplace_back(x, y), a[x] ^= a[y];
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  for (int i = 1; i <= n; ++i) std::cin >> b[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 29; ~j; --j)
      if (a[i] >> j & 1) {
        if (base[j])
          operate(i, base[j]);
        else {
          base[j] = i;
          break;
        }
      }
  }
  for (int i = 0; i < 30; ++i)
    for (int j = i - 1; ~j; --j)
      if (base[j] && a[base[i]] >> j & 1) operate(base[i], base[j]);
  for (int i = 1; i <= n; ++i) {
    int x = b[i];
    for (int j = 30; ~j; --j)
      if (x >> j & 1) x ^= a[base[j]];
    if (x) return std::cout << "-1\n", 0;
  }
  for (int i = 1; i <= n; ++i)
    if (!a[i]) {
      for (int j = 30; ~j; --j)
        if (b[i] >> j & 1) operate(i, base[j]);
    }
  for (int i = 0; i < 30; ++i)
    if (base[i]) {
      int row = -1;
      for (int j = i; j < 30; ++j)
        if (b[base[j]] >> i & 1) row = j;
      if (row == -1) {
        for (int j = 0; j < i; ++j)
          if (b[base[j]] >> i & 1) operate(base[j], base[i]);
        operate(base[i], base[i]);
        continue;
      }
      if (row != i) {
        operate(base[i], base[row], ans1, b);
        operate(base[row], base[i], ans1, b);
        operate(base[i], base[row], ans1, b);
      }
      for (int j = 0; j < 30; ++j)
        if (i != j)
          if (b[base[j]] >> i & 1) operate(base[j], base[i], ans1, b);
    }
  for (int i = ans1.size() - 1; ~i; --i) operate(ans1[i].first, ans1[i].second);
  std::cout << ans0.size() << '\n';
  for (auto p : ans0) std::cout << p.first << ' ' << p.second << '\n';
  return 0;
}
