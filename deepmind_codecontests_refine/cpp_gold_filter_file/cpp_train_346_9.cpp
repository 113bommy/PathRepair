#include <bits/stdc++.h>
using namespace std;
template <class T>
void PA(T x[], int n) {
  for (int i = 0; i < n; ++i) cout << x[i] << " ";
  cout << endl;
}
const int N = 100000;
int z[5][20];
int a[N];
int len[5];
struct Seg {
  int l, r, lc, rc;
  long long s[5][10];
} seg[N * 2];
int segn;
void update(Seg &ns, Seg &ls, Seg &rs) {
  for (int n_ = (5), z = 0; z < n_; ++z)
    for (int n_ = (len[z]), o = 0; o < n_; ++o) {
      ns.s[z][o] = ls.s[z][o] + rs.s[z][o];
    }
}
int seg_init(int l, int r) {
  int p = segn++;
  Seg &ns = seg[p];
  ns.l = l, ns.r = r;
  if (l == r) {
    for (int n_ = (5), zz = 0; zz < n_; ++zz)
      for (int n_ = (len[zz]), o = 0; o < n_; ++o)
        ns.s[zz][o] = (long long)z[zz][(l + o) % len[zz]] * a[l];
    return p;
  }
  int mid = (l + r) / 2;
  ns.lc = seg_init(l, mid);
  ns.rc = seg_init(mid + 1, r);
  update(ns, seg[ns.lc], seg[ns.rc]);
  return p;
}
void seg_ins(int p, int x, int v) {
  Seg &ns = seg[p];
  if (ns.l == ns.r) {
    for (int n_ = (5), zz = 0; zz < n_; ++zz)
      for (int n_ = (len[zz]), o = 0; o < n_; ++o)
        ns.s[zz][o] = (long long)z[zz][(ns.l + o) % len[zz]] * v;
    return;
  }
  int mid = (ns.l + ns.r) / 2;
  if (x <= mid)
    seg_ins(ns.lc, x, v);
  else
    seg_ins(ns.rc, x, v);
  update(ns, seg[ns.lc], seg[ns.rc]);
}
long long seg_find(int p, int l, int r, int zz, int o) {
  Seg &ns = seg[p];
  if (l <= ns.l && ns.r <= r) {
    return ns.s[zz][o];
  }
  int mid = (ns.l + ns.r) / 2;
  long long ret = 0;
  if (l <= mid) ret += seg_find(ns.lc, l, r, zz, o);
  if (r > mid) ret += seg_find(ns.rc, l, r, zz, o);
  return ret;
}
int main(int argc, char *argv[]) {
  for (int n_ = (5), dz = 0; dz < n_; ++dz)
    for (int n_ = (20), di = 0; di < n_; ++di) {
      int zz = dz + 2;
      int i = di + 1;
      int &ret = z[dz][di];
      if (i % (2 * (zz - 1)) == 0)
        ret = 2;
      else if (i % (int)(2 * (zz - 1)) <= zz)
        ret = i % (2 * (zz - 1));
      else
        ret = 2 * zz - i % (2 * (zz - 1));
    }
  for (int n_ = (5), zz = 0; zz < n_; ++zz) len[zz] = (zz + 1) * 2;
  int n;
  cin >> n;
  for (int n_ = (n), i = 0; i < n_; ++i) cin >> a[i];
  seg_init(0, n - 1);
  int m;
  cin >> m;
  while (m--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      p--;
      seg_ins(0, p, v);
    } else {
      int l, r, z;
      cin >> l >> r >> z;
      l--, r--, z -= 2;
      long long ret = seg_find(0, l, r, z, (len[z] - l % len[z]) % len[z]);
      cout << ret << endl;
    }
  }
  return 0;
}
