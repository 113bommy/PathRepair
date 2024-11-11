#include <bits/stdc++.h>
using namespace std;
int n, edgenum, vet[400005], Next[400005], head[200005], f[200005], fa[200005],
    dep[200005], q;
long long ans, siz[200005], w[200005], sz[200005];
void addedge(int u, int v) {
  vet[++edgenum] = v;
  Next[edgenum] = head[u];
  head[u] = edgenum;
}
long long sqr(long long x) { return x * x; }
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
void dfs(int u) {
  siz[u] = 1;
  dep[u] = dep[fa[u]] + 1;
  for (int e = head[u]; e; e = Next[e]) {
    int v = vet[e];
    if (v != fa[u]) {
      fa[v] = u;
      dfs(v);
      siz[u] += siz[v];
      w[u] += sqr((long long)siz[v]);
    }
  }
  w[u] += sqr((long long)n - siz[u]);
  ans -= w[u];
}
void merge(int x, int y) {
  ans -= (sqr((long long)n - sz[x]) - w[x]) * sz[x];
  ans -= (sqr((long long)n - sz[y]) - w[y]) * sz[y];
  ans -= 1ll * (n - sz[x]) * sz[x] * (sz[x] - 1) * 2;
  ans -= 1ll * (n - sz[y]) * sz[y] * (sz[y] - 1) * 2;
  ans -= 1ll * sz[x] * (sz[x] - 1) * (sz[x] - 2);
  ans -= 1ll * sz[y] * (sz[y] - 1) * (sz[y] - 2);
  f[y] = f[x];
  sz[x] += sz[y];
  w[x] += w[y] - sqr(siz[y]) - sqr(n - siz[y]);
  ans += (sqr((long long)n - sz[x]) - w[x]) * sz[x];
  ans += 1ll * (n - sz[x]) * sz[x] * (sz[x] - 1) * 2;
  ans += 1ll * sz[x] * (sz[x] - 1) * (sz[x] - 2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
  ans = n * (n - 1) * (n - 1);
  dfs(1);
  printf("%lld\n", ans);
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    u = find(u);
    v = find(v);
    while (u != v) {
      if (dep[u] < dep[v]) swap(u, v);
      int w = find(fa[u]);
      merge(w, u);
      u = w;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
