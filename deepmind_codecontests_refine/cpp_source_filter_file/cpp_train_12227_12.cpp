#include <bits/stdc++.h>
int val[500];
int cost[500][500];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &val[i]);
  for (int i = 0; i < m; i++) {
    int u, v, c;
    scanf("%d %d %d", &u, &v, &c);
    u--;
    v--;
    cost[u][v] = cost[v][u] = c;
  }
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (cost[i][j])
        ans = ((ans) > ((double)(val[i] + val[j]) / (double)cost[i][j])
                   ? (ans)
                   : ((double)(val[i] + val[j]) / (double)cost[i][j]));
    }
  }
  printf("%lf", ans);
}
