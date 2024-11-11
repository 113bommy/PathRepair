#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int id2[maxn];
struct seg_tree {
  long long sum[maxn << 2], add[maxn << 2];
  int ls(int x) { return x << 1; }
  int rs(int x) { return x << 1 | 1; }
  void push_up(int p) { sum[p] = sum[ls(p)] + sum[rs(p)]; }
  void build(int id, int l, int r) {
    add[id] = 0;
    if (l == r) {
      sum[id] = a[id2[l]];
      return;
    }
    int mid = (l + r) >> 1;
    build(ls(id), l, mid);
    build(rs(id), mid + 1, r);
    push_up(id);
  }
  void f(int id, int l, int r, long long k) {
    add[id] = add[id] + k;
    sum[id] = sum[id] + k * (r - l + 1);
  }
  void push_down(int id, int l, int r) {
    int mid = (l + r) >> 1;
    f(ls(id), l, mid, add[id]);
    f(rs(id), mid + 1, r, add[id]);
    add[id] = 0;
  }
  void iadd(int id, int l, int r, int x, int y, long long k) {
    if (x > y || x > r || y < l) return;
    if (x <= l && r <= y) {
      sum[id] += k * (r - l + 1);
      add[id] += k;
      return;
    }
    push_down(id, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) iadd(ls(id), l, mid, x, y, k);
    if (y > mid) iadd(rs(id), mid + 1, r, x, y, k);
    push_up(id);
  }
  long long iquery(int id, int l, int r, int x, int y) {
    if (x > y || x > r || y < l) return 0;
    long long ans = 0;
    if (x <= l && r <= y) return sum[id];
    int mid = (l + r) >> 1;
    push_down(id, l, r);
    if (x <= mid) ans += iquery(ls(id), l, mid, x, y);
    if (y > mid) ans += iquery(rs(id), mid + 1, r, x, y);
    return ans;
  }
  void upd(int id, int l, int r, int x, int w) {
    if (l == r) {
      sum[id] = w;
      return;
    }
    push_down(id, l, r);
    int mid = (l + r) / 2;
    if (x <= mid)
      upd(ls(id), l, mid, x, w);
    else
      upd(rs(id), mid + 1, r, x, w);
    push_up(id);
  }
} seg;
int n;
vector<int> g[maxn];
struct Tree_chain_subdivision {
  int cnt = 0;
  int w[maxn], wt[maxn], son[maxn], dfn[maxn], fa[maxn];
  int dep[maxn], siz[maxn], top[maxn];
  void init() {
    cnt = 0;
    dfs1(1, 1, 1);
    dfs2(1, 1);
    seg.build(1, 1, n);
  }
  void dfs1(int x, int f, int deep) {
    dep[x] = deep;
    fa[x] = f;
    siz[x] = 1;
    son[x] = 0;
    int maxson = -1;
    for (auto y : g[x]) {
      if (y == f) continue;
      dfs1(y, x, deep + 1);
      siz[x] += siz[y];
      if (siz[y] > maxson) son[x] = y, maxson = siz[y];
    }
  }
  void dfs2(int x, int topf) {
    dfn[x] = ++cnt;
    id2[cnt] = x;
    wt[cnt] = w[x];
    top[x] = topf;
    if (!son[x]) return;
    dfs2(son[x], topf);
    for (auto y : g[x]) {
      if (y == fa[x] || y == son[x]) continue;
      dfs2(y, y);
    }
  }
  int lca(int x, int y) {
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      x = fa[top[x]];
    }
    return dep[x] < dep[y] ? x : y;
  }
  void upd_range(int x, int y, int k) {
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      seg.iadd(1, 1, n, dfn[top[x]], dfn[x], k);
      x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    seg.iadd(1, 1, n, dfn[x], dfn[y], k);
  }
  void upd(int u) { seg.upd(1, 1, n, dfn[u], a[u]); }
  long long q_range(int x, int y) {
    long long ans = 0;
    while (top[x] != top[y]) {
      if (dep[top[x]] < dep[top[y]]) swap(x, y);
      ans += seg.iquery(1, 1, n, dfn[top[x]], dfn[x]);
      x = fa[top[x]];
    }
    if (dep[x] > dep[y]) swap(x, y);
    ans += seg.iquery(1, 1, n, dfn[x], dfn[y]);
    return ans;
  }
  void upd_son(int x, int k) {
    seg.iadd(1, 1, n, dfn[x], dfn[x] + siz[x] - 1, k);
  }
  int q_son(int x) { return seg.iquery(1, 1, n, dfn[x], dfn[x] + siz[x] - 1); }
} sp;
int main() {
  std::ios::sync_with_stdio(false), cin.tie(0);
  int q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] = abs(a[i]);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  sp.init();
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int u, c;
      cin >> u >> c;
      c = abs(c);
      a[u] = c;
      sp.upd(u);
    } else {
      int u, v;
      cin >> u >> v;
      cout << sp.q_range(u, v) * 2 - a[u] - a[v] << '\n';
    }
  }
  return 0;
}
