#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9, OO = 0x3f3f3f3f, mod = 1000000007;
int n, a[N], dp[N][2];
int solve(int idx = 0, int part = 0) {
  if (idx == n) {
    if (part)
      return 0;
    else
      return -1 * OO;
  }
  if (dp[idx][part] != -1) return dp[idx][part];
  return dp[idx][part] =
             max(solve(idx + 1, part),
                 solve(idx + 1, ((part & 1) + (a[idx] & 1)) & 1) + a[idx]);
}
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  cout << solve();
  return 0;
}
