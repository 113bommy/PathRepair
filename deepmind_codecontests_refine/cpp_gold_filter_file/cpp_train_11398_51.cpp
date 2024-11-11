#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 30) - 1;
long long n, k, m;
long long dp[1010][110][2], pw[1010];
long long Solve(long long p, long long r, int f) {
  if (p <= 0) return f;
  if (~dp[p][r][f]) return dp[p][r][f];
  int st = (p == 1) ? 1 : 0;
  long long res = 0;
  for (int i = (st); i <= (9); ++i) {
    long long nr = (r + (long long)i * pw[n - p] % k) % k;
    long long nf = !nr;
    res = (res + Solve(p - 1, nr, f || (!nr && i))) % m;
  }
  return dp[p][r][f] = res;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &k, &m);
  pw[0] = 1;
  for (int i = 1; i <= (n); ++i) pw[i] = (pw[i - 1] * 10) % k;
  memset(dp, -1, sizeof(dp));
  printf("%I64d\n", Solve(n, 0, 0));
  return 0;
}
