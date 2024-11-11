#include <bits/stdc++.h>
using namespace std;
long long n, m, k, p = 998244353, ans, jc[500010], ny[500010], a[500010];
long long ksm(long long x, long long y) {
  long long xlh = 1;
  while (y) {
    if (y & 1) xlh = xlh * x % p;
    x = x * x % p;
    y /= 2;
  }
  return xlh;
}
long long C(long long x, long long y) {
  return jc[x] * ny[y] % p * ny[x - y] % p;
}
int main() {
  long long i, j, xlh;
  scanf("%lld%lld", &n, &k);
  jc[0] = ny[0] = 1;
  for (i = 1; i <= n; i++)
    jc[i] = jc[i - 1] * i % p, ny[i] = ksm(jc[i], p - 2) % p;
  for (i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (i = 1; i <= n; i++) {
    if (i == 1)
      j = n;
    else
      j = i - 1;
    if (a[i] != a[j]) m++;
  }
  if (k >= 2) {
    for (i = 0; i <= m; i++) {
      xlh = ksm(2, i);
      if (i % 2 == 1)
        xlh = xlh * ksm(2, p - 2) % p;
      else
        xlh = (xlh - C(i, i / 2) + p) % p * ksm(2, p - 2) % p;
      xlh = xlh * C(m, i) % p;
      xlh = xlh * ksm(k - 2, m - i) % p;
      ans = (ans + xlh) % p;
    }
  } else
    ans = 1;
  ans = ans * ksm(k, n - m) % p;
  printf("%lld\n", ans);
}
