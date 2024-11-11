#include <bits/stdc++.h>
using namespace std;
long long dp[2005][2005];
int t[2005];
long long c[2005];
int n, m, b;
long long mod;
long long solve(int index, long long time) {
  if (time >= n) return 0;
  if (index == n) return LONG_MAX;
  if (dp[index][time] == -1)
    dp[index][time] = min(solve(index + 1, time),
                          solve(index + 1, time + t[index]) + c[index]);
  return dp[index][time];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t[i] >> c[i];
    t[i]++;
  }
  memset(dp, -1, sizeof(dp));
  cout << solve(0, 0);
  return 0;
}
