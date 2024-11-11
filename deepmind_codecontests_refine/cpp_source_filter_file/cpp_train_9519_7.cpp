#include <bits/stdc++.h>
using namespace std;
int dp[100001];
int c, d, n, m, k;
int solve(int x) {
  for (int i = 0; i <= x; i++) {
    if (i - n < 0 && i - 1 < 0)
      dp[i] = min(c, d);
    else if (i - n < 0)
      dp[i] = min(c, dp[i - 1] + d);
    else
      dp[i] = min(dp[i - n] + c, dp[i - 1] + d);
  }
  return dp[x];
}
int main() {
  cin >> c >> d;
  cin >> n >> m;
  cin >> k;
  int ans = 0;
  if (k >= n * m)
    ans = 0;
  else {
    int a = n * m - k;
    ans += solve(a);
  }
  cout << ans;
}
