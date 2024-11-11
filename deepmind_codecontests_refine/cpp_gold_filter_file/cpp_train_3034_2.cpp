#include <bits/stdc++.h>
const long long MOD = 1000000007LL;
const std::vector<std::vector<int>> c{
    {0, 0, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}, {0, 1, 0, 1}};
bool wrong(std::vector<int> const& b) {
  for (int i = 0; i < 4; ++i) {
    bool g = true;
    for (int j = 0; j < 4; ++j)
      if (b[j] != c[i][j]) g = false;
    if (g) return true;
  }
  return false;
}
int main() {
  int m;
  std::cin >> m;
  std::vector<int> s(m);
  for (int i = 0; i < m; ++i) std::cin >> s[i];
  std::vector<std::vector<long long>> d(m, std::vector<long long>(m + 1));
  for (int i = 0; i < m; ++i) d[i][i] = 1;
  for (int i = 0; i < m; ++i)
    for (int j = i + 1; j <= m; ++j) {
      d[i][j] = d[i][j - 1];
      if (j > i + 1) d[i][j] = (d[i][j] + d[i][j - 2]) % MOD;
      if (j > i + 2) d[i][j] = (d[i][j] + d[i][j - 3]) % MOD;
      if (j > i + 3) {
        std::vector<int> v(4);
        std::copy(s.begin() + j - 4, s.begin() + j, v.begin());
        if (!wrong(v)) d[i][j] = (d[i][j] + d[i][j - 4]) % MOD;
      }
    }
  std::vector<long long> res(m + 1, 0);
  res[0] = 0;
  for (int i = 1; i <= m; ++i) {
    std::vector<int> p(i);
    std::vector<int> rs(i);
    for (int j = i - 1; j >= 0; --j) rs[i - j - 1] = s[j];
    p[0] = 0;
    for (int j = 1; j < i; ++j) {
      int x = p[j - 1];
      for (; x > 0 && rs[x] != rs[j]; x = p[x - 1]) {
      }
      if (rs[x] == rs[j]) {
        p[j] = x + 1;
      } else
        p[j] = x;
    }
    int max = 0;
    for (int j = 1; j < i; ++j) max = std::max(max, p[j]);
    res[i] = res[i - 1];
    for (int j = i - max - 1; j >= 0; --j) {
      res[i] = (d[j][i] + res[i]) % MOD;
    }
    std::cout << res[i] << "\n";
  }
}
