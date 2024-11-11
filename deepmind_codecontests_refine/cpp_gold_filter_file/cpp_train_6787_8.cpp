#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> dp(100100, 0);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < 100100; ++i) dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  cout << ((2ll * (dp[n] + dp[m])) % mod - 2ll + mod) % mod;
  return 0;
}
