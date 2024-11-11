#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxlog = 35;
int n, q, L, R, tot, root;
int sum[maxn * maxlog], lazy[maxn * maxlog];
int lc[maxn * maxlog], rc[maxn * maxlog];
inline void update(int x) { sum[x] = sum[lc[x]] + sum[rc[x]]; }
void down_lazy(int l, int r, int x) {
  if (~lazy[x]) {
    int mid = l + r >> 1;
    if (!lc[x]) lc[x] = ++tot;
    sum[lc[x]] = lazy[x] * (mid - l + 1), lazy[lc[x]] = lazy[x];
    if (!rc[x]) rc[x] = ++tot;
    sum[rc[x]] = lazy[x] * (r - mid), lazy[rc[x]] = lazy[x];
    lazy[x] = -1;
  }
}
void modify(int l, int r, int &x, int k) {
  if (!x) x = ++tot;
  if (L <= l && r <= R) {
    sum[x] = (r - l + 1) * k;
    lazy[x] = k;
    return;
  }
  int mid = l + r >> 1;
  down_lazy(l, r, x);
  if (L <= mid) modify(l, mid, lc[x], k);
  if (mid < R) modify(mid + 1, r, rc[x], k);
  update(x);
}
int main() {
  cin >> n >> q;
  memset(lazy, -1, sizeof lazy);
  L = 1, R = n;
  modify(1, n, root, 0);
  while (q--) {
    int k;
    scanf("%d %d %d", &L, &R, &k);
    modify(1, n, root, 2 - k);
    printf("%d\n", n - sum[1]);
  }
  return 0;
}
