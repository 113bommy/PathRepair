#include <bits/stdc++.h>
using namespace std;
int n, a[200010];
vector<int> G[200010];
int fa[200010], deep[200010], top[200010], sze[200010], son[200010], p[200010],
    fp[200010], cnt;
void DFS(int u) {
  sze[u] = 1;
  for (auto v : G[u])
    if (v != fa[u]) {
      fa[v] = u;
      deep[v] = deep[u] + 1;
      DFS(v);
      sze[u] += sze[v];
      if (!son[u] || sze[v] > sze[son[u]]) son[u] = v;
    }
}
void gettop(int u, int sp) {
  top[u] = sp;
  p[u] = ++cnt;
  fp[cnt] = u;
  if (!son[u]) return;
  gettop(son[u], sp);
  for (auto v : G[u])
    if (v != fa[u] && v != son[u]) gettop(v, v);
}
namespace SEG {
long long lazy[200010 << 2], sum[200010 << 2];
void init() {
  memset(lazy, 0, sizeof lazy);
  memset(sum, 0, sizeof sum);
}
void pushdown(int id, int l, int mid, int r) {
  if (!lazy[id]) return;
  lazy[id << 1] += lazy[id];
  lazy[id << 1 | 1] += lazy[id];
  sum[id << 1] += lazy[id] * (mid - l + 1);
  sum[id << 1 | 1] += lazy[id] * (r - mid);
  lazy[id] = 0;
}
void pushup(int id) { sum[id] = sum[id << 1] + sum[id << 1 | 1]; }
void update(int id, int l, int r, int ql, int qr, long long val) {
  if (l >= ql && r <= qr) {
    lazy[id] += val;
    sum[id] += val * (r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  pushdown(id, l, mid, r);
  if (ql <= mid) update(id << 1, l, mid, ql, qr, val);
  if (qr > mid) update(id << 1 | 1, mid + 1, r, ql, qr, val);
  pushup(id);
}
long long query(int id, int l, int r, int ql, int qr) {
  if (l >= ql && r <= qr) return sum[id];
  int mid = (l + r) >> 1;
  pushdown(id, l, mid, r);
  long long res = 0;
  if (ql <= mid) res += query(id << 1, l, mid, ql, qr);
  if (qr > mid) res += query(id << 1 | 1, mid + 1, r, ql, qr);
  return res;
}
}  // namespace SEG
void update(int u, int v, long long val) {
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    SEG::update(1, 1, n, p[top[u]], p[u], val);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  SEG::update(1, 1, n, p[u], p[v], val);
}
long long query(int u, int v) {
  long long res = 0;
  while (top[u] != top[v]) {
    if (deep[top[u]] < deep[top[v]]) swap(u, v);
    res += SEG::query(1, 1, n, p[top[u]], p[u]);
    u = fa[top[u]];
  }
  if (deep[u] > deep[v]) swap(u, v);
  res += SEG::query(1, 1, n, p[u], p[v]);
  return res;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; ++i) G[i].clear();
    memset(son, 0, sizeof son);
    cnt = 0;
    SEG::init();
    for (int i = 1; i <= n; ++i) scanf("%d", a + i);
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
    deep[1] = 1;
    DFS(1);
    gettop(1, 1);
    long long base = 0;
    long long sum = 0;
    long long res = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    for (int i = 1; i <= n; ++i) base += 1ll * a[i] * deep[i];
    for (int i = 1; i <= n; ++i) update(1, i, -2ll * a[i]);
    for (int i = 1; i <= n; ++i) {
      long long tmp = query(1, i) + sum * deep[i] + base;
      res = max(res, tmp);
    }
    printf("%lld\n", res);
  }
  return 0;
}
