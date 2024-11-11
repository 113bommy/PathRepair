#include <bits/stdc++.h>
const int N = 5e4 + 5;
int n, q, a[N];
int fa[N], v[N], dep[N];
std ::vector<int> E[N];
int idx = 0, L[N], R[N];
void Dfs(int u) {
  L[u] = ++idx;
  v[idx] = a[u];
  dep[idx] = dep[L[fa[u]]] + 1;
  for (auto v : E[u]) Dfs(v);
  R[u] = idx;
}
int g[N];
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 2; i <= n; i++) scanf("%d", &fa[i]), E[fa[i]].push_back(i);
  Dfs(1);
  for (int t = 1; t <= q; t++) {
    int x;
    scanf("%d", &x);
    int ans = 0;
    int tot = 0;
    for (int i = L[x]; i <= R[x]; i++) {
      if (g[i] <= t) g[i] = t + v[i], ans += dep[i], tot++;
    }
    ans -= tot * dep[L[x]];
    printf("%d %d\n", ans, tot);
  }
  return 0;
}
