#include <bits/stdc++.h>
long long dp[100][2][2];
int ll, rr;
long long dfs(int x, int l, int r) {
  if (x < 0) return 1;
  if (dp[x][l][r] != -1) return dp[x][l][r];
  dp[x][l][r] = 0;
  int xl, xr;
  if (l == 0)
    xl = (ll >> x) & 1;
  else
    xl = 1;
  if (r == 0)
    xr = (rr >> x) & 1;
  else
    xr = 1;
  for (int i = 0; i <= xl; i++)
    for (int j = 0; j <= xr; j++) {
      if (i == 1 && j == 1) continue;
      dp[x][l][r] += dfs(x - 1, l | ((1 - i) && ((1LL * ll >> x) & 1)),
                         r | ((1 - j) && ((1LL * rr >> x) & 1)));
    }
  return dp[x][l][r];
}
long long fun(int l, int r) {
  if (l < 0 || r < 0) return 0;
  memset(dp, -1, sizeof(dp));
  ll = l, rr = r;
  return dfs(31, 0, 0);
}
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    int l, r;
    scanf("%d%d", &l, &r);
    long long ans = fun(r, r) - 2LL * fun(l - 1, r) + fun(l - 1, l - 1);
    printf("%lld\n", ans);
  }
}
