#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long dp[100005];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  if (n * m == 1) {
    cout << 2 << '\n';
    return 0;
  }
  dp[0] = 1;
  dp[1] = 2;
  for (long long i = 2; i < max(m, n); i++) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  }
  cout << ((dp[n - 1] + dp[m - 1] - 1) * 2) % MOD << '\n';
  return 0;
}
