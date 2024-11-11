#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
long long n, a, b, k;
long long dp[5010][5010], sum[5010][2];
int main() {
  cin >> n >> a >> b >> k;
  a--;
  b--;
  n--;
  if (b < a) {
    a -= b;
    n -= b;
  } else {
    n = b;
    a = n - a;
  }
  b = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 1;
    sum[i][0] = sum[i - 1][0] + dp[i][0];
  }
  for (long long j = 1; j <= k; j++) {
    for (long long i = 1; i <= n; i++) {
      dp[i][j] =
          (sum[min(2 * i - 1, n)][1 - (j % 2)] - dp[i][j - 1] + mod) % mod;
      sum[i][j % 2] = (sum[i - 1][j % 2] + dp[i][j]) % mod;
    }
  }
  cout << dp[a][k] << endl;
  return 0;
}
