#include <bits/stdc++.h>
using namespace std;
const long long N = 205;
long long beauty[N], dp[N][N][N];
bool vis[N][N][N];
long long n, k, x;
long long dp1(long long pos, long long rep, long long unr) {
  if (pos == n + 1) return 0;
  if (vis[pos][rep][unr]) return dp[pos][rep][unr];
  vis[pos][rep][unr] = 1;
  if (rep == x) {
    if (pos + k < n) {
      dp[pos][rep][unr] = -((long long)(2e18));
      return -((long long)(2e18));
    }
    return 0;
  }
  if (unr == k) {
    dp[pos][rep][unr] = (beauty[pos] + dp1(pos + 1, rep + 1, 0));
    return dp[pos][rep][unr];
  }
  dp[pos][rep][unr] =
      max(dp1(pos + 1, rep, unr + 1), dp1(pos + 1, rep + 1, 0) + beauty[pos]);
  return dp[pos][rep][unr];
}
bool bad() {
  long long t = -1;
  for (long long i = 0; i <= x; i++) t += k;
  return (t < n);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> x;
  for (long long i = 1; i <= n; i++) cin >> beauty[i];
  if (bad())
    cout << -1;
  else
    cout << dp1(1, 0, 0);
  return 0;
}
