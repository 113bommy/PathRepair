#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
inline void smax(int &x, int y) { x = max(x, y); }
inline void smin(int &x, int y) { x = min(x, y); }
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
vector<vector<ll> > dp;
ll ps0, ps1, ps2;
ll solve(int n, int m) {
  if (n == -1) {
    if (m == 0) return 1;
    return 0;
  }
  if (dp[n][m] != -1) return dp[n][m];
  if (m == 1) {
    dp[n][m] = (solve(n - 1, 1) * ps0) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 0) * ps1) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 2) * ps2) % 1000000007;
  } else if (m == 2) {
    dp[n][m] = (solve(n - 1, 2) * ps0) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 1) * ps1) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 0) * ps2) % 1000000007;
  } else {
    dp[n][m] = (solve(n - 1, 0) * ps0) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 2) * ps1) % 1000000007;
    dp[n][m] = (dp[n][m] + solve(n - 1, 1) * ps2) % 1000000007;
  }
  return dp[n][m];
}
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r;
  cin >> n >> l >> r;
  dp.resize(n, vector<ll>(3, -1));
  ps0 = r / 3 - (l - 1) / 3;
  ps1 = (r - 1) / 3 - floor((l - 2) / 3.0);
  ps2 = floor((r - 2) / 3.0) - floor((l - 3) / 3.0);
  cout << solve(n - 1, 0);
}
