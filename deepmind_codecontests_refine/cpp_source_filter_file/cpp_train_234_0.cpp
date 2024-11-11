#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int const N = 1e6 + 10;
struct Node {
  ll l{0LL}, r{0LL}, maxx{0LL}, minn{0LL}, lazy{0LL}, sum{0LL};
  Node() = default;
} tree[N];
ll a[N];
ll tmpV;
void pushUp(int rt) {
  tree[rt].sum = tree[rt << 1].sum + tree[rt << 1 | 1].sum;
  tree[rt].maxx = max(tree[rt << 1].maxx, tree[rt << 1 | 1].maxx);
  tree[rt].minn = min(tree[rt << 1].minn, tree[rt << 1 | 1].minn);
}
void pushDown(int rt) {
  if (tree[rt].lazy) {
    tree[rt << 1].lazy = tree[rt << 1 | 1].lazy = tree[rt].lazy;
    tree[rt << 1].sum = tree[rt].lazy * (tree[rt << 1].r - tree[rt << 1].r + 1);
    tree[rt << 1 | 1].sum =
        tree[rt].lazy * (tree[rt << 1 | 1].r - tree[rt << 1 | 1].r + 1);
    tree[rt << 1].maxx = tree[rt << 1 | 1].maxx = tree[rt << 1].minn =
        tree[rt << 1 | 1].minn = tree[rt].lazy;
    tree[rt].lazy = 0;
  }
}
void build(int l, int r, int rt) {
  if (l == r) {
    tree[rt].sum = tree[rt].maxx = tree[rt].minn = a[l];
    tree[rt].lazy = 0;
    tree[rt].l = tree[rt].r = l;
    return;
  }
  tree[rt].l = l, tree[rt].r = r;
  int mid = (l + r) >> 1;
  build(l, mid, rt << 1);
  build(mid + 1, r, rt << 1 | 1);
  pushUp(rt);
}
void update(int l, int r, int val, int rt) {
  if (l <= tree[rt].l && tree[rt].r <= r) {
    if (val <= tree[rt].minn) return;
    if (val > tree[rt].maxx) {
      tree[rt].sum = val * (tree[rt].r - tree[rt].l + 1);
      tree[rt].maxx = tree[rt].minn = val;
      tree[rt].lazy = val;
      return;
    }
  }
  pushDown(rt);
  int mid = (tree[rt].l + tree[rt].r) >> 1;
  if (l <= mid) update(l, r, val, rt << 1);
  if (r > mid) update(l, r, val, rt << 1 | 1);
  pushUp(rt);
}
ll query(int l, int r, int rt) {
  if (l <= tree[rt].l && tree[rt].r <= r) {
    if (tmpV < tree[rt].minn) return 0;
    if (tree[rt].sum <= tmpV) {
      tmpV -= tree[rt].sum;
      return tree[rt].r - tree[rt].l + 1;
    }
  }
  if (tree[rt].l == tree[rt].r) return 0;
  pushDown(rt);
  ll sum = 0;
  int mid = (tree[rt].l + tree[rt].r) >> 1;
  if (l <= mid) sum += query(l, r, rt << 1);
  if (r > mid) sum += query(l, r, rt << 1 | 1);
  return sum;
}
int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, n, 1);
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      update(1, x, y, 1);
    } else if (t == 2) {
      tmpV = y;
      cout << query(x, n, 1) << '\n';
    }
  }
  return 0;
}
