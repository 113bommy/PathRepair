#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int mod = 1e9 + 7;
const int N = 2005;
int n, k;
ll dp[N][N];
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) dp[i][1] = 1;
  for (int i = 2; i <= k; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int l = j; l <= n; l += j) {
        dp[j][i] += dp[l][i - 1] % mod;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp[i][k];
  }
  cout << ans % mod << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
