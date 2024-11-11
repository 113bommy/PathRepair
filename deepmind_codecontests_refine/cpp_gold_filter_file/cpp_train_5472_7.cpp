#include <bits/stdc++.h>
using namespace std;
int n;
int dp[30000010], sum[4010];
int Hash(int a, int b, int c, int d) {
  return ((((a * 4000ll) + b) * 100 + c) * 2 + d) % (29999995);
}
int dfs(int x, int y, int k, int now) {
  if (y - x + 1 < k) return 0;
  if (y - x + 1 == k) return ((sum[y] - sum[x - 1])) * (now ? -1 : 1);
  int num = Hash(x, y, k, now);
  if (~dp[num]) return dp[num];
  int ans = 0;
  if (now) {
    ans = dfs(x, y - k, k, 0) - (sum[y] - sum[y - k + 1 - 1]);
    if (x <= y - k)
      ans = min(ans, dfs(x, y - k - 1, k + 1, 0) - (sum[y] - sum[y - k - 1]));
    return dp[num] = ans;
  } else {
    ans = dfs(x + k, y, k, 1) + (sum[x + k - 1] - sum[x - 1]);
    if (x + k <= y)
      ans = max(ans, dfs(x + k + 1, y, k + 1, 1) + (sum[x + k] - sum[x - 1]));
    return dp[num] = ans;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i <= n; ++i) cin >> sum[i], sum[i] += sum[i - 1];
  cout << dfs(1, n, 1, 0);
  return 0;
}
