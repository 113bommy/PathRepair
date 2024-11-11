#include <bits/stdc++.h>
using namespace std;
int sum[4005], dp[30000005], n;
int h(int a, int b, int c, int d) {
  return ((((a * 4000ll) + b) * 100 + c) * 2 + d) % 20080601;
}
int dfs(int l, int r, int x, int k) {
  if (r - l + 1 < x) return 0;
  if (r - l + 1 == x) return (sum[r] - sum[l - 1]) * (k ? -1 : 1);
  int s = h(l, r, x, k);
  if (dp[s] != -1) return dp[s];
  int ans = 0;
  if (k) {
    ans = dfs(l, r - x, x, 0) - sum[r] + sum[r - x];
    if (l <= r - x)
      ans = min(ans, dfs(l, r - x - 1, x + 1, 0) - sum[r] + sum[r - x - 1]);
    return dp[s] = ans;
  } else {
    ans = dfs(l + x, r, x, 1) + sum[l + x - 1] - sum[l - 1];
    if (l + x <= r)
      ans = max(ans, dfs(l + x + 1, r, x + 1, 1) + sum[l + x] - sum[l - 1]);
    return dp[s] = ans;
  }
}
int main() {
  int i;
  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> sum[i];
    sum[i] += sum[i - 1];
  }
  cout << dfs(1, n, 1, 0) << endl;
  return 0;
}
