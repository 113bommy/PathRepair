#include <bits/stdc++.h>
using namespace std;
const int N = 15;
const int S = 1 << N;
const int INF = 0x3f3f3f3f;
int d[N][N], deg[N];
int a[N];
int dp[S];
int n, m;
int main() {
  scanf("%d%d", &n, &m);
  memset(d, INF, sizeof(d));
  for (int i = 0; i < n; ++i) d[i][i] = 0;
  int sum = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    sum += w;
    deg[--u]++;
    deg[--v]++;
    d[u][v] = min(d[u][v], w);
    d[v][u] = min(d[v][u], w);
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  for (int i = 0; i < n; ++i) {
    if (m > 0 && d[0][i] == INF) {
      puts("-1");
      return 0;
    }
  }
  memset(dp, INF, sizeof(dp));
  int c = 0;
  for (int i = 0; i < n; ++i) {
    if (deg[i] & 1) a[c++] = i;
  }
  dp[0] = 0;
  for (int mask = 0; mask < (1 << c); ++mask) {
    for (int i = 0; i < c; ++i)
      if (!(mask & (1 << i))) {
        for (int j = i + 1; j < c; ++j)
          if (!(mask & (1 << j))) {
            dp[mask | (1 << i) | (1 << j)] =
                min(dp[mask | (1 << i) | (1 << j)], dp[mask] + d[a[i]][a[j]]);
          }
        break;
      }
  }
  printf("%d\n", sum + dp[(1 << c) - 1]);
  return 0;
}
