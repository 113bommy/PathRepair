#include <bits/stdc++.h>
using namespace std;
const long long maxn = 2e5 + 5;
long long n, a[maxn], dp[2][maxn], vis[2][maxn];
long long dfs(long long x, long long p) {
  if (x > n || x <= 0) return 0;
  if (vis[p][x] == 1) return -1e18 + 7;
  vis[p][x] = 1;
  if (p) {
    if (x + a[x] <= n && x + a[x] >= 0 && dp[p ^ 1][x + a[x]] != 0)
      return dp[p][x] = a[x] + dp[p ^ 1][x + a[x]];
    else
      return dp[p][x] = a[x] + dfs(x + a[x], p ^ 1);
  } else {
    if (x - a[x] <= n && x - a[x] >= 0 && dp[p ^ 1][x - a[x]] != 0)
      return dp[p][x] = a[x] + dp[p ^ 1][x - a[x]];
    else
      return dp[p][x] = a[x] + dfs(x - a[x], p ^ 1);
  }
}
int main() {
  cin >> n;
  for (int i = 2; i <= n; i++) cin >> a[i];
  for (int i = 2; i <= n; i++)
    if (!vis[0][i]) dfs(i, 0);
  for (int i = 1; i < n; i++) {
    if (dp[0][1 + i] < 0)
      cout << -1 << '\n';
    else
      cout << i + dp[0][1 + i] << '\n';
  }
  return 0;
}
