#include <bits/stdc++.h>
using namespace std;
const int maxn = 65;
const long long inf = 1e18 + 10;
int mat[maxn][maxn][maxn];
long long path[maxn][maxn];
long long dist[maxn][maxn];
long long dp[maxn][maxn][1002];
int main(void) {
  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  for (int t = 1; t <= m; t++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) scanf("%d", &mat[t][i][j]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) dist[i][j] = inf;
  for (int t = 1; t <= m; t++) {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) path[i][j] = mat[t][i][j];
    for (int k = 1; k <= n; k++)
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) dist[i][j] = min(dist[i][j], path[i][j]);
  }
  for (int k = 2; k <= 1001; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) dp[i][j][k] = inf;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j][1] = dist[i][j];
  for (int k = 2; k <= 1000; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int c = 1; c <= n; c++)
          dp[i][j][k] =
              min({dp[i][j][k - 1], dp[i][j][k], dp[i][c][k - 1] + dist[c][j]});
  for (int i = 1; i <= q; i++) {
    int u, v, k;
    scanf("%d %d %d", &u, &v, &k);
    printf("%lld\n", dp[u][v][k + 1]);
  }
}
