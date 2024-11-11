#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
long long mod = 1e9 + 7;
long long dp[N][2];
int main() {
  int n, m;
  cin >> n >> m;
  if (m > n) swap(n, m);
  dp[1][0] = dp[1][1] = dp[0][1] = dp[0][0] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % mod;
    dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % mod;
  }
  int ans = dp[n][0] + dp[n][1];
  ans %= mod;
  ans += (dp[m][0] + dp[m][1]) % mod;
  ans %= mod;
  cout << (ans - 2 + mod) % mod;
}
