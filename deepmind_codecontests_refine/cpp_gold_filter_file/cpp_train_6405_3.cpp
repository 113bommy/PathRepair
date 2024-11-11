#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, m, q, R, gbel[MAXN], p[MAXN << 2], tot;
inline void trans(int &x) {
  x = (x + R) % n;
  if (x == 0) x = n;
  x = gbel[x];
}
namespace graph {
vector<int> g[MAXN];
int dfn[MAXN], low[MAXN], tim;
int stk[MAXN], top, ebc, bel[MAXN];
inline void addedge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}
void Tarjan(int u, int fa) {
  dfn[u] = low[u] = ++tim;
  stk[++top] = u;
  bool ff = 0;
  for (auto v : g[u]) {
    if (v == fa && !ff) {
      ff = 1;
      continue;
    }
    if (!dfn[v]) {
      Tarjan(v, u);
      low[u] = min(low[u], low[v]);
    } else {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (low[u] == dfn[u]) {
    ++ebc;
    do {
      bel[stk[top]] = ebc;
    } while (stk[top--] != u);
  }
}
void work() {
  for (int i = 1; i <= tot; ++i) {
    if (!dfn[p[i]]) {
      Tarjan(p[i], 0);
    }
  }
}
void clean() {
  tim = top = ebc = 0;
  for (int i = 1; i <= tot; ++i) {
    g[p[i]].clear();
    dfn[p[i]] = low[p[i]] = 0;
  }
}
}  // namespace graph
namespace tree {
vector<int> e[MAXN];
int tr[MAXN], fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN];
int dfn[MAXN], clk, vir[MAXN], stk[MAXN], tp;
inline bool dfn_cmp(int x, int y) { return (dfn[x] < dfn[y]); }
void DFS1(int u) {
  siz[u] = 1;
  for (auto v : e[u]) {
    if (v == fa[u]) continue;
    tr[v] = tr[u];
    fa[v] = u;
    dep[v] = dep[u] + 1;
    DFS1(v);
    if (siz[v] > siz[son[u]]) son[u] = v;
    siz[u] += siz[v];
  }
}
void DFS2(int u, int topf) {
  top[u] = topf;
  dfn[u] = ++clk;
  if (son[u]) DFS2(son[u], topf);
  for (auto v : e[u]) {
    if (v == fa[u] || v == son[u]) continue;
    DFS2(v, v);
  }
}
inline int LCA(int u, int v) {
  while (top[u] ^ top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  return (dep[u] < dep[v]) ? u : v;
}
void vtree(int l, int r) {
  stk[tp = 1] = p[l];
  for (int i = l + 1; i <= r; ++i) {
    int lca = LCA(stk[tp], p[i]);
    while (tp && dep[stk[tp]] > dep[lca]) {
      if (dep[stk[tp - 1]] <= dep[lca]) {
        graph::addedge(lca, stk[tp--]);
        if (lca ^ stk[tp]) {
          stk[++tp] = lca;
          p[++tot] = lca;
        }
        break;
      }
      --tp;
      graph::addedge(stk[tp], stk[tp + 1]);
    }
    stk[++tp] = p[i];
  }
  while (--tp) {
    graph::addedge(stk[tp], stk[tp + 1]);
  }
}
void build() {
  for (int u = 1; u <= n; ++u) {
    for (auto v : graph::g[u]) {
      if (gbel[u] ^ gbel[v]) {
        e[gbel[u]].push_back(gbel[v]);
      }
    }
  }
  for (int i = 1; i <= graph::ebc; ++i) {
    if (!tr[i]) {
      tr[i] = i;
      DFS1(i);
      DFS2(i, i);
    }
  }
}
bool work() {
  int nn, mm;
  read(nn);
  read(mm);
  tot = 0;
  for (int i = 1; i <= nn; ++i) {
    read(vir[i]);
    trans(vir[i]);
    p[++tot] = vir[i];
  }
  for (int i = 1, u, v; i <= mm; ++i) {
    read(u);
    trans(u);
    read(v);
    trans(v);
    if (u == v) continue;
    graph::addedge(u, v);
    p[++tot] = u;
    p[++tot] = v;
  }
  sort(p + 1, p + tot + 1);
  tot = unique(p + 1, p + tot + 1) - (p + 1);
  sort(p + 1, p + tot + 1, dfn_cmp);
  for (int i = 1, j, t = tot; i <= t; i = j) {
    for (j = i; j <= t && tr[p[j]] == tr[p[i]]; ++j)
      ;
    vtree(i, j - 1);
  }
  graph::work();
  graph::clean();
  int now = graph::bel[vir[1]];
  for (int i = 2; i <= nn; ++i) {
    if (graph::bel[vir[i]] != now) return 0;
  }
  return 1;
}
}  // namespace tree
void init() {
  read(n);
  read(m);
  read(q);
  for (int i = 1, u, v; i <= m; ++i) {
    read(u);
    read(v);
    graph::addedge(u, v);
  }
  iota(p + 1, p + n + 1, 1);
  tot = n;
  graph::work();
  for (int i = 1; i <= n; ++i) {
    gbel[i] = graph::bel[i];
  }
  tree::build();
  graph::clean();
}
void solve() {
  for (int i = 1; i <= q; ++i) {
    int ans = tree::work();
    puts(ans ? "YES" : "NO");
    if (ans) R = (R + i) % n;
  }
}
int main() {
  init();
  solve();
  return 0;
}
