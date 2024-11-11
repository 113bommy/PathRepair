#include <bits/stdc++.h>
using namespace std;
long long dp[262149][20];
long long kt[20];
long long s[20][20];
long long solve(long long mask, long long pr, long long n, long long t,
                long long u) {
  if (t == n) {
    return ((long long)0);
  }
  if (dp[mask][pr] != -1) {
    return dp[mask][pr];
  }
  dp[mask][pr] = 0;
  long long nmask;
  for (long long i = 0; i < u; i++) {
    if ((mask & (1 << i)) == 0) {
      nmask = mask + (1 << i);
      dp[mask][pr] =
          max(dp[mask][pr], s[pr][i] + kt[i] + solve(nmask, i, n, t + 1, u));
    }
  }
  return dp[mask][pr];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    long long n, m, k, x, y, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
      cin >> kt[i];
    }
    for (int i = 1; i <= k; i++) {
      cin >> x >> y >> c;
      s[x - 1][y - 1] = c;
    }
    long long ans = INT_MIN;
    long long nm = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, kt[i] + solve(nm + (1 << i), i, m, 1, n));
    }
    cout << ans << endl;
  }
}
