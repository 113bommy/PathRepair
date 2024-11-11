#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[2100], b[4410];
long long dp[2100][4410];
long long solve(int idx, int r) {
  if (idx == n) {
    if (r < 0)
      return 1e18;
    else
      return 0;
  }
  long long &ret = dp[idx][r + 2100];
  if (ret != -1) return ret;
  ret = 1e18;
  ret = min(ret, solve(idx + 1, min(r + a[idx], n)) + b[idx]);
  ret = min(ret, solve(idx + 1, r - 1));
  return ret;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  memset(dp, -1, sizeof dp);
  solve(0, 0);
  cout << dp[0][2100];
  return 0;
}
