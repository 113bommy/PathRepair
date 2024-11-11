#include <bits/stdc++.h>
using namespace std;
long long n, k, l, r;
void ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  ex_gcd(b, a % b, x, y);
  long long t = x;
  x = y;
  y = t - a / b * y;
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  if (l > r)
    r = n - l + r + 1, l = 1;
  else
    r = r - l + 1, l = 1;
  if (n <= 1000000) {
    long long ans = -1;
    for (int bit = 1; bit <= 2; bit++)
      for (int lt = 1; lt <= bit; lt++) {
        for (int i = n + bit - 1; i <= n * 2; i++) {
          long long t = k / i;
          long long y = k % i;
          if (r == n) {
            if ((y + lt - 1) % i == 0) ans = max(i - n, ans);
            continue;
          }
          if (i - n - (y - r + bit - lt) > n - r || y - r > i - n ||
              y - r + 1 < lt || y > (r - 1) * 2 + lt)
            continue;
          ans = max(i - n, ans);
        }
      }
    printf("%lld\n", ans);
  } else {
    long long lim = k / n, ans = -1;
    for (int bit = 1; bit <= 2; bit++)
      for (int lt = 1; lt <= bit; lt++) {
        if (k < r + lt - 1) continue;
        if (k <= r * 2 - 2 + lt) {
          ans = max(ans, k - r + bit - 1 + n - r);
          continue;
        }
        for (int i = 1; i <= lim; i++) {
          long long y = k / i;
          long long x = k % i;
          if (x < r - 1 + lt) {
            long long t = (r - 2 + lt - x) / i + 1;
            x += t * i;
            y -= t;
          }
          if ((y - x + lt - bit) - 2 * (n - r) > 0) {
            long long t = ((y - x + lt - bit) - 2 * (n - r) - 1) / (i + 1) + 1;
            x += t * i;
            y -= t;
          }
          if (x > y) continue;
          if (r == n) {
            if ((y - x - bit + lt) % (i + 1) == 0) {
              long long t = (y - x - bit + lt) / (i + 1);
              x += t * i;
              y -= t;
            }
            if ((!x && lt == bit) || x + bit - lt == y) ans = max(ans, y - n);
            continue;
          }
          if (y > 2 * (n - 1) + bit || (y < n - 1 + bit && y != 0)) continue;
          if (x > (r - 1) * 2 + lt || (x < r - 1 + lt && x != 0)) continue;
          ans = max(y - n, ans);
        }
      }
    printf("%lld\n", ans);
  }
}
