#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct Q {
  int l, r, t, b;
  void read() { scanf("%d%d%d%d", &l, &b, &r, &t); }
} q[N];
struct R {
  int x, y;
  void read() { scanf("%d%d", &x, &y); }
} r[N];
int n, m, kn, qn;
vector<int> vq[N], vr[N];
struct Tree {
  static const int N = ::N << 2;
  int val[N], n;
  int ls(int o) { return o << 1; }
  int rs(int o) { return o << 1 | 1; }
  void init(int _n) {
    n = _n;
    fill_n(val, N, 0);
  }
  void _change(int o, int l, int r, int qx, int qv) {
    if (l == r) {
      val[o] = qv;
      return;
    }
    int mid = l + r >> 1;
    if (qx <= mid)
      _change(ls(o), l, mid, qx, qv);
    else
      _change(rs(o), mid + 1, r, qx, qv);
    val[o] = min(val[ls(o)], val[rs(o)]);
  }
  void change(int qx, int qv) { _change(1, 1, n, qx, qv); }
  int _query(int o, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return val[o];
    int mid = l + r >> 1, ret = 0x3f3f3f3f;
    if (ql <= mid) ret = min(_query(ls(o), l, mid, ql, qr), ret);
    if (qr > mid) ret = min(_query(rs(o), mid + 1, r, ql, qr), ret);
    return ret;
  }
  int query(int ql, int qr) { return _query(1, 1, n, ql, qr); }
} tree;
int ans[N];
void solve() {
  for (int i = (1); i < (n + 1); ++i) vq[i].clear(), vr[i].clear();
  for (int i = (1); i < (kn + 1); ++i) vr[r[i].x].push_back(i);
  for (int i = (1); i < (qn + 1); ++i) vq[q[i].r].push_back(i);
  tree.init(m);
  for (int i = (1); i < (n + 1); ++i) {
    for (auto rid : vr[i]) tree.change(r[rid].y, i);
    for (auto qid : vq[i]) {
      ans[qid] &= tree.query(q[qid].b, q[qid].t) < q[qid].l;
    }
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &kn, &qn);
  for (int i = (1); i < (kn + 1); ++i) r[i].read();
  for (int i = (1); i < (qn + 1); ++i) q[i].read();
  for (int i = (1); i < (qn + 1); ++i) ans[i] = true;
  solve();
  swap(n, m);
  for (int i = (1); i < (kn + 1); ++i) swap(r[i].x, r[i].y);
  for (int i = (1); i < (qn + 1); ++i)
    swap(q[i].b, q[i].l), swap(q[i].t, q[i].r);
  solve();
  for (int i = (1); i < (qn + 1); ++i) puts(!ans[i] ? "YES" : "NO");
  return 0;
}
