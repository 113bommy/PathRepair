#include <bits/stdc++.h>
using namespace std;
int read() {
  int v = 0, f = 1;
  char c = getchar();
  while (c < 48 || 57 < c) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (48 <= c && c <= 57) v = (v << 3) + v + v + c - 48, c = getchar();
  return v * f;
}
const int N = 201000;
struct Edge {
  int nxt, to;
} eg[N];
int head[N], en;
void setEdge(int u, int v) {
  eg[++en] = (Edge){head[u], v};
  head[u] = en;
}
long long a[N], b[N], f[N];
int dep[N], son[N], top[N], fa[N], n, m, st[N], ed[N], siz[N];
vector<pair<int, int> > V[N];
vector<pair<pair<int, int>, int> > W[N];
void dfs1(int u) {
  siz[u] = 1;
  for (int e = head[u]; e; e = eg[e].nxt) {
    int v = eg[e].to;
    fa[v] = u;
    dep[v] = dep[u] + 1;
    dfs1(v);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int anc) {
  static int dfsClock;
  st[u] = ++dfsClock;
  top[u] = anc;
  if (son[u]) dfs2(son[u], anc);
  for (int e = head[u]; e; e = eg[e].nxt) {
    int v = eg[e].to;
    if (v == son[u]) continue;
    dfs2(v, v);
  }
  ed[u] = dfsClock;
}
void add(int u, long long v) {
  for (int i = u; i <= n; i += i & -i) a[i] += v;
}
long long ask(int u) {
  long long re = 0;
  for (int i = u; i; i -= i & -i) re += a[i];
  return re;
}
long long query(int u, int v) {
  long long re = b[v] - (ask(st[v]) - ask(st[v] - 1));
  int t1 = u, t2 = v;
  while (top[v] != top[u]) {
    re += ask(st[v]) - ask(st[top[v]] - 1);
    re -= f[top[v]];
    v = fa[top[v]];
    re += f[son[v]];
  }
  re += ask(st[v]) - ask(st[u] - 1);
  return re;
}
void dfs3(int u) {
  for (int e = head[u]; e; e = eg[e].nxt) {
    int v = eg[e].to;
    dfs3(v);
    b[u] += f[v];
    if (v != son[u]) add(st[u], f[v]);
    f[u] += f[v];
  }
  for (vector<pair<int, int> >::iterator j = V[u].begin(); j != V[u].end();
       j++) {
    int v = (*j).first, w = (*j).second;
    f[u] = max(f[u], query(u, v) + w);
  }
  for (vector<pair<pair<int, int>, int> >::iterator j = W[u].begin();
       j != W[u].end(); j++) {
    int x = (*j).first.first, y = (*j).first.second, w = (*j).second;
    f[u] = max(f[u], query(u, x) + query(u, y) - b[u] + w);
  }
}
int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]]) swap(u, v);
    v = fa[top[v]];
  }
  return dep[u] < dep[v] ? u : v;
}
int main() {
  n = read(), m = read();
  for (int i = 2; i <= n; i++) setEdge(read(), i);
  dfs1(1);
  dfs2(1, 1);
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), w = read();
    int l = lca(u, v);
    if (u == l)
      V[u].push_back(make_pair(v, w));
    else if (v == l)
      V[v].push_back(make_pair(u, w));
    else
      W[l].push_back(make_pair(make_pair(u, v), w));
  }
  dfs3(1);
  printf("%lld\n", f[1]);
}
