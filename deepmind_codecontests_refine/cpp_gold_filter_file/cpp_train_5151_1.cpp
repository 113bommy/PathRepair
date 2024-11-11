#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5, K = 220, inf = 1e9;
int a[N], n, k;
int f[N][K][2], g[N][K][2];
int main() {
  scanf(" %d%d", &n, &k);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (k); i++)
    f[0][i][0] = f[0][i][1] = g[0][i][0] = g[0][i][1] = -inf;
  for (int i = (1); i <= (n); i++) {
    int x = a[i];
    for (int j = (1); j <= (k); j++) {
      int co = (j == 1 || j == k) ? 1 : 2;
      g[i][j][0] = g[i][j][1] = -inf;
      f[i][j][0] = max(f[i - 1][j][0] + co * x, g[i - 1][j - 1][1] + co * x);
      f[i][j][1] = max(f[i - 1][j][1] - co * x, g[i - 1][j - 1][0] - co * x);
      g[i][j][0] = max(g[i - 1][j][0], f[i][j][0]);
      g[i][j][1] = max(g[i - 1][j][1], f[i][j][1]);
      if (j > 1 && j < k) {
        g[i][j][0] = max(g[i][j][0], g[i - 1][j - 1][0]);
        g[i][j][1] = max(g[i][j][1], g[i - 1][j - 1][1]);
      }
    }
  }
  int ans = max(g[n][k][0], g[n][k][1]);
  printf("%d\n", ans);
  return 0;
}
