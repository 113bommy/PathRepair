#include <bits/stdc++.h>
using namespace std;
long long pow(long long x, long long y) {
  long long t = 1;
  for (; y; y >>= 1) {
    if (y & 1) t = (long long)t * x;
    x = (long long)x * x;
  }
  return t;
}
long long gcd(long long x, long long y) {
  long long r = x % y;
  while (r != 0) x = y, y = r, r = x % y;
  return y;
}
long long n, l, r, f[10010];
int main() {
  cin >> n >> l >> r;
  memset(f, -1, sizeof(f));
  f[1] = 1;
  for (long long i = 2; i <= 10000; i++) {
    if ((log((double)r) / log((double)i)) < (double)(n - 1) - 1e-12)
      break;
    else
      f[i] = pow(i, n - 1);
  }
  long long ans = 0;
  if (n == 1) ans = r - l + 1;
  if (n == 2) ans = (r - l + 1) * (r - l);
  if (n > 2) {
    for (long long x = 1; x <= 10000; x++) {
      long long res1 = f[x];
      if (res1 == -1) break;
      for (long long y = x + 1; y <= 10000; y++) {
        long long res2 = f[y];
        if (res2 == -1) break;
        if (gcd(x, y) == 1) {
          long long k = 1, j;
          if (l % res1 == 0)
            k = l / res1;
          else
            k = l / res1 + 1;
          j = r / res2 + 1;
          if (j > k) ans += (j - k) * 2;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
