#include <bits/stdc++.h>
const int N = 100005;
int n, m, P, te, h[N], nxt[N << 1], to[N << 1], vis[N], tot, cnt, ans = 1;
void addedge(int u, int v) {
  nxt[++te] = h[u];
  h[u] = te;
  to[te] = v;
  nxt[++te] = h[v];
  h[v] = te;
  to[te] = u;
}
void dfs(int u) {
  vis[u] = 1;
  ++tot;
  for (int v, i = h[u]; i; i = nxt[i])
    if (!vis[v = to[i]]) dfs(v);
}
int main() {
  scanf("%d%d%d", &n, &m, &P);
  for (int u, v, i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    addedge(u, v);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) tot = 0, dfs(i), ans = 1ll * ans * tot % P, ++cnt;
  if (cnt == 1)
    ans = 1 % P;
  else
    for (int k = cnt - 2; k; --k) ans = 1ll * ans * n % P;
  printf("%d", ans);
  return 0;
}
