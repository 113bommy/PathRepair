#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
const ll inf = LLONG_MAX;
int n, q, a[N], b[N];
vector<int> G[N];
int in[N], out[N], num[N], id;
void dfs(int u, int fa) {
  in[u] = ++id;
  num[id] = u;
  for (auto v : G[u]) {
    if (v == fa) continue;
    a[v] += a[u];
    b[v] += b[u];
    dfs(v, u);
  }
  out[u] = id;
}
struct Line {
  ll k, b, x;
  ll eval() const { return k * x + b; }
  bool cmp(const Line& oth) const {
    ll x1 = eval(), x2 = oth.eval();
    if (x1 != x2) return x1 > x2;
    return k > oth.k;
  }
  ll isect(const Line& oth) {
    ll delta = eval() - oth.eval();
    ll secx = delta / (oth.k - k) + 1;
    return secx;
  }
};
struct seg {
  int l, r;
  Line L;
  ll wait, tag;
} t[N << 3];
void push(int p) {
  int l = t[p].l, r = t[p].r;
  if (l == r || t[p].wait > t[p].L.x) return;
  auto l1 = t[p << 1].L;
  auto l2 = t[p << 1 | 1].L;
  if (!l1.cmp(l2)) swap(l1, l2);
  t[p].L = l1;
  t[p].wait = min(t[p << 1].wait, t[p << 1 | 1].wait);
  if (l1.k < l2.k) t[p].wait = min(t[p].wait, l1.isect(l2));
}
void setv(int p, ll add) {
  t[p].L.x += add;
  t[p].tag += add;
  t[p].wait -= add;
}
void pushdown(int p) {
  setv(p << 1, t[p].tag), setv(p << 1 | 1, t[p].tag);
  t[p].tag = 0;
}
void build(int p, int l, int r) {
  t[p].l = l, t[p].r = r, t[p].wait = 0;
  if (l == r) {
    int x = num[(l + 1) / 2];
    if (l & 1)
      t[p].L = {b[x], 1ll * a[x] * b[x], 0};
    else
      t[p].L = {-b[x], -1ll * a[x] * b[x], 0};
    t[p].wait = inf;
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  push(p);
}
void upd(int p, int x, int y, ll add) {
  int l = t[p].l, r = t[p].r;
  if (l >= x && r <= y && t[p].wait >= add) {
    setv(p, add);
    return;
  }
  if (t[p].tag) pushdown(p);
  int mid = (l + r) >> 1;
  if (x <= mid) upd(p << 1, x, y, add);
  if (y > mid) upd(p << 1 | 1, x, y, add);
  t[p].wait = 0;
  push(p);
}
ll qry(int p, int x, int y) {
  int l = t[p].l, r = t[p].r;
  if (l >= x && r <= y) return t[p].L.eval();
  if (t[p].tag) pushdown(p);
  int mid = (l + r) >> 1;
  ll ans = 0;
  if (x <= mid) ans = max(ans, qry(p << 1, x, y));
  if (y > mid) ans = max(ans, qry(p << 1 | 1, x, y));
  return ans;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    int fa;
    scanf("%d", &fa);
    G[fa].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  dfs(1, 0);
  build(1, 1, 2 * n);
  while (q--) {
    int op, v;
    scanf("%d%d", &op, &v);
    if (op == 1) {
      ll x;
      scanf("%lld", &x);
      upd(1, in[v] * 2 - 1, out[v] * 2, x);
    } else
      printf("%lld\n", qry(1, in[v] * 2 - 1, out[v] * 2));
  }
  return 0;
}
