#include <bits/stdc++.h>
using namespace std;
int dp[2005][2005];
const int mod = 1000000007;
int main() {
  int n, l;
  cin >> n >> l;
  for (int i = 1; i <= n; ++i) dp[1][i] = 1;
  for (int i = 1; i < l; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k = j; k <= n; k += j) {
        dp[i + 1][k] += dp[i][j];
        dp[i + 1][k] %= mod;
      }
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += dp[l][i];
    cnt %= mod;
  }
  cout << cnt;
  return 0;
}
