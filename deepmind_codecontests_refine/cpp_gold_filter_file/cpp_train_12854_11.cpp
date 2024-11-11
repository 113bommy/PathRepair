#include <bits/stdc++.h>
using namespace std;
int n, m, dfn[2003], col[2003], st[2003], DFSTime, C, ln, lev;
vector<int> e[2003], g[2003];
int Tarjan(int fa, int u) {
  if (dfn[u]) return dfn[u];
  int low = dfn[u] = ++DFSTime;
  st[++st[0]] = u;
  for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != fa) low = min(low, Tarjan(u, e[u][i]));
  if (dfn[u] == low)
    for (++C;;) {
      col[st[st[0]]] = C;
      if (st[st[0]--] == u) break;
    }
  return low;
}
int DFS(int fa, int u) {
  dfn[u] = 1;
  if (g[u].size() < 2) ++lev;
  int p = 0, q = 0;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v != fa) {
      int res = DFS(u, v);
      if (res > p) {
        q = p;
        p = res;
      } else if (res > q)
        q = res;
    }
  }
  ln = max(ln, p + q + 1);
  return p + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i)
    if (!dfn[i]) Tarjan(0, i);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < e[i].size(); ++j) {
      int k = e[i][j];
      if (col[k] == col[i]) continue;
      g[col[i]].push_back(col[k]);
    }
  for (int i = 1; i <= C; ++i) dfn[i] = 0;
  int ans = n - 1;
  for (int i = 1; i <= C; ++i) {
    if (dfn[i]) continue;
    ln = lev = 0;
    DFS(0, i);
    if (ln >= 2)
      ans -= lev - 2 + ln;
    else
      ans--;
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}
