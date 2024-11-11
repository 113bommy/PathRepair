#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int MOD = 998244353;
int n, col, ans, m;
int c[1000005], p[N], a[N], mn[N], mx[N];
int dp[N][N], sm[N][N];
vector<int> hv[N];
int dfs(int x, int y) {
  int C = sm[x][y];
  if (dp[x][y] != -1) return dp[x][y];
  if (x > y) return dp[x][y] = 0;
  if (mn[C] < x || mx[C] > y) return dp[x][y] = 0;
  if (x == y) return dp[x][y] = 1;
  dp[x][y] = 0;
  int lft = (x != mn[C]) ? 2ll * dfs(x, mn[C] - 1) : 1,
      rht = (y != mx[C]) ? 2ll * dfs(mx[C] + 1, y) : 1;
  for (int i = x + 1; i <= mn[C] - 1; i++)
    lft = (1ll * lft + 1ll * dfs(i, mn[C] - 1) * dfs(x, i - 1) % MOD) % MOD;
  for (int i = mx[C] + 1; i <= y - 1; i++)
    rht = (1ll * rht + 1ll * dfs(mx[C] + 1, i) * dfs(i + 1, y) % MOD) % MOD;
  ans = (1ll * lft * rht) % MOD;
  for (int i = 1; i < hv[C].size(); i++)
    ans = (1ll * ans * dfs(hv[C][i - 1] + 1, hv[C][i] - 1)) % MOD;
  return dp[x][y] = ans;
}
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dp[i][j] = -1;
  scanf("%d%d", &col, &n);
  for (int i = 1; i <= col; i++) mn[i] = n + 1;
  for (int i = 1; i <= n; i++) scanf("%d", c + i);
  for (int i = 1; i <= n; i++) {
    if (i == 0 || c[i] != c[i - 1]) a[++m] = c[i];
    if (m > 1000) {
      puts("0");
      return 0;
    }
  }
  for (int i = 1; i <= m; i++) {
    mn[a[i]] = min(mn[a[i]], i);
    mx[a[i]] = max(mx[a[i]], i);
    hv[a[i]].push_back(i);
    int MN = a[i];
    for (int j = i; j <= m; j++) {
      MN = min(MN, a[j]);
      sm[i][j] = MN;
    }
  }
  printf("%d\n", dfs(1, m));
  return 0;
}
