#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 2001;
const long long BASE = 1000000007;
int n, m;
long long dp[MAXSIZE + 1][MAXSIZE + 1];
long long sum[MAXSIZE + 1][MAXSIZE + 1];
int main() {
  scanf("%d%d", &n, &m);
  for (int l = 1; l < m; l++) dp[1][l] = 1;
  for (int i = 2; i <= n; i++) {
    long long sum = 0;
    for (int j = 1; j < m; j++) {
      sum += (dp[i - 1][j]) % BASE;
      dp[i][j] = (dp[i][j - 1] + sum) % BASE;
    }
  }
  for (int j = 1; j < m; j++)
    for (int t = n - 1; t >= 0; t--)
      sum[n - t][j] = (sum[n - t - 1][j] + dp[n - t][j]) % BASE;
  long long ANS = 0;
  for (int t = 1; t <= n; t++) {
    for (int j = 1; j < m; j++) {
      long long count = (sum[n - t + 1][j] * (m - j)) % BASE;
      ANS = (ANS + dp[t][j] * count) % BASE;
    }
  }
  printf("%I64d", ANS);
  return 0;
}
