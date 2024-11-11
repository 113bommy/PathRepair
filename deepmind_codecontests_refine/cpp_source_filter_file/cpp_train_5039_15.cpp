#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int dp[100005][2][2];
int solve(int idx, int prf, int sf) {
  if (idx == n) return 0;
  int &ret = dp[idx][prf][sf];
  if (ret != -1) return ret;
  ret = 0;
  if (prf && !sf)
    ret =
        max(solve(idx + 1, 1, 0) - a[idx],
            max(solve(idx + 1, 0, 1) - a[idx], solve(idx + 1, 1, 1) + a[idx]));
  else if (!prf && sf)
    ret = solve(idx + 1, 0, 1) - a[idx];
  else
    ret = max(solve(idx + 1, 0, 1) + a[idx], solve(idx + 1, 1, 1) + a[idx]);
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  cout << solve(0, 1, 0) << endl;
  return 0;
}
