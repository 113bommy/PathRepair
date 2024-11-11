#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
const int mod = 1e9 + 7;
int dp[N][N << 2][2];
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> v(n + 1);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].emplace_back(y);
    v[y].emplace_back(x);
  }
  vector<int> fa(n + 1), sz(n + 1, 1);
  iota(fa.begin(), fa.end(), 0);
  function<int(int)> find = [&](int n) {
    return fa[n] == n ? fa[n] : fa[n] = find(fa[n]);
  };
  for (int x = 1; x <= n; x++) {
    for (auto y : v[x]) {
      if (x == 1 || y == 1) continue;
      int fax = find(x), fay = find(y);
      if (fax == fay) continue;
      fa[fax] = fay;
      sz[fay] += sz[fax];
    }
  }
  vector<int> cyc(n + 1, 0);
  for (int i = 2; i <= n; i++)
    if (fa[i] == i) cyc[sz[i] + 1]++;
  vector<int> a(n + 1);
  auto Dp = [&](int len) {
    int cnt = 0, sum = 0;
    for (int i = 2; i <= n; i++)
      for (int j = 1; j <= cyc[i] - (i == len); j++) a[++cnt] = i, sum += i;
    for (int i = 0; i <= cnt; i++)
      for (int j = -sum; j <= sum; j++)
        for (int k = 0; k <= 1; k++) dp[i][j + sum][k] = 0;
    dp[0][0 + sum][1] = 1;
    for (int i = 0; i < cnt; i++) {
      for (int j = -sum; j <= sum; j++) {
        for (int k = 0; k <= 1; k++) {
          int nj = j + sum;
          int val = dp[i][nj][k];
          if (nj + a[i + 1] <= (int)8e3) add(dp[i + 1][nj + a[i + 1]][k], val);
          if (nj - a[i + 1] >= 0) add(dp[i + 1][nj - a[i + 1]][k], val);
          add(dp[i + 1][nj][0], val);
        }
      }
    }
    if (!len) return dp[cnt][0 + sum][1];
    int ans = 0;
    for (int i = 1; i < len; i++) {
      int cf = len - 2 * i;
      if (cf < -sum || cf > sum) continue;
      add(ans, dp[cnt][cf + sum][0]);
      add(ans, dp[cnt][cf + sum][1]);
    }
    for (int i = 0; i < len; i++) {
      int cf = len - 2 * i - 1;
      if (cf < -sum || cf > sum) continue;
      if (i && i < len - 1) add(ans, dp[cnt][cf + sum][0]);
      add(ans, dp[cnt][cf + sum][1]);
    }
    ans = ans * 2 % mod;
    return ans;
  };
  int ans = 0;
  for (int i = 2; i <= n; i++) {
    if (!cyc[i]) continue;
    add(ans, 1LL * Dp(i) * cyc[i] % mod);
  }
  add(ans, Dp(0));
  printf("%d\n", ans);
  return 0;
}
