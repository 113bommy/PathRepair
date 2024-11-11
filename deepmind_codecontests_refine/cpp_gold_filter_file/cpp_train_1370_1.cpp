#include <bits/stdc++.h>
namespace io {
int F() {
  int F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
long long G() {
  long long F = 1, n = 0;
  char ch;
  while ((ch = getchar()) != '-' && (ch < '0' || ch > '9'))
    ;
  ch == '-' ? F = 0 : n = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') n = n * 10 + ch - '0';
  return F ? n : -n;
}
}  // namespace io
int R(int l, int r) { return (rand() << 15 | rand()) % (r - l + 1) + l; }
int n;
std::vector<int> d;
std::vector<bool> query(const std::vector<int> d) {
  std::vector<bool> ans;
  printf("? ");
  for (int i = 1; i <= n; ++i) printf("%d%c", d[i], " \n"[i == n]);
  fflush(stdout);
  char s[1111];
  scanf("%s", s);
  ans.resize(n + 1);
  for (int i = 0; i < n; ++i) ans[i + 1] = s[i] - '0';
  return ans;
}
std::vector<int> f[1111];
std::vector<bool> a, g[11];
int fa[1111];
void print(std::vector<int> f) {
  for (int j : f) printf("%d ", j);
  puts("");
}
int main() {
  n = io::F();
  int mdep = 1024;
  while (mdep / 2 >= n) mdep /= 2;
  d.resize(n + 1);
  f[0].push_back(1);
  for (int i = 2; i <= n; ++i) f[mdep].push_back(i);
  for (int T = mdep; T != 1; T >>= 1) {
    for (int z = 0; z < 3 * T && z < mdep; z += T) {
      int fl = 0;
      if (f[z + T].size() == 0) continue;
      for (int j = 1; j <= n; ++j) d[j] = 0;
      for (int i = z; i < mdep; i += 3 * T)
        for (auto j : f[i]) d[j] = T / 2, fl = 1;
      if (fl == 0) continue;
      a = query(d);
      for (int i = z + T; i <= mdep; i += 3 * T) {
        std::vector<int> g;
        for (auto j : f[i])
          if (a[j])
            f[i - T / 2].push_back(j);
          else
            g.push_back(j);
        f[i] = g;
      }
    }
  }
  while (f[mdep].size() == 0) --mdep;
  for (auto j : f[1]) fa[j] = 1;
  for (int z = 1; z <= 3; ++z) {
    int mx = 0;
    for (int i = z; i < mdep; i += 3)
      (mx < (f[i].size()) ? mx = (f[i].size()), 1 : 0);
    if (mx == 0) continue;
    int r = mx == 1 ? -1 : 31 - __builtin_clz(mx - 1);
    for (int i = 0; i <= r; ++i) {
      for (int j = 1; j <= n; ++j) d[j] = 0;
      for (int j = z; j < mdep; j += 3) {
        for (int k = 0; k < f[j].size(); ++k)
          if (k & 1 << i) d[f[j][k]] = 1;
      }
      g[i] = query(d);
    }
    for (int i = z + 1; i <= mdep; i += 3)
      for (auto j : f[i]) {
        for (int k = 0; k <= r; ++k)
          if (g[k][j]) fa[j] |= 1 << k;
        fa[j] = f[i - 1][fa[j]];
      }
  }
  puts("!");
  for (int i = 2; i <= n; ++i) printf("%d %d\n", i, fa[i]);
  return 0;
}
