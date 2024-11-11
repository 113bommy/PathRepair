#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
struct IntervalTree {
  long long sum[maxn << 3], setv[maxn << 3], val[maxn << 3];
  void pushup(int o) {
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
    if (setv[o << 1] == setv[o << 1 | 1])
      setv[o] = setv[o << 1];
    else
      setv[o] = 0;
  }
  void build(int o, int l, int r) {
    sum[o] = val[o] = setv[o] = 0;
    if (l == r) {
      setv[o] = l;
      return;
    }
    int mid = (l + r) / 2;
    build(o << 1, l, mid);
    build(o << 1 | 1, mid + 1, r);
    pushup(o);
  }
  void pushdown(int o, int l, int r) {
    if (val[o]) {
      int mid = (l + r) >> 1;
      sum[o << 1] += val[o] * (mid - l + 1);
      sum[o << 1 | 1] += val[o] * (r - mid);
      val[o << 1] += val[o];
      val[o << 1 | 1] += val[o];
      setv[o << 1] = setv[o << 1 | 1] = setv[o];
      val[o] = setv[o] = 0;
    }
  }
  void update(int o, int l, int r, int q1, int q2, long long x) {
    if (q1 <= l && r <= q2) {
      if (setv[o]) {
        sum[o] += (r - l + 1) * abs(setv[o] - x);
        val[o] += abs(setv[o] - x);
        setv[o] = x;
        return;
      }
    }
    int mid = (l + r) >> 1;
    pushdown(o, l, r);
    if (q1 <= mid) update(o << 1, l, mid, q1, q2, x);
    if (q2 > mid) update(o << 1 | 1, mid + 1, r, q1, q2, x);
    pushup(o);
  }
  long long query(int o, int l, int r, int q1, int q2) {
    int mid = ((l + r) / 2);
    if (q1 <= l && r <= q2) return sum[o];
    pushdown(o, l, r);
    long long x = 0, y = 0;
    if (q1 <= mid) x = query(o << 1, l, mid, q1, q2);
    if (q2 > mid) y = query(o << 1 | 1, mid + 1, r, q1, q2);
    pushup(o);
    return x + y;
  }
} tree;
int main() {
  int op, a, b, v;
  scanf("%d%d", &n, &m);
  tree.build(1, 1, n);
  while (m--) {
    scanf("%d%d%d", &op, &a, &b);
    if (op == 1) {
      scanf("%d", &v);
      tree.update(1, 1, n, a, b, v);
    } else
      cout << tree.query(1, 1, n, a, b) << endl;
  }
  return 0;
}
