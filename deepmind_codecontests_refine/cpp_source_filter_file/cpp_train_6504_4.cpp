#include <bits/stdc++.h>
using namespace std;
int n, a[105], dp[105] = {0}, ans = 0;
int dfs(int x) {
  if (2 * x >= n + 1) return 0;
  dp[x] = max(dfs(2 * x) + a[2 * x - 1], dfs(2 * x + 1) + a[2 * x]);
  return dp[x];
}
void dfs2(int x, int v) {
  if (2 * x >= n + 1) return;
  int l = v - dp[2 * x], r = v - dp[2 * x + 1];
  ans += l - a[2 * x - 1];
  ans += r - a[2 * x];
  dfs2(2 * x, v - l);
  dfs2(2 * x + 1, v - r);
}
int main() {
  scanf("%d", &n);
  n = (1 << (n + 1)) - 2;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int ml = dfs(1);
  dfs2(1, ml);
  printf("%d\n", ans);
  return 0;
}
