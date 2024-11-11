#include <bits/stdc++.h>
using namespace std;
const int MAXN = 61, INF = 2 * 1000 * 1000 * 1000;
int n, m, r, mat[MAXN][MAXN][MAXN], dis[MAXN][MAXN], d[MAXN][MAXN][MAXN];
void floyd(int car) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dis[i][j] = mat[car][i][j];
  for (int t = 1; t <= n; t++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        dis[i][j] = min(dis[i][j], dis[i][t] + dis[t][j]);
}
int main() {
  scanf("%d%d%d", &n, &m, &r);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) scanf("%d", &mat[i][j][k]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[0][i][j] = INF;
  for (int i = 1; i <= m; i++) {
    floyd(i);
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++) d[0][j][k] = min(d[0][j][k], dis[j][k]);
  }
  for (int k = 1; k < n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        d[k][i][j] = d[k - 1][i][j];
        for (int temp = 1; temp <= n; temp++)
          d[k][i][j] = min(d[k][i][j], d[k - 1][i][temp] + d[0][temp][j]);
      }
  for (int i = 1; i <= r; i++) {
    int s, t, k;
    scanf("%d%d%d", &s, &t, &k);
    k = min(k, n - 1);
    printf("%d\n", d[k][s][t]);
  }
  return 0;
}
