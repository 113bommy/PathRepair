#include <bits/stdc++.h>
using namespace std;
long long n;
void exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return;
  }
  exgcd(b, a % b, x, y);
  long long p = x - a / b * y;
  x = y;
  y = p;
}
long long dv(long long a, long long b) {
  if (b == 0) return 8e18;
  long long u = a / b - 2;
  while ((u + 1) * b <= a) ++u;
  return u;
}
long long wo(long long p, long long q, long long k, long long b) {
  if (k < p) return -1;
  k -= p;
  long long ua = min(p, k);
  if (b <= ua)
    ;
  else
    return -1;
  if (n < 900000) {
    for (int w = n; w >= 0; --w) {
      long long u = w + n, t = (k - ua) / u - 2;
      while (u * t < k - ua || t < 0) ++t;
      while (u * t <= k - b) {
        long long A = k - u * t, B = w - A;
        if (b <= A && A <= ua)
          ;
        else
          throw "GG";
        if (0 <= B && B <= q) return w;
        ++t;
      }
    }
    return -1;
  }
  long long aa = -1;
  for (long long t = 0; n * t <= k; ++t) {
    long long A = t + 1, B = t, C = k - n * t;
    if (C == 0) {
      if (b <= 0) {
        if (t == 0)
          aa = max(aa, q);
        else
          aa = max(aa, 0LL);
      }
      continue;
    }
    long long a0, b0;
    exgcd(A, B, a0, b0);
    a0 *= C;
    b0 *= C;
    if (B == 0) {
      if (b <= a0 && a0 <= p)
        ;
      else
        continue;
    }
    long long k = min(dv(a0 - b, B), dv(q - b0, A));
    if (a0 - k * B <= ua && b0 + k * A >= 0)
      ;
    else
      continue;
    aa = max(aa, a0 + b0 + k);
  }
  return aa;
}
int main() {
  long long l, r, k;
  cin >> n >> l >> r >> k;
  long long g = r - l + 1;
  if (g < 0) g += n;
  long long ans = -1;
  ans = max(ans, wo(g, n - g, k, 0));
  ans = max(ans, wo(g, n - g, k + 1, 1));
  cout << ans << "\n";
}
