#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, f[N][N], g[N][N][N];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, cnt; i <= n; i++) {
    scanf("%d", &cnt);
    for (int j = 1, l, r; j <= cnt; j++) {
      scanf("%d%d", &l, &r);
      for (int k = l; k <= r; k++) g[k][l][r]++;
    }
  }
  for (int i = m; i >= 1; i--)
    for (int j = i; j <= m; j++)
      for (int k = i; k <= j; k++) {
        g[k][i][j] += g[k][i][j - 1] + g[k][i + 1][j] - g[k][i + 1][j - 1];
        f[i][j] =
            max(f[i][j], f[i][k - 1] + f[k + 1][j] + g[k][i][j] * g[k][i][j]);
      }
  printf("%d", f[1][m]);
  return 0;
}
