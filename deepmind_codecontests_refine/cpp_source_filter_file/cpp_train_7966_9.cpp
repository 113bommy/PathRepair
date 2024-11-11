#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 3e5 + 30;
long long n, m, k;
long long dp[N], s[N];
signed main() {
  cin >> n >> m;
  dp[0] = 1;
  for (long long i = 1; i <= n; i++) {
    dp[i] = m * (dp[i - 1] * 2 - s[i - 1]) % mod;
    s[i] = (s[i - 1] * (m - 1) + dp[i]) % mod;
  }
  cout << (dp[n] + mod) % mod << endl;
  return 0;
}
