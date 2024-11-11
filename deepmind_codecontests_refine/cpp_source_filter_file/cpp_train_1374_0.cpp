#include <bits/stdc++.h>
std::vector<int> g[1000011];
int t, n, m, dfn[1000011], low[1000011], scc[1000011], scnt = 0;
bool ins[1000011];
int s[1000011], cur = 0, top = 0;
void tarjan(int u) {
  dfn[u] = low[u] = ++cur;
  s[++top] = u, ins[u] = 1;
  for (int v : g[u])
    if (!dfn[v])
      tarjan(v), low[u] = std::min(low[u], low[v]);
    else if (ins[v])
      low[u] = std::min(low[u], low[v]);
  if (low[u] == dfn[u]) {
    ++scnt;
    while (s[top] != u) scc[s[top]] = scnt, ins[s[top--]] = 0;
    scc[s[top]] = scnt, ins[s[top--]] = 0;
  }
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scnt = top = cur = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) dfn[i] = low[i] = scc[i] = 0, g[i].clear();
    for (int i = 1; i <= m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
      if (!dfn[i]) tarjan(i);
    int c = 0;
    for (int i = 1; i <= n; ++i) c += scc[i] == 1;
    if (c == n) {
      puts("No");
      continue;
    }
    printf("Yes\n%lld %lld\n", c, n - c);
    for (int i = 1; i <= n; ++i)
      if (scc[i] == 1) printf("%lld ", i);
    puts("");
    for (int i = 1; i <= n; ++i)
      if (scc[i] != 1) printf("%lld ", i);
    puts("");
  }
}
