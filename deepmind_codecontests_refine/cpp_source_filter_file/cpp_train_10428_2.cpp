#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const long long N = 103;
long long dp[N][N];
int32_t main() {
  long long n, k;
  cin >> n >> k;
  long long a[n + 1];
  for (long long i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long pos = 0;
  long long ans = 0;
  for (long long diff = 1; diff <= 100000 / (k + 1); diff++) {
    dp[0][0] = 1;
    pos = 0;
    for (long long i = 1; i <= n; i++) {
      while (pos < i && a[i] - a[pos + 1] >= diff) pos++;
      dp[i][0] = 1;
      for (long long j = 1; j <= k; j++)
        dp[i][j] = (dp[i - 1][j] + dp[pos][j - 1]) % MOD;
    }
    ans = (ans + dp[n][k]) % MOD;
  }
  cout << ans << endl;
}
