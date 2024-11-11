#include <bits/stdc++.h>
using namespace std;
long long sumdeg[100007][4], res = 0, mod = 998244353, a[100007], n,
                             mobius[100007];
long long pow2(long long i) {
  if (i == 0) return 1;
  long long k = pow2(i / 2);
  if (i % 2 == 0)
    return (k * k) % mod;
  else
    return (k * k * 2) % mod;
}
long long ans(long long i) {
  if (sumdeg[i][0] == 2)
    return (mobius[i] - 4) * (sumdeg[i][1] * sumdeg[i][1]) % mod;
  long long x = (sumdeg[i][1] * sumdeg[i][1]) % mod,
            y = ((sumdeg[i][0] % mod - 2) * sumdeg[i][2]) % mod;
  x = (x * sumdeg[i][0] % mod) % mod;
  return ((mobius[i] - 4) * pow2(sumdeg[i][0] - 3) * (x + y)) % mod;
}
signed main() {
  a[0] = 0;
  mobius[1] = 5;
  for (long long i = 1; i < 100005; i++) {
    a[i] = 0;
    sumdeg[i][0] = 0;
    sumdeg[i][1] = 0;
    sumdeg[i][2] = 0;
    if (mobius[i] == 0)
      for (long long j = i; j < 1e5 + 5; j += i) {
        if (j % (i * i) == 0)
          mobius[j] = 4;
        else if (mobius[j] == 0)
          mobius[j] = 3;
        else
          mobius[j] = 8 - mobius[j];
      }
  }
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    a[x] = y;
  }
  for (long long i = 1; i < 1e5 + 5; i++)
    for (long long j = i; j < 1e5 + 5; j += i) {
      sumdeg[i][0] = sumdeg[i][0] + a[j];
      sumdeg[i][1] = (sumdeg[i][1] + a[j] * j) % mod;
      sumdeg[i][2] = (sumdeg[i][2] + a[j] * ((j * j) % mod)) % mod;
    }
  for (long long i = 1; i < 1e5 + 5; i++)
    if (sumdeg[i][0] > 1) res = (res + ans(i)) % mod;
  if (res < 0) res += mod;
  printf("%lld", res);
}
