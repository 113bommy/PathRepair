#include <bits/stdc++.h>
using namespace std;
const long long MXN = 3e5 + 1;
const long long MNN = 5e3 + 1;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long double EPS = 1e-9;
long long n, m, k;
long long sums[MXN];
long long dp[MNN][MNN];
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (long long i = 1; i <= n; i++) {
    long long a;
    scanf("%I64d", &a);
    sums[i] = sums[i - 1] + a;
  }
  for (long long i = 1; i <= k; i++) {
    for (long long j = 1; j <= n; j++) {
      if (i * m > j) {
        dp[i][j] = 0;
      } else {
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + sums[j] - sums[j - m]);
      }
    }
  }
  printf("%I64d", dp[k][n]);
  return 0;
}
