#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int next, to;
} edge[150005 * 2];
int fi[150005], se;
inline void add_edge(int u, int v) {
  edge[++se].next = fi[u], edge[se].to = v, fi[u] = se;
}
inline void add(int u, int v) { add_edge(u, v), add_edge(v, u); }
long long Pow(long long a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) (ans *= a) %= 998244353;
    (a *= a) %= 998244353, b >>= 1;
  }
  return ans;
}
int fa[150005], size[150005], son[150005], top[150005], p[150005], fp[150005],
    stree, n, invn;
void dfs1(int x) {
  size[x] = 1;
  for (int i = fi[x]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa[x]) continue;
    fa[v] = x, dfs1(v), size[x] += size[v];
    if (size[v] > size[son[x]]) son[x] = v;
  }
}
void dfs2(int x, int sp) {
  top[x] = sp, p[x] = ++stree, fp[stree] = x;
  if (!son[x]) return;
  dfs2(son[x], sp);
  for (int i = fi[x]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (v == fa[x] || v == son[x]) continue;
    dfs2(v, v);
  }
}
int sum[150005 * 4], a[150005], L, R, w;
void update(int x) { sum[x] = (sum[x << 1] + sum[x << 1 | 1]) % 998244353; }
void change(int l, int r, int x) {
  if (l == r) {
    (sum[x] += w) %= 998244353;
    return;
  }
  int mid = (l + r) >> 1;
  if (L <= mid)
    change(l, mid, x << 1);
  else
    change(mid + 1, r, x << 1 | 1);
  update(x);
}
void modify(int v, int d) {
  L = 1, w = 1ll * d * size[v] % 998244353 * invn % 998244353;
  change(1, n, 1);
  L = p[v], w = 1ll * d * (n - size[v]) % 998244353 * invn % 998244353;
  change(1, n, 1);
  (a[v] += d) %= 998244353;
  if (son[v]) {
    v = son[v],
    w = 1ll * d * (998244353 - size[v]) % 998244353 * invn % 998244353,
    L = p[v];
    change(1, n, 1);
  }
}
int Q(int l, int r, int x) {
  if (L <= l && R >= r) return sum[x];
  int mid = (l + r) >> 1, ans = 0;
  if (L <= mid) ans += Q(l, mid, x << 1);
  if (R > mid) (ans += Q(mid + 1, r, x << 1 | 1)) %= 998244353;
  return ans;
}
int query(int v) {
  int ans = 0;
  while (v) {
    if (v == top[v]) {
      L = R = p[v];
      (ans += Q(1, n, 1)) %= 998244353;
      (ans += 1ll * (998244353 - size[v]) * invn % 998244353 * a[fa[v]] %
              998244353) %= 998244353;
      v = fa[v];
    } else {
      L = p[top[v]], R = p[v];
      (ans += Q(1, n, 1)) %= 998244353;
      v = top[v];
      (ans += 1ll * (998244353 - size[v]) * invn % 998244353 * a[fa[v]] %
              998244353) %= 998244353;
      v = fa[v];
    }
  }
  return ans;
}
int main() {
  int q, u, v, op;
  scanf("%d%d", &n, &q);
  invn = Pow(n, 998244353 - 2);
  for (int i = 1; i < n; i++) scanf("%d%d", &u, &v), add(u, v);
  dfs1(1), dfs2(1, 1);
  for (int i = 0; i < q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &u, &v);
      modify(u, v);
    } else {
      scanf("%d", &u);
      printf("%d", query(u));
    }
  }
  return 0;
}
