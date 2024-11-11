#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5, M = 1e6 + 5, inf = 1e9;
long long n, m, fa[N], cnt, nxt[N << 1], to[N << 1], val[N << 1], head[N],
    dep[N], f[N][22], mx[N][22], ans[M], p, ip[N << 1], edge[N];
bool ok[M];
struct Edge {
  long long u, v, w, i;
} e[M], E[M];
long long read() {
  long long x = 0, f = 1;
  char s;
  while ((s = getchar()) > '9' || s < '0')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9')
    x = (x << 1) + (x << 3) + (s ^ 48), s = getchar();
  return x * f;
}
void addEdge(long long u, long long v, long long w, long long ID) {
  nxt[++cnt] = head[u], to[cnt] = v, head[u] = cnt, val[cnt] = w, ip[cnt] = ID;
}
void init() {
  for (long long i = 1; i <= n; ++i) fa[i] = i;
}
long long Find(long long x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void dfs(long long u, long long ba) {
  dep[u] = dep[ba] + 1;
  f[u][0] = ba;
  for (long long i = 1; i <= 20; ++i)
    f[u][i] = f[f[u][i - 1]][i - 1],
    mx[u][i] = max(mx[u][i - 1], mx[f[u][i - 1]][i - 1]);
  for (long long i = head[u]; i; i = nxt[i]) {
    long long v = to[i];
    if (v == ba) continue;
    mx[v][0] = val[i];
    edge[v] = ip[i];
    dfs(v, u);
  }
}
long long LCA(long long u, long long v) {
  if (dep[v] > dep[u]) swap(u, v);
  long long r = 0;
  for (long long i = 20; i >= 0; --i)
    if (dep[f[u][i]] >= dep[v]) {
      r = max(r, mx[u][i]);
      u = f[u][i];
    }
  if (u == v) return r;
  for (long long i = 20; i >= 0; --i)
    if (f[u][i] ^ f[v][i]) {
      r = max(r, max(mx[u][i], mx[v][i]));
      u = f[u][i];
      v = f[v][i];
    }
  return max(r, max(mx[u][0], mx[v][0]));
}
bool cmp(Edge a, Edge b) { return a.w < b.w; }
void Kruskal() {
  sort(e + 1, e + m + 1, cmp);
  init();
  for (long long i = 1; i <= m; ++i) {
    long long u = e[i].u, v = e[i].v;
    if (Find(u) ^ Find(v)) {
      fa[Find(u)] = Find(v);
      ok[e[i].i] = 1;
      addEdge(u, v, e[i].w, e[i].i), addEdge(v, u, e[i].w, e[i].i);
    }
  }
}
long long Lca(long long u, long long v) {
  if (dep[v] > dep[u]) swap(u, v);
  for (long long i = 20; i >= 0; --i)
    if (dep[f[u][i]] >= dep[v]) u = f[u][i];
  if (u == v) return u;
  for (long long i = 20; i >= 0; --i)
    if (f[u][i] ^ f[v][i]) u = f[u][i], v = f[v][i];
  return f[u][0];
}
void jump(long long u, long long v, long long w) {
  if (dep[u] < dep[v]) swap(u, v);
  long long lca = Lca(u, v);
  if (Find(u) ^ u) u = Find(u);
  if (Find(v) ^ v) v = Find(v);
  while (dep[u] > dep[lca]) {
    ans[edge[u]] = w;
    fa[u] = Find(f[u][0]);
    u = Find(f[u][0]);
  }
  while (dep[v] > dep[lca]) {
    ans[edge[v]] = w;
    fa[v] = Find(f[v][0]);
    v = Find(f[v][0]);
  }
}
signed main() {
  long long u, v, w;
  memset(ans, -1, sizeof ans);
  n = read(), m = read();
  for (long long i = 1; i <= m; ++i) {
    u = read(), v = read(), w = read();
    e[i] = (Edge){u, v, w, i};
  }
  Kruskal();
  init();
  dfs(1, 0);
  for (long long i = 1; i <= m; ++i) {
    if (ok[e[i].i]) continue;
    ans[e[i].i] = LCA(e[i].u, e[i].v);
    E[++p] = e[i];
  }
  for (long long i = 1; i <= p; ++i) jump(E[i].u, E[i].v, E[i].w);
  for (long long i = 1; i <= m; ++i)
    printf("%d\n", ans[i] == -1 ? inf : ans[i]);
  return 0;
}
