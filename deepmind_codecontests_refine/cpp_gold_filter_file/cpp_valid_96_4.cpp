#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
long long a[maxn];
struct node {
  long long l, r;
  long long pre, suf, cnt;
  bool flag;
} tree[maxn * 4];
void push_up(int rt) {
  if (tree[rt << 1].flag && tree[rt << 1 | 1].flag) {
    if (a[tree[rt << 1].r] <= a[tree[rt << 1 | 1].l]) {
      tree[rt].pre = tree[rt].r - tree[rt].l + 1;
      tree[rt].suf = tree[rt].r - tree[rt].l + 1;
      tree[rt].flag = 1;
      tree[rt].cnt = 0;
    } else {
      tree[rt].pre = tree[rt << 1].r - tree[rt << 1].l + 1;
      tree[rt].suf = tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1;
      tree[rt].flag = 0;
      tree[rt].cnt = 0;
    }
  } else if (tree[rt << 1].flag) {
    if (a[tree[rt << 1].r] <= a[tree[rt << 1 | 1].l]) {
      tree[rt].pre =
          (tree[rt << 1].r - tree[rt << 1].l + 1) + tree[rt << 1 | 1].pre;
      tree[rt].suf = tree[rt << 1 | 1].suf;
      tree[rt].flag = 0;
      tree[rt].cnt = tree[rt << 1 | 1].cnt;
    } else {
      tree[rt].pre = tree[rt << 1].r - tree[rt << 1].l + 1;
      tree[rt].suf = tree[rt << 1 | 1].suf;
      tree[rt].flag = 0;
      tree[rt].cnt = (tree[rt << 1 | 1].pre + 1) * tree[rt << 1 | 1].pre / 2 +
                     tree[rt << 1 | 1].cnt;
    }
  } else if (tree[rt << 1 | 1].flag) {
    if (a[tree[rt << 1].r] <= a[tree[rt << 1 | 1].l]) {
      tree[rt].pre = tree[rt << 1].pre;
      tree[rt].suf =
          (tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1) + tree[rt << 1].suf;
      tree[rt].flag = 0;
      tree[rt].cnt = tree[rt << 1].cnt;
    } else {
      tree[rt].pre = tree[rt << 1].pre;
      tree[rt].suf = tree[rt << 1 | 1].r - tree[rt << 1 | 1].l + 1;
      tree[rt].flag = 0;
      tree[rt].cnt =
          (tree[rt << 1].suf + 1) * tree[rt << 1].suf / 2 + tree[rt << 1].cnt;
    }
  } else {
    if (a[tree[rt << 1].r] <= a[tree[rt << 1 | 1].l]) {
      tree[rt].pre = tree[rt << 1].pre;
      tree[rt].suf = tree[rt << 1 | 1].suf;
      tree[rt].flag = 0;
      tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt +
                     (tree[rt << 1].suf + tree[rt << 1 | 1].pre + 1) *
                         (tree[rt << 1].suf + tree[rt << 1 | 1].pre) / 2;
    } else {
      tree[rt].pre = tree[rt << 1].pre;
      tree[rt].suf = tree[rt << 1 | 1].suf;
      tree[rt].flag = 0;
      tree[rt].cnt = tree[rt << 1].cnt + tree[rt << 1 | 1].cnt +
                     (tree[rt << 1].suf + 1) * tree[rt << 1].suf / 2 +
                     (tree[rt << 1 | 1].pre + 1) * tree[rt << 1 | 1].pre / 2;
    }
  }
}
void build(int rt, int l, int r) {
  tree[rt].l = l, tree[rt].r = r;
  if (l == r) {
    tree[rt].pre = tree[rt].suf = 1;
    tree[rt].cnt = 0;
    tree[rt].flag = 1;
    return;
  } else {
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    push_up(rt);
  }
}
void update_point(int rt, int pos, long long val) {
  if (tree[rt].l == tree[rt].r && pos == tree[rt].l) {
    a[pos] = val;
    return;
  }
  int mid = tree[rt].l + tree[rt].r >> 1;
  if (pos <= mid)
    update_point(rt << 1, pos, val);
  else
    update_point(rt << 1 | 1, pos, val);
  push_up(rt);
}
long long query_interval(int rt, int l, int r) {
  if (l <= tree[rt].l && r >= tree[rt].r)
    if (tree[rt].flag)
      return (tree[rt].r - tree[rt].l + 2) * (tree[rt].r - tree[rt].l + 1) / 2;
    else
      return tree[rt].cnt + tree[rt].pre * (tree[rt].pre + 1) / 2 +
             tree[rt].suf * (tree[rt].suf + 1) / 2;
  int mid = tree[rt].l + tree[rt].r >> 1;
  if (r <= mid)
    return query_interval(rt << 1, l, r);
  else if (l > mid)
    return query_interval(rt << 1 | 1, l, r);
  else {
    long long res = query_interval(rt << 1, l, mid) +
                    query_interval(rt << 1 | 1, mid + 1, r);
    if (a[tree[rt << 1].r] <= a[tree[rt << 1 | 1].l]) {
      long long llen = mid - max((long long)l, mid - tree[rt << 1].suf + 1) + 1,
                rlen = min((long long)r, mid + tree[rt << 1 | 1].pre) - mid;
      res += llen * rlen;
    }
    return res;
  }
}
void solve() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build(1, 1, n);
  for (int i = 1; i <= q; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int pos, x;
      cin >> pos >> x;
      update_point(1, pos, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << query_interval(1, l, r) << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
