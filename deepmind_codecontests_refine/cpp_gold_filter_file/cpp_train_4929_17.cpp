#include <bits/stdc++.h>
using namespace std;
const int maxn = 70, maxm = 70, cs = 1073741824;
int g[maxn][maxn], f[maxn][maxn], s[maxn][maxn][maxn];
int main() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) g[i][j] = cs;
  for (int T = 1; T <= m; ++T) {
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) scanf("%d", &f[i][j]);
    for (int k = 1; k <= n; ++k)
      for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j) g[i][j] = min(g[i][j], f[i][j]);
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 0; k < n; ++k) s[i][j][k] = cs;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) s[i][j][0] = g[i][j];
  for (int k = 1; k < n; ++k)
    for (int l = 1; l <= n; ++l)
      for (int i = 1; i <= n; ++i)
        if ((i != l) && (s[i][l][k - 1] != cs))
          for (int j = 1; j <= n; ++j)
            if ((j != i) && (j != l) && (g[l][j] != cs))
              s[i][j][k] = min(s[i][j][k], s[i][l][k - 1] + g[l][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      for (int k = 1; k < n; ++k) s[i][j][k] = min(s[i][j][k], s[i][j][k - 1]);
  for (int i = 1; i <= r; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    c = min(c, n - 1);
    printf("%d\n", s[a][b][c]);
  }
}
