#include <bits/stdc++.h>
using namespace std;
const long long int mx = 2e3 + 10;
long long int dp[mx][mx];
const long long int mod = 1e9 + 7;
int main() {
  long long int n, k;
  cin >> n >> k;
  dp[0][1] = 1;
  for (long long int len = 1; len <= k; len++) {
    for (long long int i = 1; i <= n; i++) {
      for (long long int j = i; j <= n; j += i) {
        dp[len][j] = (dp[len][j] + dp[len - 1][i]) % mod;
      }
    }
  }
  long long int res = 0;
  for (long long int i = 1; i <= n; i++) res = (res + dp[k][i]) % mod;
  cout << res << endl;
  return 0;
}
