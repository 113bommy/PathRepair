#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long cp1[102];
long long cp2[102];
long long dp[102][10002];
long long comb[102][102];
bool mark[102][10002];
long long Calculate_Pow(long long x, long long y) {
  long long val = 1;
  for (long long i = 1, t = x; i <= y; i <<= 1, t = (t * t) % 1000000007)
    if (y & i) val = (val * t) % 1000000007;
  return val;
}
void Calculate_Combination() {
  for (long long i = 0; i <= n; i++) comb[i][0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= i; j++)
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % 1000000007;
}
long long f(long long col, long long last) {
  if (last < 0) return 0;
  if (col == n && last) return 0;
  if (col == n) return 1;
  if (mark[col][last]) return dp[col][last];
  mark[col][last] = true;
  if (col >= m % n) {
    for (long long i = 0; i <= n; i++)
      dp[col][last] =
          (dp[col][last] + cp1[i] * f(col + 1, last - i)) % 1000000007;
  } else {
    for (long long i = 0; i <= n; i++)
      dp[col][last] =
          (dp[col][last] + cp2[i] * f(col + 1, last - i)) % 1000000007;
  }
  return dp[col][last];
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  Calculate_Combination();
  for (long long i = 0; i <= n; i++) {
    cp1[i] = Calculate_Pow(comb[n][i], m / n);
    cp2[i] = Calculate_Pow(comb[n][i], m / n + 1);
  }
  printf("%I64d\n", f(0, k));
  return 0;
}
