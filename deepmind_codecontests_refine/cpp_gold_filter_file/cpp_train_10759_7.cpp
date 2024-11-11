#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 100010;
int dg[30], dis[30][30], od[30], ptr;
int dp[1 << 16], val[900], cost[900], base[30];
void floyd(int n) {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dis[i][k] + dis[k][j] < dis[i][j])
          dis[i][j] = dis[i][k] + dis[k][j];
}
int main() {
  int n, m, i, j, ans, u, v, w, ct, lim;
  for (i = base[0] = 1; i < 30; i++) base[i] = base[i - 1] << 1;
  while (~scanf("%d%d", &n, &m)) {
    ans = ptr = ct = 0;
    memset(dis, 0x3f, sizeof dis);
    memset(dg, 0, sizeof dg);
    memset(dp, 0x3f, sizeof dp);
    for (i = 1; i <= n; i++) dis[i][i] = 0;
    for (i = 0; i < m; i++) {
      scanf("%d%d%d", &u, &v, &w);
      dis[v][u] = dis[u][v] = min(dis[u][v], w);
      dg[u]++, dg[v]++, ans += w;
    }
    for (i = 1; i <= n; i++)
      if (dg[i] & 1) od[ptr++] = i;
    if (ptr & 1) {
      printf("-1\n");
      continue;
    }
    floyd(n);
    for (i = 1; i <= n; i++)
      if (dg[i] && dis[1][i] >= INF) break;
    if (i <= n) {
      printf("-1\n");
      continue;
    }
    for (i = 0; i < ptr; i++)
      for (j = i + 1; j < ptr; j++)
        val[ct] = base[i] | base[j], cost[ct++] = dis[od[i]][od[j]];
    dp[0] = 0, lim = 1 << ptr;
    for (i = 0; i < lim; i++) {
      for (j = 0; j < ct; j++) {
        if (i & val[j]) continue;
        dp[i | val[j]] = min(dp[i | val[j]], dp[i] + cost[j]);
      }
    }
    ans += dp[lim - 1];
    printf("%d\n", ans);
  }
  return 0;
}
