#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const double eps = 1E-8;
const int N = 210;
int n, m, g[N][N], d[N][N];
int check(int u, int v) {
  pair<int, int> t[N], tt[N];
  for (int i = 1; i <= n; i++) t[i] = make_pair(d[u][i], d[v][i]);
  sort(t + 1, t + 1 + n);
  int c = 0;
  for (int i = 1; i <= n; i++) {
    while (c && tt[c].second <= t[i].second) c--;
    tt[++c] = t[i];
  }
  if (c == 1)
    return min(tt[1].first, tt[1].second);
  else {
    int ret = 0x7fffffff;
    for (int i = 1; i < c; i++)
      ret = min(ret, (g[u][v] + tt[i].first + tt[i + 1].second) / 2);
    return ret;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  (memset(g, 0x3f, sizeof(g)));
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    g[a][b] = g[b][a] = 2 * c;
  }
  for (int i = 1; i <= n; i++) g[i][i] = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) d[i][j] = g[i][j];
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
  int ans = 0x7fffffff;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (d[i][j] != INF) ans = min(ans, check(i, j));
  printf("%f\n", ans / 2.0);
  return 0;
}
