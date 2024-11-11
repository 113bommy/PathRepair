#include <bits/stdc++.h>
using namespace std;
double f[3001][301], g[301], p[3001][301], ans = 0.0, s[3001];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) f[0][i] = 1.0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      p[i][j] = 1.0 * x / 1000;
      f[i][j] = f[i - 1][j] * (1.0 - p[i][j]);
    }
  for (int i = 1; i <= m; i++) g[i] = 1.0 - f[n][i];
  for (int i = 1; i <= n; i++) {
    int k = 1;
    for (int j = 2; j <= m; j++)
      if (g[j] > g[k]) k = j;
    ans += g[k];
    for (int j = 0; j <= n; j++) s[j] = f[j][k];
    f[0][k] = 0.0;
    for (int j = 1; j <= n; j++)
      f[j][k] = s[j - 1] * p[j][k] + f[j - 1][k] * (1.0 - p[j][k]);
    g[k] -= f[n][k];
  }
  printf("%.10lf\n", ans);
  return 0;
}
