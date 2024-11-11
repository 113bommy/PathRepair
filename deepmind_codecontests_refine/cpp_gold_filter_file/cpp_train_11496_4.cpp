#include <bits/stdc++.h>
using namespace std;
int a[41][41], s[41][41], f[41][41][41][41], g[41][41][41][41];
int i, j, k, t, m, n, q, p;
char ch;
int main() {
  cin >> m >> n >> q;
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) {
      cin >> ch;
      a[i][j] = ch - 48;
    }
  memset(s, 0, sizeof(s));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
  memset(g, 0, sizeof(g));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = i; k >= 1; k--)
        for (int t = j; t >= 1; t--) {
          g[i][j][k][t] =
              g[i][j][k + 1][t] + g[i][j][k][t + 1] - g[i][j][k + 1][t + 1];
          if (s[i][j] - s[i][t - 1] - s[k - 1][j] + s[k - 1][t - 1] == 0)
            g[i][j][k][t]++;
        }
  memset(f, 0, sizeof(f));
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = i; k <= m; k++)
        for (int t = j; t <= n; t++) {
          f[i][j][k][t] = f[i][j][k - 1][t] + f[i][j][k][t - 1] -
                          f[i][j][k - 1][t - 1] + g[k][t][i][j];
        }
  for (int p = 1; p <= q; p++) {
    cin >> i >> j >> k >> t;
    cout << f[i][j][k][t] << "\n";
  }
  return 0;
}
