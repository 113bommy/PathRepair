#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, E = 2e6 + 5;
int n, k;
int oo = 1e9 + 7;
int f[N][30];
int v[E], lz[E], p[E][2], all = 1;
void prep() {
  for (int j = 1; j <= log2(n) + 1; ++j)
    for (int i = 1; i - 1 + (1 << j) <= n; ++i)
      f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
int ngu(int l, int r) {
  int res = oo;
  for (int i = log2(n) + 1; i >= 0; --i) {
    if (l - 1 + (1 << i) > r) continue;
    res = min(res, f[l][i]);
    l += 1 << i;
  }
  return res;
}
int cal(int l, int r) {
  if (r - l + 1 >= n) return ngu(1, n);
  l %= n;
  l += n * !l;
  r %= n;
  r += n * !r;
  if (l <= r)
    return ngu(l, r);
  else
    return min(ngu(l, n), ngu(1, r));
}
void down(int id, int l, int r) {
  if (!lz[id]) return;
  v[id] = lz[id];
  if (l < r) {
    if (!p[id][0]) p[id][0] = ++all;
    if (!p[id][1]) p[id][1] = ++all;
    lz[p[id][0]] = lz[id];
    lz[p[id][1]] = lz[id];
  }
  lz[id] = 0;
}
void upd(int id, int l, int r, int L, int R, int val) {
  down(id, l, r);
  if (l > R || r < L) return;
  if (L <= l && r <= R) {
    lz[id] = val;
    down(id, l, r);
    return;
  }
  int mid = l + r >> 1, a, b;
  if (!p[id][0] && L <= mid) p[id][0] = ++all;
  if (p[id][0])
    upd(p[id][0], l, mid, L, R, val), a = v[p[id][0]];
  else
    a = cal(l, mid);
  if (!p[id][1] && R > mid) p[id][1] = ++all;
  if (p[id][1])
    upd(p[id][1], mid + 1, r, L, R, val), b = v[p[id][1]];
  else
    b = cal(mid + 1, r);
  v[id] = min(a, b);
}
int sch(int id, int l, int r, int L, int R) {
  down(id, l, r);
  if (l > R || r < L) return oo;
  int s = max(l, L), e = min(r, R);
  if (!v[id]) return cal(s, e);
  if (L <= l && r <= R) return v[id];
  int mid = l + r >> 1, a, b;
  if (!p[id][0] && L <= mid)
    a = cal(L, min(mid, R));
  else if (p[id][0])
    a = sch(p[id][0], l, mid, L, R);
  else
    a = oo;
  if (!p[id][1] && R > mid)
    b = cal(max(L, mid + 1), R);
  else if (p[id][1])
    b = sch(p[id][1], mid + 1, r, L, R);
  else
    b = oo;
  return min(a, b);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> f[i][0];
  prep();
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int r;
    cin >> r;
    if (r == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      upd(1, 1, k * n, l, r, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << sch(1, 1, k * n, l, r) << '\n';
    }
  }
  return 0;
}
