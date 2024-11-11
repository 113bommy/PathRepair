#include <bits/stdc++.h>
const int maxn = 1050;
inline int getint() {
  int ans(0);
  char w = getchar();
  while (w < '0' || '9' < w) w = getchar();
  while ('0' <= w && w <= '9') {
    ans = ans * 10 + w - '0';
    w = getchar();
  }
  return ans;
}
int n, m;
int ns, nd, n1;
int ans[maxn][maxn];
int main() {
  n = getint();
  m = getint();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int x = getint();
      switch (x) {
        case 1:
          ++ns;
          ++n1;
          break;
        case 10:
          ++ns;
          ++n1;
          break;
        case 11:
          ++nd;
          ++ ++n1;
          break;
      }
    }
  }
  int need = n1 / (m << 1) + (n1 % (m << 1) > 0);
  for (int i = 1; i <= n && nd; ++i)
    for (int j = 1; j <= m && nd; ++j) {
      ans[i][j] = 11;
      --nd;
    }
  for (int i = n; i && ns; --i)
    for (int j = m; j && ns; --j) {
      if (ans[i][j]) continue;
      ans[i][j] = 1;
      --ns;
      if (!ans[i - 1][j]) {
        ans[i - 1][j] = 10;
        --ns;
      }
    }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m; ++j) printf("%02d ", ans[i][j]);
    printf("%02d\n", ans[i][m]);
  }
  return 0;
}
