#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
long long sum[N * 4], f[N * 4], mi[N * 4], mx[N * 4], a[N];
void push_down(int l, int r, int root) {
  if (!f[root]) return;
  int mid = l + r >> 1;
  sum[root << 1] = 1ll * f[root] * (mid - l + 1);
  sum[root << 1 | 1] = 1ll * f[root] * (r - mid);
  mi[root << 1] = mi[root << 1 | 1] = mx[root << 1] = mx[root << 1 | 1] =
      f[root << 1] = f[root << 1 | 1] = f[root];
  f[root] = 0;
}
void build(int l, int r, int root) {
  if (l == r) {
    sum[root] = mi[root] = mx[root] = a[l];
    return;
  }
  int mid = l + r >> 1;
  build(l, mid, root << 1);
  build(mid + 1, r, root << 1 | 1);
  sum[root] = sum[root << 1] + sum[root << 1 | 1];
  mi[root] = mi[root << 1 | 1];
  mx[root] = mx[root << 1];
}
void update(int l, int r, int root, int ql, int qr, long long v) {
  int mid = l + r >> 1;
  if (l >= ql && r <= qr) {
    if (mi[root] >= v) return;
    if (mx[root] <= v) {
      sum[root] = 1ll * v * (r - l + 1);
      mi[root] = f[root] = mx[root] = v;
      return;
    }
  }
  push_down(l, r, root);
  if (mid >= ql) update(l, mid, root << 1, ql, qr, v);
  if (mid < qr) update(mid + 1, r, root << 1 | 1, ql, qr, v);
  sum[root] = sum[root << 1] + sum[root << 1 | 1];
  if (mi[root << 1] < mi[root << 1 | 1])
    while (1)
      ;
  if (mx[root << 1] < mx[root << 1 | 1])
    while (1)
      ;
  mi[root] = mi[root << 1 | 1];
  mx[root] = mx[root << 1];
}
int query(int l, int r, int root, int ql, int qr, long long& v) {
  if (mi[root] > v) return 0;
  if (l == r) {
    if (v >= sum[root]) {
      v -= sum[root];
      return 1;
    }
    return 0;
  }
  int mid = l + r >> 1;
  push_down(l, r, root);
  if (l >= ql && r <= qr) {
    if (v >= sum[root]) {
      v -= sum[root];
      return r - l + 1;
    }
    int ans = 0;
    if (v >= mi[root << 1]) ans = query(l, mid, root << 1, ql, qr, v);
    if (v >= mi[root << 1 | 1])
      ans += query(mid + 1, r, root << 1 | 1, ql, qr, v);
    return ans;
  }
  int ans = 0;
  if (mid >= ql) ans = query(l, mid, root << 1, ql, qr, v);
  if (mid < qr) ans += query(mid + 1, r, root << 1 | 1, ql, qr, v);
  return ans;
}
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, n, 1);
  while (q--) {
    int op, x;
    long long y;
    scanf("%d%d%lld", &op, &x, &y);
    if (op - 2)
      update(1, n, 1, 1, x, y);
    else
      printf("%d\n", query(1, n, 1, x, n, y));
  }
  return 0;
}
