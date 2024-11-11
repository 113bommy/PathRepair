#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int INF = 1e9;
int n, t, f[N];
vector<int> V;
struct Panel {
  int h, l, r;
  void in() { scanf("%d%d%d", &h, &l, &r); }
  void out() { printf("%d %d %d\n", h, l, r); }
  bool operator<(const Panel &p) const { return h > p.h; }
} p[N];
struct Node {
  int lc, len, tot;
  Node() {}
  Node(int _c, int _l, int _t) { lc = _c, len = _l, tot = _t; }
};
struct SegTree {
  int cov[N << 3];
  Node a[N << 3];
  void merge(Node &t, const Node &x, const Node &y) {
    t.len = (x.len == x.tot && x.lc == y.lc) ? x.len + y.len : x.len;
    t.lc = x.lc, t.tot = x.tot + y.tot;
  }
  void up(int t) { merge(a[t], a[((t) << 1)], a[((t) << 1 | 1)]); }
  void down(int t) {
    if (~cov[t]) {
      cov[((t) << 1)] = cov[t], a[((t) << 1)].lc = cov[t],
                  a[((t) << 1)].len = a[((t) << 1)].tot;
      cov[((t) << 1 | 1)] = cov[t], a[((t) << 1 | 1)].lc = cov[t],
                      a[((t) << 1 | 1)].len = a[((t) << 1 | 1)].tot;
      cov[t] = -1;
    }
  }
  void build(int t, int l, int r) {
    cov[t] = -1;
    if (l == r) {
      a[t] = Node(0, r - l + 1, r - l + 1);
    } else {
      int z = (l + r) >> 1;
      build(((t) << 1), l, z), build(((t) << 1 | 1), z + 1, r);
      up(t);
    }
  }
  void upd(int t, int l, int r, int L, int R, int C) {
    if (L <= l && r <= R) {
      cov[t] = C, a[t] = Node(C, r - l + 1, r - l + 1);
      return;
    }
    down(t);
    int z = (l + r) >> 1;
    if (R <= z)
      upd(((t) << 1), l, z, L, R, C);
    else if (L > z)
      upd(((t) << 1 | 1), z + 1, r, L, R, C);
    else
      upd(((t) << 1), l, z, L, R, C), upd(((t) << 1 | 1), z + 1, r, L, R, C);
    up(t);
  }
  Node qry(int t, int l, int r, int L, int R) {
    if (L <= l && r <= R) return a[t];
    down(t);
    int z = (l + r) >> 1;
    Node ret;
    if (R <= z)
      ret = qry(((t) << 1), l, z, L, R);
    else if (L > z)
      ret = qry(((t) << 1 | 1), z + 1, r, L, R);
    else
      merge(ret, qry(((t) << 1), l, z, L, R),
            qry(((t) << 1 | 1), z + 1, r, L, R));
    up(t);
    return ret;
  }
} seg;
int main() {
  scanf("%d%d", &n, &t);
  for (int i = (0); i < (n); ++i) p[i].in();
  p[n++] = (Panel){t, -INF, INF}, p[n++] = (Panel){0, -INF, INF};
  for (int i = (0); i < (n); ++i) V.push_back(p[i].l), V.push_back(p[i].r);
  sort((V).begin(), (V).end()), sort(p, p + n);
  V.erase(unique((V).begin(), (V).end()), V.end());
  for (int i = (0); i < (n); ++i) {
    p[i].l = lower_bound((V).begin(), (V).end(), p[i].l) - V.begin();
    p[i].r = lower_bound((V).begin(), (V).end(), p[i].r) - V.begin();
  }
  f[0] = INF << 1, seg.build(1, 0, ((int)(V).size()) - 1);
  for (int i = 1, j; i < n; i = j) {
    j = i + 1;
    while (j < n && p[j].h == p[i].h) ++j;
    for (int k = (i); k < (j); ++k) {
      int x = p[k].l;
      while (x <= p[k].r) {
        Node nd = seg.qry(1, 0, ((int)(V).size()) - 1, x, p[k].r);
        int l = max(p[k].l, p[nd.lc].l), r = min(p[k].r, p[nd.lc].r);
        if (x == l && x + nd.len - 1 == r)
          f[k] = max(f[k], min(f[nd.lc], V[r] - V[l]));
        x += nd.len;
      }
    }
    for (int k = (i); k < (j); ++k)
      seg.upd(1, 0, ((int)(V).size()) - 1, p[k].l, p[k].r, k);
  }
  printf("%d\n", f[n - 1]);
  return 0;
}
