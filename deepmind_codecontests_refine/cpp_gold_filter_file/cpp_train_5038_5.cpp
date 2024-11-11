#include <bits/stdc++.h>
const int N = 200010;
using namespace std;
const int mod = 1e9;
long long f0[N], f1[N];
int a[N];
struct Seg {
  int l, r;
  long long s0, s1;
} tree[N * 4];
struct Data {
  long long x, y;
};
void update(int idx) {
  int mid = (tree[idx].l + tree[idx].r) >> 1;
  tree[idx].s0 =
      (tree[idx << 1].s0 + tree[idx << 1 | 1].s0 * f0[mid - tree[idx].l + 1] +
       tree[idx << 1 | 1].s1 * f1[mid - tree[idx].l + 1]) %
      mod;
  tree[idx].s1 =
      (tree[idx << 1].s1 + tree[idx << 1 | 1].s0 * f0[mid - tree[idx].l + 2] +
       tree[idx << 1 | 1].s1 * f1[mid - tree[idx].l + 2]) %
      mod;
}
void b_tree(int l, int r, int idx) {
  tree[idx].l = l;
  tree[idx].r = r;
  tree[idx].s0 = tree[idx].s1 = a[l];
  if (l == r) return;
  int mid = (l + r) >> 1;
  b_tree(l, mid, idx << 1);
  b_tree(mid + 1, r, idx << 1 | 1);
  update(idx);
}
void insert(int id, int x, int idx) {
  if (tree[idx].l == tree[idx].r) {
    tree[idx].s1 = tree[idx].s0 = x;
    return;
  }
  int mid = (tree[idx].l + tree[idx].r) >> 1;
  if (id <= mid)
    insert(id, x, idx << 1);
  else
    insert(id, x, idx << 1 | 1);
  update(idx);
}
Data query(int l, int r, int idx) {
  if (tree[idx].l == l && tree[idx].r == r) {
    return Data{tree[idx].s0, tree[idx].s1};
  }
  int mid = (tree[idx].l + tree[idx].r) >> 1;
  if (r <= mid)
    return query(l, r, idx << 1);
  else if (l > mid)
    return query(l, r, idx << 1 | 1);
  Data d1 = query(l, mid, idx << 1);
  Data d2 = query(mid + 1, r, idx << 1 | 1);
  Data d;
  d.x = (d1.x + d2.x * f0[mid - l + 1] + d2.y * f1[mid - l + 1]) % mod;
  d.y = (d1.y + d2.x * f0[mid - l + 2] + d2.y * f1[mid - l + 2]) % mod;
  return d;
}
int main() {
  f0[0] = 1;
  f1[1] = 1;
  for (int i = 2; i < N; i++) {
    f0[i] = (f0[i - 1] + f0[i - 2]) % mod;
    f1[i] = (f1[i - 1] + f1[i - 2]) % mod;
  }
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  b_tree(1, n, 1);
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      insert(x, v, 1);
    } else if (t == 2) {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%I64d\n", query(l, r, 1).x);
    }
  }
  return 0;
}
