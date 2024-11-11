#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 2e6 + 7;
struct graph {
  int cnt, v[M], nxt[M], w[M], hd[N];
  void add(int x, int y, int z) {
    v[++cnt] = y;
    w[cnt] = z;
    nxt[cnt] = hd[x];
    hd[x] = cnt;
  }
} G, H;
int n, m, q, a[M][2], dep[N], lca[N], p0[N], p1[N], fa[N], tot[N];
bool o[N];
int find(int* f, int x) { return (f[x] == x) ? x : f[x] = find(f, f[x]); }
void dfs(int u) {
  for (int i = G.hd[u]; i; i = G.nxt[i])
    if (!dep[G.v[i]]) {
      fa[G.v[i]] = u;
      dep[G.v[i]] = dep[u] + 1;
      dfs(G.v[i]);
      p1[G.v[i]] = u;
      if (find(p0, u) == find(p0, G.v[i])) o[u] |= o[G.v[i]];
    } else if (dep[G.v[i]] + 1 < dep[u]) {
      int z = find(p0, u);
      while (dep[z] > dep[u] + 1) p0[z] = fa[z], z = find(p0, z);
      if ((dep[u] - dep[G.v[i]]) % 2 == 0) o[u] = 1;
    }
  for (int i = H.hd[u]; i; i = H.nxt[i]) lca[H.w[i]] = find(p1, H.v[i]);
}
void work(int u) {
  if (o[find(p0, u)]) tot[u]++;
  for (int i = G.hd[u]; i; i = G.nxt[i])
    if (dep[G.v[i]] == dep[u] + 1) {
      if (find(p0, u) == find(p0, G.v[i])) o[G.v[i]] |= o[u];
      tot[G.v[i]] = tot[u];
      work(G.v[i]);
    }
}
bool check(int x, int y, int w) {
  if (find(p1, x) != find(p1, y)) return 0;
  if ((dep[x] - dep[y]) % 2) return 1;
  return tot[x] + tot[y] - tot[w] * 2 > 0;
}
int main() {
  scanf("%d%d", &n, &m);
  int x, y;
  for (int i = 1; i <= m; i++)
    scanf("%d%d", &x, &y), G.add(x, y, i), G.add(y, x, i);
  scanf("%d", &q);
  for (int i = 1; i <= q; i++)
    scanf("%d%d", &a[i][0], &a[i][1]), H.add(a[i][0], a[i][1], i),
        H.add(a[i][1], a[i][0], i);
  for (int i = 1; i <= n; i++) p0[i] = p1[i] = i;
  for (int i = 1; i <= n; i++)
    if (!dep[i]) dep[i] = 1, dfs(i), work(i);
  for (int i = 1; i <= q; i++)
    if (check(a[i][0], a[i][1], lca[i]))
      puts("Yes");
    else
      puts("No");
}
