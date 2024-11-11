#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e6 + 6, mod = 1e9 + 7;
long long n, ans, dp[mxn];
int main() {
  cin >> n;
  dp[1] = 1;
  dp[2] = 2;
  for (long long i = 3; i <= n; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + 1) % mod;
  }
  ans = (dp[n] + dp[n - 1]) % mod;
  cout << ans << endl;
  return 0;
}
