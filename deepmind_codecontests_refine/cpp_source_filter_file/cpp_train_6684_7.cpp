#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int mxn = 200001, k = 100;
int n, q;
long long a[mxn], b[mxn], iv[k + 1];
struct segTree {
  int l, r;
  segTree *tl, *tr;
  long long vl, lv, rv, ls, rs;
  segTree(int l, int r) : l(l), r(r) {
    if (l != r) {
      int mid = (l + r) / 2;
      tl = new segTree(l, mid);
      tr = new segTree(mid + 1, r);
      pul();
    } else {
      vl = lv = rv = k * iv[a[l]] % mod, ls = rs = 0;
      if (b[l]) updl();
      if (b[r + 1]) updr();
    }
  }
  void updl() { lv = (ls ^= 1) ? 1 : vl; }
  void updr() { rv = (rs ^= 1) ? 0 : vl; }
  void pul() {
    vl = (tl->vl + tr->vl + tl->rv * (mod + tr->lv - 1)) % mod;
    lv = tl->lv * (tl->rs ? 1 : tr->lv) % mod;
    rv = (tr->lv * (tr->ls ? 0 : tl->rv) + tr->rv) % mod;
    ls = tl->ls + tr->ls, rs = tl->rs + tr->rs;
  }
  void add(int x, int y) {
    if (x < l || r < x) return;
    if (l == r) return (y ? updr() : updl());
    tl->add(x, y), tr->add(x, y);
    pul();
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  iv[0] = iv[1] = 1;
  for (int i = 2; i <= k; i++) iv[i] = mod - mod / i * iv[mod % i] % mod;
  b[0] = b[n] = 1;
  segTree tre(0, n - 1);
  while (q--) {
    int x;
    cin >> x;
    tre.add(--x, 0);
    tre.add(--x, 1);
    cout << tre.vl << '\n';
  }
  return 0;
}
