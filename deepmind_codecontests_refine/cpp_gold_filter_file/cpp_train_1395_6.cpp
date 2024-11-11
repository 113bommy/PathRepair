#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long powmod(long long a, long long p) {
  if (p == 0) return 1;
  long long c = powmod(a, p / 2);
  if (p & 1) return (c * c) % mod * a % mod;
  return (c * c) % mod;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  string s;
  cin >> s;
  long long n = s.length();
  reverse(s.begin(), s.end());
  long long dp[n + 1];
  if (s[0] == '1')
    dp[1] = 1;
  else
    dp[1] = 0;
  for (long long i = 1; i < n; i++) {
    if (s[i] == '1')
      dp[i + 1] = ((dp[i] * 2) % mod + powmod(2, 2 * i)) % mod;
    else
      dp[i + 1] = (2 * dp[i]) % mod;
  }
  cout << dp[n];
}
