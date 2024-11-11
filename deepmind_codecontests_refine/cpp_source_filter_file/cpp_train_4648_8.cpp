#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int rt[105], tot;
int ls[N * 30], rs[N * 30];
int a[N], ans[N];
int merge(int x, int y) {
  if (!x || !y) return (x + y);
  ls[x] = merge(ls[x], ls[y]);
  rs[x] = merge(rs[x], rs[y]);
  return x;
}
void update(int &o, int l, int r, int pos) {
  o = ++tot;
  if (l == r) return;
  int mid = l + r >> 1;
  if (pos <= mid)
    update(ls[o], l, mid, pos);
  else
    update(rs[o], mid + 1, r, pos);
}
void change(int &x, int &y, int l, int r, int L, int R) {
  if (!x) return;
  if (L <= l && R >= r) {
    y = merge(x, y);
    x = 0;
    return;
  }
  if (!y) y = ++tot;
  int mid = l + r >> 1;
  if (L <= mid) change(ls[x], ls[y], l, mid, L, R);
  if (R > mid) change(rs[x], rs[y], mid + 1, r, L, R);
}
void query(int o, int l, int r, int v) {
  if (!o) return;
  if (l == r) {
    ans[l] = v;
    return;
  }
  int mid = l + r >> 1;
  query(ls[o], l, mid, v);
  query(rs[o], mid + 1, r, v);
}
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    update(rt[a[i]], 1, n, i);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r, a, b;
    scanf("%d%d%d%d", &l, &r, &a, &b);
    if (a != b) change(rt[a], rt[b], 1, n, l, r);
  }
  for (int i = 1; i <= 100; i++) query(rt[i], 1, n, i);
  for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
