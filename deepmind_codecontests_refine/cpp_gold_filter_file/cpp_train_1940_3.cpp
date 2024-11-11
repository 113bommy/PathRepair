#include <bits/stdc++.h>
using namespace std;
long long dp[505][505][2], n;
const long long MO = 1000000007;
bool mp[505][505];
int main() {
  scanf("%lld", &n);
  long long a;
  for (long long i = 1; i <= n; i++) {
    dp[i][i][1] = 1;
    for (long long j = 1; j <= n; j++) {
      scanf("%lld", &a);
      mp[i][j] = a;
    }
  }
  for (long long l = 2; l <= n; l++)
    for (long long i = 1, j = i + l - 1; j <= n; i++, j++)
      for (long long k = i; k <= j - 1; k++) {
        long long a = dp[i][k][1], b = dp[k][j][0], c = dp[k][j][1];
        (dp[i][j][1] += mp[i][j] * (dp[i][k][0] + dp[i][k][1]) *
                        (dp[k + 1][j][0] + dp[k + 1][j][1])) %= MO;
        (dp[i][j][0] += a * (b + c)) %= MO;
      }
  printf("%lld", (dp[1][n][0] + dp[1][n][1]) % MO);
  return 0;
}
