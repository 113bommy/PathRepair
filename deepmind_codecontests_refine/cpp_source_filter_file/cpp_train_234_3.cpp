#include <bits/stdc++.h>
using namespace std;
long long n, q;
long long a[500000 + 5];
struct segment_tree {
  struct node {
    long long l;
    long long r;
    long long minv;
    long long sum;
    long long tag;
    long long len() { return r - l + 1; }
  } tree[500000 * 4 + 5];
  void push_up(long long pos) {
    tree[pos].sum = tree[pos << 1].sum + tree[pos << 1 | 1].sum;
    tree[pos].minv = min(tree[pos << 1].minv, tree[pos << 1 | 1].minv);
  }
  void build(long long l, long long r, long long pos) {
    tree[pos].l = l;
    tree[pos].r = r;
    if (l == r) {
      tree[pos].minv = tree[pos].sum = a[l];
      return;
    }
    long long mid = (l + r) >> 1;
    build(l, mid, pos << 1);
    build(mid + 1, r, pos << 1 | 1);
    push_up(pos);
  }
  void set_tag(long long pos, long long val) {
    tree[pos].minv = val;
    tree[pos].tag = val;
    tree[pos].sum = val * tree[pos].len();
  }
  void push_down(long long pos) {
    if (tree[pos].tag) {
      set_tag(pos << 1, tree[pos].tag);
      set_tag(pos << 1 | 1, tree[pos].tag);
      tree[pos].tag = 0;
    }
  }
  void update(long long L, long long R, long long val, long long pos) {
    if (L <= tree[pos].l && R >= tree[pos].r) {
      set_tag(pos, val);
      return;
    }
    push_down(pos);
    long long mid = (tree[pos].l + tree[pos].r) >> 1;
    if (L <= mid) update(L, R, val, pos << 1);
    if (R > mid) update(L, R, val, pos << 1 | 1);
    push_up(pos);
  }
  long long getPos(long long val, long long pos) {
    if (tree[pos].l == tree[pos].r) return tree[pos].l;
    push_down(pos);
    long long mid = (tree[pos].l + tree[pos].r) >> 1;
    if (tree[pos << 1].minv >= val)
      return getPos(val, pos << 1 | 1);
    else
      return getPos(val, pos << 1);
  }
  long long getSum(long long L, long long R, long long pos) {
    if (L > R) return 0;
    if (L <= tree[pos].l && R >= tree[pos].r) return tree[pos].sum;
    push_down(pos);
    long long mid = (tree[pos].l + tree[pos].r) >> 1;
    long long ans = 0;
    if (L <= mid) ans += getSum(L, R, pos << 1);
    if (R > mid) ans += getSum(L, R, pos << 1 | 1);
    return ans;
  }
  long long getAns(long long &val, long long pos) {
    if (tree[pos].sum <= val) {
      val -= tree[pos].sum;
      return tree[pos].r - tree[pos].l + 1;
    }
    if (tree[pos].l == tree[pos].r) return 0;
    push_down(pos);
    long long mid = (tree[pos].l + tree[pos].r) >> 1;
    long long ans = 0;
    if (tree[pos << 1].minv <= val) ans += getAns(val, pos << 1);
    if (tree[pos << 1 | 1].minv <= val) ans += getAns(val, pos << 1 | 1);
    return ans;
  }
} T;
signed main() {
  long long op;
  long long x, y;
  scanf("%d %d", &n, &q);
  for (long long i = 1; i <= n; i++) scanf("%d", &a[i]);
  T.build(1, n, 1);
  for (long long i = 1; i <= q; i++) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%lld %lld", &x, &y);
      long long p = T.getPos(y, 1);
      if (p <= x) T.update(p, x, y, 1);
    } else {
      scanf("%lld %lld", &x, &y);
      y += T.getSum(1, x - 1, 1);
      long long ans = T.getAns(y, 1) - (x - 1);
      printf("%lld\n", ans);
    }
  }
}
