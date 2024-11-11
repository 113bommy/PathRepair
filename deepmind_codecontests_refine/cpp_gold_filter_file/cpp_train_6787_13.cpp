#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  int n, m;
  cin >> n >> m;
  if (n < m) swap(n, m);
  vector<long long> dp(n + 3);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i <= n; ++i) {
    dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
  }
  cout << (2 * dp[n] + 2 * dp[m] - 2 + mod) % mod;
  return 0;
}
