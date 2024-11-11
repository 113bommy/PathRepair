#include <bits/stdc++.h>
using namespace std;
struct segTree {
  int l, r;
  segTree *tl, *tr;
  int vv, lz, vx, vl, vr, vs;
  segTree(int l, int r) : l(l), r(r) {
    vv = lz = vx = vl = vr = vs = 0;
    if (l != r) {
      int mid = (l + r) / 2;
      tl = new segTree(l, mid);
      tr = new segTree(mid + 1, r);
    }
  }
  void upd(int v) { vv += v, lz += v; }
  void psh() { tl->upd(lz), tr->upd(lz), lz = 0; }
  void pul() {
    vv = min(tl->vv, tr->vv), vx = max(tl->vx, tr->vx);
    int x = tl->vv == vv, y = tr->vv == vv;
    vl = x ? tl->vl : max(tl->vx, tr->vl);
    vr = y ? tr->vr : max(tl->vr, tr->vx);
    vs = x * tl->vs + y * tr->vs + (x && y) * max(tl->vr, tr->vl);
  }
  void ad1(int x, int v) {
    if (x < l || r < x) return;
    if (l == r) return (void)(vx += v, vl += v, vr += v);
    psh();
    tl->ad1(x, v), tr->ad1(x, v);
    pul();
  }
  void ad2(int a, int b, int v) {
    if (b < l || r < a) return;
    if (a <= l && r <= b) return upd(v);
    psh();
    tl->ad2(a, b, v), tr->ad2(a, b, v);
    pul();
  }
  void dbg() {
    cout << l << " " << r << '\n';
    cout << vv << " " << lz << '\n';
    cout << vx << " " << vl << " " << vr << " " << vs << '\n';
    cout << '\n';
    if (l != r) psh(), tl->dbg(), tr->dbg();
  }
};
const int m = 400000;
int n, q;
int a[m];
set<int> second[m];
segTree tre(0, m);
void add(int x, int y) {
  if (!second[x].empty()) {
    tre.ad1(*second[x].begin(), y * second[x].size());
    tre.ad2(*second[x].begin(), *prev(second[x].end()), y);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int x = (i << 1) | 1;
    cin >> a[x];
    second[--a[x]].insert(x);
  }
  for (int i = 0; i < m; i++) add(i, 1);
  cout << (n - tre.vs) << '\n';
  while (q--) {
    int x, y;
    cin >> x >> y;
    x = ((--x) << 1) | 1, y--;
    if (a[x] != y) {
      add(a[x], -1), add(y, -1);
      second[a[x]].erase(x);
      swap(a[x], y);
      second[a[x]].insert(x);
      add(a[x], 1), add(y, 1);
    }
    cout << (n - tre.vs) << '\n';
  }
  return 0;
}
