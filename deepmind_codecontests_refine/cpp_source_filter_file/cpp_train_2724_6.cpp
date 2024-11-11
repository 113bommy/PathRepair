#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int dp[110][110][2];
long long int rec(long long int n1, long long int n2, long long int k1,
                  long long int k2, long long int turn) {
  if (n1 == 0) {
    if (n2 <= k2) {
      return 1;
    }
    return 0;
  }
  if (n2 == 0) {
    if (n1 <= k1) {
      return 1;
    }
    return 0;
  }
  if (dp[n1][n2][turn] != -1) return dp[n1][n2][turn];
  long long int ans = 0;
  if (turn == 1) {
    for (long long int i = 1; i <= min(k1, n1); i++) {
      ans = (ans + rec(n1 - i, n2, k1, k2, 0)) % mod;
    }
  } else {
    for (long long int i = 1; i <= min(k2, n2); i++) {
      ans = (ans + rec(n1, n2 - i, k1, k2, 1)) % mod;
    }
  }
  return dp[n1][n2][turn] = ans % mod;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(dp, -1, sizeof(dp));
  long long int n, m, k1, k2;
  cin >> n >> m >> k1 >> k2;
  cout << (rec(n, m, k1, k2, 1) + rec(n, m, k1, k2, 0)) % mod;
  return 0;
}
