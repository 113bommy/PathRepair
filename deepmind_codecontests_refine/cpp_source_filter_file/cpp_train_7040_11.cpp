#include <bits/stdc++.h>
using namespace std;
long long const mod = 1e9 + 7, MAXN = 2e5 + 5, oo = 3e18;
long long tc, n, m;
long long a[MAXN];
double st[MAXN << 2], add[MAXN << 2], mul[MAXN << 2];
void build(long long node = 1, long long tl = 1, long long tr = n) {
  add[node] = 0;
  mul[node] = 1;
  if (tl == tr) {
    st[node] = a[tl];
    return;
  }
  long long tm = (tl + tr) >> 1;
  build(node << 1, tl, tm);
  build(node << 1 | 1, tm + 1, tr);
  st[node] = st[node << 1] + st[node << 1 | 1];
}
void apply(long long node, long long tl, long long tr) {
  long long len = (tr - tl + 1);
  long long lf = len - (len >> 1), rt = len >> 1;
  if (mul[node] != 1) {
    st[node << 1] *= mul[node];
    mul[node << 1] *= mul[node];
    add[node << 1] *= mul[node];
    st[node << 1 | 1] *= mul[node];
    mul[node << 1 | 1] *= mul[node];
    add[node << 1] *= mul[node];
    mul[node] = 1;
  }
  if (add[node] != 0) {
    st[node << 1] += lf * add[node];
    st[node << 1 | 1] += rt * add[node];
    add[node << 1] += add[node];
    add[node << 1 | 1] += add[node];
    add[node] = 0;
  }
  return;
}
void upd(long long opt, long long l, long long r, double val,
         long long node = 1, long long tl = 1, long long tr = n) {
  if (l > r || r < tl || l > tr) return;
  if (l <= tl && tr <= r) {
    if (opt == 1) {
      st[node] *= val;
      add[node] *= val;
      mul[node] *= val;
    } else {
      st[node] += val * (tr - tl + 1);
      add[node] += val;
    }
    return;
  }
  apply(node, tl, tr);
  long long tm = (tl + tr) >> 1;
  upd(opt, l, r, val, node << 1, tl, tm);
  upd(opt, l, r, val, node << 1 | 1, tm + 1, tr);
  st[node] = st[node << 1] + st[node << 1 | 1];
}
double query(long long l, long long r, long long node = 1, long long tl = 1,
             long long tr = n) {
  if (l > r || r < tl || l > tr) return 0.0;
  if (l <= tl && tr <= r) {
    return st[node];
  }
  apply(node, tl, tr);
  long long tm = (tl + tr) >> 1;
  return query(l, r, node << 1, tl, tm) +
         query(l, r, node << 1 | 1, tm + 1, tr);
}
void aurelion_sol() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  for (int i = 1; i <= m; i++) {
    long long opt;
    cin >> opt;
    if (opt == 2) {
      long long l, r;
      cin >> l >> r;
      cout << fixed << setprecision(9) << query(l, r) << endl;
    } else {
      long long l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      double sz1 = r1 - l1 + 1, sz2 = r2 - l2 + 1;
      double ev_1 = query(l1, r1), ev_2 = query(l2, r2);
      upd(1, l1, r1, (sz1 - 1) / sz1);
      upd(1, l2, r2, (sz2 - 1) / sz2);
      upd(2, l1, r1, (ev_2) / (sz1 * sz2));
      upd(2, l2, r2, (ev_1) / (sz1 * sz2));
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tc = 1;
  while (tc--) aurelion_sol();
}
