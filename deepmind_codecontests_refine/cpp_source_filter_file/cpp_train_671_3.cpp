#include <bits/stdc++.h>
using namespace std;
long long ans, n, k, p = 1e9 + 7, fac[200010], jc[200010], ny[200010],
                     a[200010];
char s[200010];
long long C(long long y, long long x) {
  if (x < 0 || y < 0 || x < y) return 0;
  return jc[x] * ny[y] % p * ny[x - y] % p;
}
long long ksm(long long x, long long y) {
  long long xlh = 1;
  while (y) {
    if (y & 1) xlh = xlh * x % p;
    x = x * x % p;
    y /= 2;
  }
  return xlh;
}
int main() {
  long long i, xlh = 0, now, mlby = 0;
  scanf("%lld%lld", &n, &k);
  scanf("%s", s + 1);
  for (i = 1; i <= n; i++) (a[i] = a[i - 1] * 10 + s[i] - '0') % p;
  for (i = 2; i < n; i++) (xlh += a[i]) %= p;
  for (i = 1; i < n - 1; i++) mlby = (mlby + a[i]) % p;
  fac[0] = jc[0] = ny[0] = 1;
  for (i = 1; i <= n; i++)
    fac[i] = fac[i - 1] * 10 % p, jc[i] = jc[i - 1] * i % p,
    ny[i] = ksm(jc[i], p - 2);
  now = (xlh - mlby * fac[1] % p + p) % p;
  ans = (ans + C(k - 2, n - 1 - 2) * now) % p;
  for (i = 2; i <= n; i++) {
    xlh = (xlh - a[i] + p) % p;
    mlby = (mlby - a[n - i] + p) % p;
    now = (xlh - mlby * fac[i] % p + p) % p;
    ans = (ans + C(k - 2, n - i - 2) * now) % p;
  }
  for (i = 1; i < n; i++) {
    ans = (ans + a[i] * C(k - 1, n - i - 1)) % p;
  }
  for (i = n; i > 1; i--) {
    now = (a[n] - a[i - 1] * fac[n - i + 1] % p + p) % p;
    ans = (ans + now * C(k - 1, i - 2));
  }
  ans = (ans + C(k, 0) * a[n]) % p;
  printf("%lld", ans);
}
