#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 4e3 + 1;
long long dp[MAXN][MAXN];
int g[MAXN][2];
int siz[MAXN];
int a[MAXN], n;
int root;
int m;
int solve(int l, int r) {
  if (l > r) return 0;
  int mn = l;
  for (int i = l; i <= r; ++i)
    if (a[i] < a[mn]) mn = i;
  g[mn][0] = solve(l, mn - 1);
  g[mn][1] = solve(mn + 1, r);
  return mn;
}
void dfs(int now) {
  if (g[now][0] == 0 && g[now][1] == 0) {
    siz[now] = 1;
    dp[now][1] = 1ll * (m - 1) * a[now];
    dp[now][0] = 0;
    return;
  }
  if (g[now][0] == 0) {
    dfs(g[now][1]);
    for (int j = 0; j <= n; ++j) dp[now][j] = dp[g[now][1]][j];
    siz[now] = siz[g[now][1]] + 1;
  } else if (g[now][1] == 0) {
    dfs(g[now][0]);
    for (int j = 0; j <= n; ++j) dp[now][j] = dp[g[now][0]][j];
    siz[now] = siz[g[now][0]] + 1;
  } else {
    dfs(g[now][0]);
    dfs(g[now][1]);
    siz[now] = siz[g[now][0]] + siz[g[now][1]] + 1;
    for (int j = 0; j <= siz[g[now][0]]; ++j)
      for (int k = 0; k <= siz[g[now][1]]; ++k) {
        dp[now][j + k] =
            max(dp[now][j + k],
                dp[g[now][0]][j] + dp[g[now][1]][k] - 2ll * j * k * a[now]);
      }
  }
  for (int i = siz[now]; i >= 1; --i) {
    dp[now][i] = max(dp[now][i], dp[now][i - 1] - 2ll * (i - 1) * a[now] +
                                     1ll * (m - 1) * a[now]);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= n; ++j) dp[i][j] = -1e18;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  root = solve(1, n);
  dfs(root);
  cout << dp[root][m] << endl;
  return 0;
}
