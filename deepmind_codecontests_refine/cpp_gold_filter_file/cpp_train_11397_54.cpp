#include <bits/stdc++.h>
long long n, k, m;
long long dp[1010][110][2], pw[1010], PW[1010];
long long Solve(long long p, long long r, int f) {
  if (p <= 0) return f;
  if (~dp[p][r][f]) return dp[p][r][f];
  if (f) return (9LL * PW[p - 1]) % m;
  long long res = 0;
  for (int i = ((p == 1) ? 1 : 0); i <= (9); ++i) {
    long long nr = (r + (long long)i * pw[n - p]) % k;
    res = (res + Solve(p - 1, nr, f || (!nr && i))) % m;
  }
  return dp[p][r][f] = res;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &k, &m);
  pw[0] = PW[0] = 1;
  for (int i = 1; i <= (n); ++i)
    pw[i] = (pw[i - 1] * 10) % k, PW[i] = (PW[i - 1] * 10) % m;
  memset(dp, -1, sizeof(dp));
  printf("%I64d\n", Solve(n, 0, 0));
  return 0;
}
