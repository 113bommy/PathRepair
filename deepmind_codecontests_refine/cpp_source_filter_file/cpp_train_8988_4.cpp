#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
struct node {
  int l, r;
};
struct segtree {
  node seg[maxn << 2];
  int lsum[maxn << 2], rsum[maxn << 2], sum[maxn << 2];
  void pushup(int o) {
    int len = seg[o].r - seg[o].l + 1;
    lsum[o] = lsum[o << 1];
    rsum[o] = rsum[o << 1 | 1];
    if (lsum[o] == len - (len >> 1)) lsum[o] += lsum[o << 1 | 1];
    if (rsum[o] == len >> 1) rsum[o] += rsum[o << 1];
    sum[o] =
        max(lsum[o << 1 | 1] + rsum[o << 1], max(sum[o << 1], sum[o << 1 | 1]));
  }
  void build(int o, int l, int r) {
    seg[o].l = l, seg[o].r = r;
    lsum[o] = rsum[o] = sum[o] = r - l + 1;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(o << 1, l, m);
    build(o << 1 | 1, m + 1, r);
  }
  void update(int o, int v) {
    if (seg[o].l == seg[o].r) {
      if (v < 0)
        sum[o] = lsum[o] = rsum[o] = 1;
      else
        sum[o] = lsum[o] = rsum[o] = 0;
      return;
    }
    int m = (seg[o].l + seg[o].r) >> 1;
    if (abs(v) <= m)
      update(o << 1, v);
    else
      update(o << 1 | 1, v);
    pushup(o);
  }
  int query(int o, int v) {
    if (seg[o].l == 1 && lsum[o] >= v) return 1;
    if (seg[o].l == seg[o].r) return seg[o].l;
    int m = (seg[o].l + seg[o].r) >> 1;
    if (sum[o << 1] + 1 >= 2 * v)
      return query(o << 1, v);
    else if (rsum[o << 1] + lsum[o << 1 | 1] + 1 >= 2 * v)
      return m + v - rsum[o << 1];
    else
      return query(o << 1 | 1, v);
  }
} tree;
int ps[10000001];
int main() {
  int n, m;
  while (scanf("%d%d", &n, &m) != EOF) {
    tree.build(1, 1, n);
    for (int i = 1; i <= m; i++) {
      int op, x, pos = -1;
      scanf("%d%d", &op, &x);
      if (op == 1) {
        int t = (tree.sum[1] + 1) / 2;
        t = max(t, tree.lsum[1]);
        t = max(t, tree.rsum[1]);
        ps[x] = tree.query(1, t);
        tree.update(1, ps[x]);
        printf("cas %d\n", ps[x]);
      } else {
        tree.update(1, -ps[x]);
      }
    }
  }
}
