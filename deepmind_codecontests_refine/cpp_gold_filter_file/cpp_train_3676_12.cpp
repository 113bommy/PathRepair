#include <bits/stdc++.h>
using namespace std;
long long re() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int n, t;
long long dp[22][5][3][11][11];
vector<int> v;
long long dfs(int p, int pre, int pst, int t1, int t2) {
  if (t1 > t || t2 > t - 1) return 0;
  if (p > n) {
    if (t1 == t && t2 == t - 1) {
      return 1;
    } else
      return 0;
  }
  if (dp[p][pre][pst][t1][t2] != -1) return dp[p][pre][pst][t1][t2];
  long long ans = 0;
  for (int i = 1; i <= 4; i++) {
    if (i == pre) continue;
    ans += dfs(p + 1, i, i > pre ? 2 : 1, t1 + ((i < pre && pst == 2) ? 1 : 0),
               t2 + ((i > pre && pst == 1) ? 1 : 0));
  }
  return dp[p][pre][pst][t1][t2] = ans;
}
int main() {
  memset(dp, -1, sizeof(dp));
  n = re(), t = re();
  long long ans = 0;
  for (int i = 1; i <= 4; i++) {
    ans += dfs(2, i, 0, 0, 0);
  }
  cout << ans;
}
