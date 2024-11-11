#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + (ch ^ 48);
    ch = getchar();
  }
  return x *= f, void();
}
template <typename T>
void ckmax(T &a, T b) {
  a = b > a ? b : a;
}
template <typename T>
void ckmin(T &a, T b) {
  a = b < a ? b : a;
}
const int N = 5e5 + 5;
int n, m, q, tot, U[N], V[N], del[N], fa[N], p[N], op[N], x[N], dfn[N], cnt,
    siz[N];
vector<int> g[N];
pair<int, int> w[N << 2];
inline void pushup(int p) { w[p] = max(w[p << 1], w[p << 1 | 1]); }
void modify(int p, int l, int r, int x, int val) {
  if (l == r) return w[p] = make_pair(val, l), void();
  if (x <= ((l + r) >> 1))
    modify(p << 1, l, ((l + r) >> 1), x, val);
  else
    modify(p << 1 | 1, ((l + r) >> 1) + 1, r, x, val);
  pushup(p);
}
pair<int, int> query(int p, int l, int r, int x, int y) {
  if (y == 0) return make_pair(0, 0);
  if (x <= l && r <= y) return w[p];
  pair<int, int> res(0, 0);
  if (x <= ((l + r) >> 1))
    res = max(res, query(p << 1, l, ((l + r) >> 1), x, y));
  if (y > ((l + r) >> 1))
    res = max(res, query(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y));
  return res;
}
int find(int u) {
  if (fa[u] == u) return u;
  return fa[u] = find(fa[u]);
}
inline void merge(int u, int v) {
  u = find(u), v = find(v);
  if (u == v) return;
  fa[u] = fa[v] = ++tot;
  fa[tot] = tot;
  g[tot].push_back(u);
  g[tot].push_back(v);
}
void dfs(int u) {
  dfn[u] = ++cnt, siz[u] = 1;
  if (u <= n) modify(1, 1, tot, dfn[u], p[u]);
  for (auto v : g[u]) {
    if (dfn[v]) continue;
    dfs(v), siz[u] += siz[v];
  }
}
int main() {
  read(n), read(m), read(q), tot = n;
  for (int i = 1; i <= n; i++) read(p[i]);
  for (int i = 1; i <= m; i++) read(U[i]), read(V[i]);
  for (int i = 1; i <= q; i++) {
    read(op[i]), read(x[i]);
    if (op[i] == 2) del[x[i]] = 1;
  }
  for (int i = 1; i <= n; i++) fa[i] = i;
  for (int i = 1; i <= m; i++) {
    if (!del[i]) merge(U[i], V[i]);
  }
  for (int i = q; i >= 1; i--) {
    if (op[i] == 2) {
      merge(U[x[i]], V[x[i]]);
    } else {
      x[i] = find(x[i]);
    }
  }
  for (int i = 1; i < tot; i++) {
    if (fa[i] == i) {
      g[tot].push_back(i);
    }
  }
  dfs(tot);
  for (int i = 1; i <= q; i++) {
    if (op[i] == 1) {
      pair<int, int> ans;
      ans = query(1, 1, tot, dfn[x[i]], dfn[x[i]] + siz[x[i]] - 1);
      printf("%d\n", ans.first);
      modify(1, 1, tot, ans.second, 0);
    }
  }
  return 0;
}
