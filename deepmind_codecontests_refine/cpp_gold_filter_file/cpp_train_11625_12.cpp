#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
long long ans;
int ne[N << 1], fi[N], zz[N << 1], tot, x, y, dp[N][25], T, n, Max[N],
    dp2[N][25];
void jb(int x, int y) {
  ne[++tot] = fi[x];
  fi[x] = tot;
  zz[tot] = y;
}
int cmp(int x, int y) { return dp[x][T] > dp[y][T]; }
void dfs(int x, int y) {
  Max[x] = 1;
  vector<int> v;
  for (int i = fi[x]; i; i = ne[i])
    if (zz[i] != y) {
      dfs(zz[i], x);
      Max[x] = max(Max[x], Max[zz[i]] + 1);
      v.push_back(zz[i]);
    }
  dp[x][0] = 1e9;
  ans += n - 1;
  for (int i = 1; i <= 20; i++) {
    T = i - 1;
    sort(v.begin(), v.end(), cmp);
    for (int j = 0; j < (int)v.size(); j++)
      if (dp[v[j]][i - 1] >= j + 1) dp[x][i] = j + 1;
    dp2[x][i] = dp[x][i];
    for (int j : v) dp2[x][i] = max(dp2[x][i], dp2[j][i]);
    if (dp2[x][i] > 1) ans += dp2[x][i] - 1;
  }
  ans += Max[x];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    jb(x, y);
    jb(y, x);
  }
  dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
