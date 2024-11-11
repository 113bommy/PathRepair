#include <bits/stdc++.h>
using namespace std;
long long mod;
long long add(long long x, long long y) {
  return x + y - (x + y >= mod ? mod : 0);
}
void addTo(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
}
long long mul(long long x, long long y) { return (x * y) % mod; }
signed main() {
  long long n;
  cin >> n >> mod;
  vector<long long> dp(n + 1), df(n + 1);
  long long all = 0, sum = 0, prv = 1;
  for (long long i{1}; i <= n; ++i) {
    addTo(sum, df[i]);
    dp[i] = add(prv, sum);
    addTo(all, dp[i]);
    prv = all;
    for (long long j{2}; i * j <= n; ++j) {
      addTo(df[i * j], dp[i]);
      if ((i + 1) * j <= n) addTo(df[(i + 1) * j], -dp[i]);
    };
  }
  cout << dp[n] << '\n';
  return 0;
}
