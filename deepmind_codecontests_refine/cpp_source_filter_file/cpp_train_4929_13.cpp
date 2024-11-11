#include <bits/stdc++.h>
using namespace std;
const int N = 61;
int n, m, q, g[N][N][N], dp[N][N][N];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int car = 0; car < m; ++car) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) scanf("%d", &g[car][i][j]);
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
          g[car][i][j] = min(g[car][i][j], g[car][i][k] + g[car][k][j]);
  }
  memset(dp, 0x3f, sizeof dp);
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < n; ++k) dp[0][j][k] = min(dp[0][j][k], g[i][j][k]);
  for (int l = 1; l <= n; ++l)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          dp[l][i][j] = min(dp[l][i][j], dp[l - 1][i][k] + dp[0][k][j]);
  while (q--) {
    int u, v, k;
    scanf("%d%d%d", &u, &v, &k);
    --u, --v;
    printf("%d\n", dp[k][u][v]);
  }
  return 0;
}
