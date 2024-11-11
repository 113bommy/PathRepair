#include <bits/stdc++.h>
using namespace std;
int n, m, a[100010], mx[270000];
long long t[270000];
inline void build_tree(int p, int l, int r) {
  if (l == r) {
    t[p] = a[l];
    mx[p] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  build_tree(p << 1, l, mid);
  build_tree(p << 1 | 1, mid + 1, r);
  t[p] = t[p << 1] + t[p << 1 | 1];
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
inline long long query(int p, int l, int r, int ll, int rr) {
  if (l >= ll && r <= rr) return t[p];
  long long res = 0;
  int mid = (l + r) >> 1;
  if (ll <= mid) res += query(p << 1, l, mid, ll, rr);
  if (rr > mid) res += query(p << 1 | 1, mid + 1, r, ll, rr);
  return res;
}
inline void mod(int p, int l, int r, int ll, int rr, int x) {
  if (mx[p] < x) return;
  if (l == r) {
    t[p] %= x;
    mx[p] %= x;
    return;
  }
  int mid = (l + r) >> 1;
  if (ll <= mid) mod(p << 1, l, mid, ll, rr, x);
  if (rr > mid) mod(p << 1 | 1, mid + 1, r, ll, rr, x);
  t[p] = t[p << 1] + t[p << 1 | 1];
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
inline void cg(int p, int l, int r, int x, int num) {
  if (l == r) {
    t[p] = mx[p] = num;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    cg(p << 1, l, mid, x, num);
  else
    cg(p << 1 | 1, mid + 1, r, x, num);
  t[p] = t[p << 1] + t[p << 1 | 1];
  mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  build_tree(1, 1, n);
  int tp, l, r, x;
  while (m--) {
    scanf("%d%d%d", &tp, &l, &r);
    if (tp == 1) {
      cout << query(1, 1, n, l, r) << endl;
    }
    if (tp == 2) {
      scanf("%d", &x);
      mod(1, 1, n, l, r, x);
    }
    if (tp == 3) {
      cg(1, 1, n, l, r);
    }
  }
  return 0;
}
