#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  bool f = true;
  long long x = 0;
  register char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = false;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  if (f) return x;
  return ~(--x);
}
inline void write(const long long &x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
inline void print(const long long &x) {
  x < 0 ? putchar('-'), write(~(x - 1)) : write(x);
  putchar('\n');
}
inline long long max(const long long &a, const long long &b) {
  return a > b ? a : b;
}
inline long long min(const long long &a, const long long &b) {
  return a < b ? a : b;
}
const int MAXN = 3e5 + 7;
int fa[MAXN];
int find(int k) { return k == fa[k] ? k : fa[k] = find(fa[k]); }
bool merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return 1;
  fa[v] = u;
  return 0;
}
vector<int> g[MAXN], W[MAXN];
int ans[MAXN * 2];
struct edge {
  int u, v, w, id;
} e[MAXN * 2];
int n, q, m;
namespace Tree {
int dfn[MAXN], fa[MAXN], top[MAXN], siz[MAXN], son[MAXN], dep[MAXN], val[MAXN],
    cnt;
struct BIT {
  int t[MAXN];
  void add(int k, int val) {
    for (; k < MAXN; k += k & (-k)) t[k] += val;
  }
  inline int ask(int k) {
    int ans = 0;
    for (; k; k -= k & (-k)) ans += t[k];
    return ans;
  }
  int query(int l, int r) { return ask(r) - ask(l - 1); }
  void modify(int l, int r) {
    for (register int i = l; i <= r; ++i) add(i, 1);
  }
} T;
void dfs1(int u, int F) {
  fa[u] = F;
  siz[u] = 1;
  for (register int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    if (v == F) continue;
    dep[v] = dep[u] + 1, val[v] = val[u] ^ W[u][i], dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int F, int topf) {
  top[u] = topf, dfn[u] = ++cnt;
  if (son[u]) dfs2(son[u], u, topf);
  for (auto v : g[u]) {
    if (v == F || v == son[u]) continue;
    dfs2(v, u, v);
  }
}
int LCA(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  return v;
}
int query(int u, int v) {
  int res = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    res += T.query(dfn[top[u]], dfn[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  res += T.query(dfn[v] + 1, dfn[u]);
  return res;
}
void modify(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) swap(u, v);
    T.modify(dfn[top[u]], dfn[u]);
    u = fa[top[u]];
  }
  if (dep[u] < dep[v]) swap(u, v);
  T.modify(dfn[v] + 1, dfn[u]);
}
}  // namespace Tree
int main() {
  n = read(), q = read();
  for (register int i = 1; i <= n; ++i) fa[i] = i;
  for (register int i = 1; i <= q; ++i) {
    int u = read(), v = read(), w = read();
    if (!merge(u, v)) {
      g[u].push_back(v), g[v].push_back(u);
      W[u].push_back(w), W[v].push_back(w);
      ans[i] = 1;
    } else
      e[++m] = (edge){u, v, w, i};
  }
  for (register int i = 1; i <= n; ++i) {
    if (!Tree::siz[i]) {
      Tree::dfs1(i, i);
      Tree::dfs2(i, i, i);
    }
  }
  for (register int i = 1; i <= m; ++i) {
    int u = e[i].u, v = e[i].v;
    if ((Tree::val[u] ^ Tree::val[v] ^ e[i].w) && !Tree::query(u, v)) {
      ans[e[i].id] = 1;
      Tree::modify(u, v);
    }
  }
  for (register int i = 1; i <= q; ++i) puts(ans[i] ? "YES" : "NO");
  return 0;
}
