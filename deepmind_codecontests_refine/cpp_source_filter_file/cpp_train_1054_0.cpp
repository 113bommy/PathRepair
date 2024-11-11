#include <bits/stdc++.h>
using namespace std;
const int N = 1048576;
long long t[N], m[N], d[N], res[N];
int n, q, par[N], a[N], v[N], h[N], h2[N], nex[N], nex2[N], u[N], l[N], r[N];
inline void up(int o) { t[o] = min(t[2 * o], t[2 * o + 1]) + m[o]; }
void build(int o, int l, int r) {
  if (l == r) {
    t[o] = d[l];
    return;
  }
  int mid = (l + r) / 2;
  build(2 * o, l, mid);
  build(2 * o + 1, mid + 1, r);
  up(o);
}
void upd(int o, int l, int r, int L, int R, int d) {
  if (L <= l && r <= R) {
    t[o] += d;
    m[o] += d;
    return;
  }
  int mid = (l + r) / 2;
  if (L <= mid) upd(2 * o, l, mid, L, R, d);
  if (R > mid) upd(2 * o + 1, mid + 1, r, L, R, d);
  up(o);
}
long long query(int o, int l, int r, int L, int R) {
  if (L <= l && r <= R) return t[o];
  int mid = (l + r) / 2;
  long long mn = 1ll << 60;
  if (L <= mid) mn = min(mn, query(2 * o, l, mid, L, R));
  if (R > mid) mn = min(mn, query(2 * o + 1, r, mid + 1, L, R));
  return mn + m[o];
}
void _upd(int x, int d) {
  upd(1, 1, n, 1, n, d);
  upd(1, 1, n, x, v[x], -2 * d);
}
void dfs(int x) {
  _upd(x, a[x]);
  for (int i = h2[x]; i; i = nex2[i]) res[i] = query(1, 1, n, l[i], r[i]);
  for (int i = h[x]; i; i = nex[i]) dfs(i);
  _upd(x, -a[x]);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    scanf("%d%d", &par[i], &a[i]);
    d[i] = d[par[i]] + a[i];
    nex[i] = h[par[i]];
    h[par[i]] = i;
  }
  for (int i = n; i; i--)
    if (h[i])
      v[i] = v[h[i]], d[i] = 1ll << 60;
    else
      v[i] = i;
  for (int i = 1; i <= q; i++)
    scanf("%d%d%d", &u[i], &l[i], &r[i]), nex2[i] = h2[u[i]], h2[u[i]] = i;
  build(1, 1, n);
  dfs(1);
  for (int i = 1; i <= q; i++) printf("%lld\n", res[i]);
  return 0;
}
