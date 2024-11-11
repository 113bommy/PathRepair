#include <bits/stdc++.h>
using namespace std;
const int P = 1000000007, N = 200005;
int n, m;
int a[N], w[N], caw[4 * N], Ans;
long long cw[4 * N], Sum;
long long queryw(int p, int l, int r, int x, int y) {
  if (x > y) return 0;
  if (l == x && r == y) return cw[p];
  int mid = (l + r) >> 1, ll = p << 1;
  if (y <= mid)
    return queryw(ll, l, mid, x, y);
  else if (x >= mid + 1)
    return queryw(ll | 1, mid + 1, r, x, y);
  else
    return queryw(ll, l, mid, x, mid) + queryw(ll | 1, mid + 1, r, mid + 1, y);
}
int queryaw(int p, int l, int r, int x, int y) {
  if (x > y) return 0;
  if (l == x && r == y) return caw[p];
  int mid = (l + r) >> 1, ll = p << 1;
  if (y <= mid)
    return queryaw(ll, l, mid, x, y);
  else if (x >= mid + 1)
    return queryaw(ll | 1, mid + 1, r, x, y);
  else
    return (queryaw(ll, l, mid, x, mid) +
            queryaw(ll | 1, mid + 1, r, mid + 1, y)) %
           P;
}
void build(int p, int l, int r) {
  if (l == r) {
    caw[p] = 1ll * (a[l] + P - l) * w[l] % P;
    cw[p] = w[l];
    return;
  }
  int mid = (l + r) >> 1, ll = p << 1;
  build(ll, l, mid);
  build(ll | 1, mid + 1, r);
  cw[p] = cw[ll] + cw[ll | 1];
  caw[p] = (caw[ll] + caw[ll | 1]) % P;
}
void change(int p, int l, int r, int x) {
  if (l == r) {
    caw[p] = 1ll * (a[l] + P - l) * w[l] % P;
    cw[p] = w[l];
    return;
  }
  int mid = (l + r) >> 1, ll = p << 1;
  if (x <= mid)
    change(ll, l, mid, x);
  else
    change(ll | 1, mid + 1, r, x);
  cw[p] = cw[ll] + cw[ll | 1];
  caw[p] = (caw[ll] + caw[ll | 1]) % P;
}
int findKth(int p, int l, int r) {
  if (l == r) return l;
  int mid = (l + r) >> 1, ll = p << 1;
  if (cw[ll] >= Sum - cw[ll])
    return findKth(ll, l, mid);
  else {
    Sum -= cw[ll];
    return findKth(ll | 1, mid + 1, r);
  }
}
int find(int p, int l, int r, int x, int y) {
  if (l == x && r == y) {
    if (cw[p] >= Sum - cw[p])
      return findKth(p, l, r);
    else {
      Sum -= cw[p];
      return -1;
    }
  }
  int mid = (l + r) >> 1, ll = p << 1;
  if (y <= mid)
    return find(ll, l, mid, x, y);
  else if (x >= mid + 1)
    return find(ll | 1, mid + 1, r, x, y);
  else {
    int tmp = find(ll, l, mid, x, mid);
    if (tmp != -1) return tmp;
    return find(ll | 1, mid + 1, r, mid + 1, y);
  }
}
void upd(int &x, long long y) { x = (x + y) % P; }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  build(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x < 0) {
      w[-x] = y;
      change(1, 1, n, -x);
    } else {
      Sum = queryw(1, 1, n, x, y);
      int K = find(1, 1, n, x, y);
      Ans = 0;
      upd(Ans, 1ll * (a[K] + P - K) * (queryw(1, 1, n, x, K) % P));
      upd(Ans, P - queryaw(1, 1, n, x, K));
      upd(Ans, 1ll * (K + P - a[K]) * (queryw(1, 1, n, K + 1, y) % P));
      upd(Ans, queryaw(1, 1, n, K + 1, y));
      printf("%d\n", Ans);
    }
  }
  return 0;
}
