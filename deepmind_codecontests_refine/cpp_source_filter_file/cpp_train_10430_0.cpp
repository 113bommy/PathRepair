#include <bits/stdc++.h>
using namespace std;
const long long N = 5000, mod = 998244353;
long long n, a[N], dp[N][N], k;
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  a[n] = a[0];
  long long c = 2300;
  if (a[0] == a[1])
    dp[0][c] = k;
  else {
    dp[0][c + 1] = 1;
    dp[0][c - 1] = 1;
    dp[0][c] = k - 2;
  }
  for (long long i = 1; i < n; ++i) {
    for (long long j = 1; j < 3000; ++j) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) * (a[i] != a[i + 1]);
      if (a[i] != a[i + 1])
        dp[i][j] += dp[i - 1][j] * (k - 2);
      else
        dp[i][j] += dp[i - 1][j] * k;
      dp[i][j] %= mod;
    }
  }
  long long res = 0;
  for (long long i = c + 1; i < N; ++i) {
    res += dp[n - 1][i];
    res %= mod;
  }
  cout << res;
}
