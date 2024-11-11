#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, m, vis[N], ins[N], deg[N], stk[N], tp;
basic_string<int> g[N], G[N];
void dfs(int u) {
  vis[u] = ins[u] = 1;
  for (int v : g[u]) {
    if (!ins[v]) G[u] += v, ++deg[v];
    if (!vis[v]) dfs(v);
  }
  ins[u] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, a, b; i <= m; ++i) scanf("%d%d", &a, &b), g[a] += b;
  for (int i = 1; i <= n; ++i)
    if (!vis[i]) dfs(i);
  for (int i = 1; i <= n; ++i)
    if (!deg[i]) stk[++tp] = i;
  while (tp > 1) {
    int u = stk[tp--], v = stk[tp--], c;
    printf("? %d %d\n", u, v), fflush(stdout);
    scanf("%d", &c);
    if (!c) swap(u, v);
    stk[++tp] = u;
    for (int y : G[v])
      if (--deg[y] == 0) stk[++tp] = y;
  }
  printf("%d", stk[tp]);
  return 0;
}
