#include <bits/stdc++.h>
const long long MOD = 1000000007;
int n;
int x[105], y[105];
long long c[101][101];
long long s[105];
long long dp[105][1005];
void init() {
  c[0][0] = 1;
  for (int i = 1; i <= 100; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}
void update(long long& ret, long long v) { ret = (ret + v) % MOD; }
int main() {
  init();
  scanf("%d", &n);
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    s[i] = s[i - 1] + x[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", &y[i]);
  }
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= s[i]; j++) {
      if (dp[i][j] != 0) {
        int t = s[i + 1] - j;
        for (int k = j; k <= s[i + 1] && k - j <= y[i + 1]; k++) {
          update(dp[i + 1][k], dp[i][j] * c[t][k - j]);
        }
      }
    }
  }
  int sum = s[n];
  long long res = dp[n][sum];
  for (int i = 1; i <= n; i++) {
    res = res * c[sum][x[i]] % MOD;
    sum -= x[i];
  }
  printf("%lld\n", res);
  return 0;
}
