#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long m;
long long sum[4][1000005];
const long long bk2 = (mod + 1) / 2, bk3 = (mod + 1) / 3, bk6 = (mod + 1) / 6;
int main() {
  scanf("%I64d", &m);
  sum[0][0] = 1;
  for (int i = 1; i < 1000005; i++) {
    long long ns = 1;
    for (int j = 0; j < 4; j++) {
      sum[j][i] = (sum[j][i - 1] + ns * 2) % mod;
      ns = ns * i % mod * i % mod;
    }
  }
  long long nm = m % mod;
  long long ans = 0;
  for (long long i = 0; i * i <= m; i++) {
    long long n1 = m - i * i;
    long long l = 0, r = 1000005;
    while (l < r) {
      long long mid = ((l + r) >> 1) + 1;
      if (mid * mid <= n1)
        l = mid;
      else
        r = mid - 1;
    }
    long long ksm[4];
    ksm[0] = 1;
    for (int j = 1; j < 4; j++) ksm[j] = ksm[j - 1] * i % mod * i % mod;
    long long num[4] = {
        ksm[3] * bk3 % mod - (nm + 2) * bk2 % mod * ksm[2] % mod +
            (3 * nm + 4) % mod * bk6 % mod * ksm[1] % mod +
            nm * (nm + 1) % mod * (nm + 2) % mod * bk6 % mod,
        ksm[2] - (nm + 2) * ksm[1] % mod + (3 * nm + 4) % mod * bk6 % mod,
        ksm[1] - (nm + 2) * bk2 % mod, bk3};
    long long nans = 0;
    for (int j = 0; j < 4; j++) nans = (nans + num[j] % mod * sum[j][l]) % mod;
    if (!i)
      ans = (ans + nans) % mod;
    else
      ans = (ans + 2 * nans) % mod;
  }
  ans = (ans % mod + mod) % mod;
  printf("%I64d\n", ans);
  return 0;
}
