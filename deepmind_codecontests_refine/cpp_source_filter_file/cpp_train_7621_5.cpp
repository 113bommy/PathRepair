#include <bits/stdc++.h>
const long long mod = 998244353;
long long qpow(long long x, long long k) {
  long long r = 1;
  for (; k; k >>= 1, (x *= x) %= mod)
    if (k & 1) (r *= x) %= mod;
  return r;
}
int rnk[1111], top;
long long f[111][111];
int n;
int l[1111], r[1111];
int main() {
  scanf("%d", &n);
  register int i, ii, iii, iiii;
  long long t = 1;
  for (i = 1; i <= n; i++)
    scanf("%d%d", l + i, r + i), r[i]++, (t *= (r[i] - l[i])) %= mod;
  for (i = 1; i <= n; i++) rnk[++top] = l[i], rnk[++top] = r[i];
  std::sort(rnk + 1, rnk + top + 1);
  f[0][top] = 1, l[0] = -1, r[0] = 1e9 + 7;
  for (i = 1; i <= n; i++) {
    for (ii = top - 1; ii; ii--) {
      if (l[i] >= rnk[ii + 1] || r[i] <= rnk[ii]) continue;
      int sz = rnk[ii + 1] - rnk[ii] - 1, R = 0, C = 1;
      for (iii = i - 1; ~iii; iii--) {
        sz++, R++, C = C * sz % mod * qpow(R, mod - 2) % mod;
        for (iiii = ii + 1; iiii <= top; iiii++)
          (f[i][ii] += f[iii][iiii] * C) %= mod;
        if (l[iii] >= rnk[ii + 1] || r[iii] <= rnk[ii]) break;
      }
    }
  }
  long long sum = 0;
  for (i = 1; i <= top; i++) (sum += f[n][i]) %= mod;
  printf("%lld\n", sum * qpow(t, mod - 2) % mod);
}
