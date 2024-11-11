#include <bits/stdc++.h>
const int N = 3e5 + 5;
const int Q = 5e5 + 5;
int n, q;
struct edge {
  int u, v, w;
} e[Q];
bool ans[Q];
std::vector<std::pair<int, int>> adj[N];
int uset[N];
int find(int x) { return x == uset[x] ? x : uset[x] = find(uset[x]); }
int fa[N], dep[N];
int siz[N], wson[N], wtop[N];
int dfn[N], val[N], timer = 0;
void dfs1(int x, int f) {
  fa[x] = f, dep[x] = dep[f] + 1, siz[x] = 1;
  for (auto e : adj[x])
    if (e.first != f) {
      int y = e.first, v = e.second;
      val[y] = val[x] ^ v;
      dfs1(y, x), siz[x] += siz[y];
      if (siz[y] > siz[wson[x]]) wson[x] = y;
    }
}
void dfs2(int x, int t) {
  wtop[x] = t, dfn[x] = ++timer;
  if (wson[x]) dfs2(wson[x], t);
  for (auto e : adj[x])
    if (e.first != fa[x] && e.first != wson[x]) dfs2(e.first, e.first);
}
int sum[N << 2], add[N << 2];
inline void pushup(int x) { sum[x] = sum[x << 1] + sum[x << 1 | 1]; }
inline void set_add(int x, int l, int r, int v) {
  sum[x] += (r - l + 1) * v;
  add[x] += v;
}
inline void pushdown(int x, int l, int r) {
  if (add[x]) {
    set_add(x << 1, l, ((l + r) >> 1), add[x]);
    set_add(x << 1 | 1, ((l + r) >> 1) + 1, r, add[x]);
    add[x] = 0;
  }
}
void update(int x, int l, int r, int ql, int qr, int v) {
  if (ql <= l && r <= qr) return set_add(x, l, r, v);
  if (ql > r || l > qr) return;
  pushdown(x, l, r);
  update(x << 1, l, ((l + r) >> 1), ql, qr, v);
  update(x << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr, v);
  pushup(x);
}
int get_sum(int x, int l, int r, int ql, int qr) {
  if (ql <= l && r <= qr) return sum[x];
  if (ql > r || l > qr) return 0;
  pushdown(x, l, r);
  return get_sum(x << 1, l, ((l + r) >> 1), ql, qr) +
         get_sum(x << 1 | 1, ((l + r) >> 1) + 1, r, ql, qr);
}
inline int get_sum(int x, int y) {
  int ans = 0;
  while (wtop[x] != wtop[y]) {
    if (dep[wtop[x]] < dep[wtop[y]]) std::swap(x, y);
    ans += get_sum(1, 1, n, dfn[wtop[x]], dfn[x]);
    x = fa[wtop[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  if (x != y) ans += get_sum(1, 1, n, dfn[x] + 1, dfn[y]);
  return ans;
}
inline void update(int x, int y) {
  while (wtop[x] != wtop[y]) {
    if (dep[wtop[x]] < dep[wtop[y]]) std::swap(x, y);
    update(1, 1, n, dfn[wtop[x]], dfn[x], 1);
    x = fa[wtop[x]];
  }
  if (dep[x] > dep[y]) std::swap(x, y);
  if (x != y) update(1, 1, n, dfn[x] + 1, dfn[y] - 1, 1);
}
signed main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) uset[i] = i;
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    if (find(e[i].u) != find(e[i].v)) {
      uset[find(e[i].u)] = find(e[i].v);
      adj[e[i].u].emplace_back(e[i].v, e[i].w);
      adj[e[i].v].emplace_back(e[i].u, e[i].w);
      ans[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dfn[i]) continue;
    dfs1(i, 0);
    dfs2(i, i);
  }
  for (int i = 1; i <= q; i++)
    if (!ans[i]) {
      int u = e[i].u, v = e[i].v;
      if ((val[u] ^ val[v] ^ e[i].w) && !get_sum(u, v))
        update(u, v), ans[i] = 1;
    }
  for (int i = 1; i <= q; i++)
    if (ans[i])
      puts("YES");
    else
      puts("NO");
  return 0;
}
