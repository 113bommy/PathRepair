#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int d_, x_, y_;
void gcd(int a, int b) {
  if (b == 0)
    d_ = a, x_ = 1, y_ = 0;
  else {
    int tmp;
    gcd(b, a % b);
    tmp = x_ - a / b * y_, x_ = y_, y_ = tmp;
  }
}
int inv(int a) {
  gcd(a, 1000000007);
  return x_;
}
int main() {
  static int ll[200000], rr[200000], vv[200000], pp[200000];
  int n, i, e1, e2, x, ans;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &ll[i]);
  for (i = 0; i < n; i++) scanf("%d", &rr[i]);
  for (i = 0; i < n; i++) vv[i] = inv(rr[i] - ll[i] + 1);
  for (i = 0; i + 1 < n; i++) {
    int l1 = ll[i], r1 = rr[i];
    int l2 = ll[i + 1], r2 = rr[i + 1];
    int l = max(l1, l2), r = min(r1, r2);
    if (l <= r)
      pp[i] =
          (long long)(r - l + 1) * vv[i] % 1000000007 * vv[i + 1] % 1000000007;
  }
  e1 = e2 = 0;
  for (i = 0; i + 1 < n; i++) {
    e1 = (e1 + pp[i]) % 1000000007;
    e2 = (e2 + pp[i]) % 1000000007;
  }
  for (i = 0; i + 2 < n; i++) {
    int l1 = ll[i], r1 = rr[i];
    int l2 = ll[i + 1], r2 = rr[i + 1];
    int l3 = ll[i + 2], r3 = rr[i + 2];
    int l = max(max(l1, l2), l3);
    int r = min(min(r1, r2), r3);
    if (l <= r)
      e2 = (e2 + (long long)(r - l + 1) * vv[i] % 1000000007 * vv[i + 1] %
                     1000000007 * vv[i + 2] * 2) %
           1000000007;
  }
  x = 0;
  for (i = 2; i + 1 < n; i++) {
    x = (x + pp[i - 2]) % 1000000007;
    e2 = (e2 + (long long)x * pp[i]) % 1000000007;
  }
  ans = ((long long)n * n - n * 2LL * e1 + e2) % 1000000007;
  if (ans < 0) ans += 1000000007;
  printf("%d\n", ans);
  return 0;
}
