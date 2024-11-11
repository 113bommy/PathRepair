#include <bits/stdc++.h>
using namespace std;
int dis[666][666], n, m, t, l, r, p, mid, g[666][666];
int linker[666], a[666];
bool v[666];
bool dfs(int u, int x) {
  for (int i = 1; i <= n; i++)
    if (dis[a[u]][i] <= x && !v[i]) {
      v[i] = true;
      if (linker[i] == -1 || dfs(linker[i], x)) {
        linker[i] = u;
        return true;
      }
    }
  return false;
}
bool check(int x) {
  memset(linker, -1, sizeof(linker));
  int tmp = 0;
  for (int i = 1; i <= p; i++) {
    memset(v, 0, sizeof(v));
    if (dfs(i, x)) tmp++;
  }
  return tmp >= t;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &p, &t);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i == j)
        dis[i][j] = 0;
      else
        dis[i][j] = 1000000007;
  for (int i = 1; i <= p; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    dis[u][v] = min(dis[u][v], w);
    dis[v][u] = min(dis[v][u], w);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        if (dis[i][k] + dis[k][j] < dis[i][j])
          dis[i][j] = dis[i][k] + dis[k][j];
  l = 0;
  r = 1731311;
  while (r - l > 1) {
    mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  if (check(l))
    printf("%d\n", l);
  else if (!check(r))
    printf("-1\n");
  else
    printf("%d\n", r);
  return 0;
}
