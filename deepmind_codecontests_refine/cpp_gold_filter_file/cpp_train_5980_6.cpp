#include <bits/stdc++.h>
using namespace std;
struct cell {
  long long ll, rl, rr, lr;
};
bool g[1000008];
long long n, m, ll[1000008], lr[1000008], rr[1000008], rl[1000008];
void build(int k, long long l, long long r) {
  if (l == r) {
    ll[k] = rr[k] = 0;
    lr[k] = rl[k] = 1;
    if (g[l]) ll[k] = lr[k] = rl[k] = 1000000007;
    if (g[n + l]) rr[k] = lr[k] = rl[k] = 1000000007;
    return;
  }
  long long mid = l + r >> 1;
  build((k << 1), l, mid);
  build((k << 1 | 1), mid + 1, r);
  ll[k] = min(ll[(k << 1)] + ll[(k << 1 | 1)] + 1,
              lr[(k << 1)] + rl[(k << 1 | 1)] + 1);
  lr[k] = min(lr[(k << 1)] + rr[(k << 1 | 1)] + 1,
              ll[(k << 1)] + lr[(k << 1 | 1)] + 1);
  rr[k] = min(rr[(k << 1)] + rr[(k << 1 | 1)] + 1,
              rl[(k << 1)] + lr[(k << 1 | 1)] + 1);
  rl[k] = min(rl[(k << 1)] + ll[(k << 1 | 1)] + 1,
              rr[(k << 1)] + rl[(k << 1 | 1)] + 1);
}
cell query(int k, long long l, long long r, long long x, long long y) {
  if (x <= l && y >= r) {
    cell e;
    e.ll = ll[k];
    e.lr = lr[k];
    e.rr = rr[k];
    e.rl = rl[k];
    return e;
  }
  long long mid = l + r >> 1;
  cell e1, e2, e;
  if (k == 0) return e;
  if (x <= mid) e1 = query((k << 1), l, mid, x, y);
  if (y > mid) e2 = query((k << 1 | 1), mid + 1, r, x, y);
  if (x <= mid && y > mid) {
    e.ll = min(e1.ll + e2.ll + 1, e1.lr + e2.rl + 1);
    e.lr = min(e1.ll + e2.lr + 1, e1.lr + e2.rr + 1);
    e.rr = min(e1.rr + e2.rr + 1, e1.rl + e2.lr + 1);
    e.rl = min(e1.rl + e2.ll + 1, e1.rr + e2.rl + 1);
  } else if (x <= mid)
    e = e1;
  else if (y > mid)
    e = e2;
  return e;
}
int main() {
  long long x, y, i, j;
  char c;
  scanf("%lld%lld", &n, &m);
  for (j = 0; j < 2; j++)
    for (i = 1; i <= n; i++) {
      scanf("%c", &c);
      while (c != '.' && c != 'X') scanf("%c", &c);
      if (c == '.')
        g[j * n + i] = 0;
      else
        g[j * n + i] = 1;
    }
  build(1, 1, n);
  for (i = 1; i <= m; i++) {
    scanf("%lld%lld", &x, &y);
    long long xx = x, yy = y, ans;
    if (x > n) xx = xx - n;
    if (y > n) yy = yy - n;
    if (xx > yy) {
      swap(xx, yy);
      swap(x, y);
    }
    cell e = query(1, 1, n, xx, yy);
    if (x <= n && y <= n)
      ans = e.ll;
    else if (x <= n && y > n)
      ans = e.lr;
    else if (x > n && y <= n)
      ans = e.rl;
    else if (x > n && y > n)
      ans = e.rr;
    if (ans > 400000 || ans < 0)
      printf("-1\n");
    else
      printf("%lld\n", ans);
  }
  return 0;
}
