#include <bits/stdc++.h>
using namespace std;
long long dp[1005] = {0};
long long MOD = 1000000007;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, p;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> p;
    dp[i + 1] = (2 % MOD + dp[i + 1] % MOD) % MOD;
    dp[i + 1] = (dp[i] % MOD + dp[i + 1] % MOD) % MOD;
    dp[i + 1] = (dp[i] % MOD + dp[i + 1] % MOD) % MOD;
    dp[i + 1] = (dp[i + 1] % MOD - dp[p] % MOD + MOD) % MOD;
  }
  cout << dp[n + 1] << endl;
  return 0;
}
