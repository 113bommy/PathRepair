#include <bits/stdc++.h>
using namespace std;
vector<int> e[100010];
int d[100010];
int dp[100010][2];
int ans;
void update(int v, int max_val[2]) {
  if (v > max_val[0]) {
    max_val[1] = max_val[0];
    max_val[0] = v;
  } else if (v > max_val[1]) {
    max_val[1] = v;
  }
}
void dfs(int fa, int x) {
  int max_son[2][2] = {0, 0, 0, 0};
  dp[x][1] = 1;
  for (int y : e[x]) {
    if (y == fa) continue;
    dfs(x, y);
    dp[x][1] = max(dp[x][1], dp[y][0] + 1);
    dp[x][0] = max(dp[x][0], dp[y][0] + d[x] - 1);
    dp[x][0] = max(dp[x][0], dp[y][1] + d[x] - 1);
    update(dp[y][0], max_son[0]);
    update(max(dp[y][0], dp[y][1]), max_son[1]);
  }
  ans = max(ans, max_son[0][0] + max_son[0][1] + 1);
  ans = max(ans, max_son[1][0] + max_son[1][1] + d[x] - 2 + (fa == 0) ? 0 : 1);
  ans = max(ans, max_son[1][0] + d[x] - 1 + (fa == 0) ? 0 : 1);
}
int main() {
  int n, x, y, i;
  scanf("%d", &n);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    e[x].push_back(y);
    e[y].push_back(x);
    d[x]++;
    d[y]++;
  }
  for (i = 1; i <= n; i++) d[i]--;
  d[1]++;
  dfs(0, 1);
  printf("%d\n", ans);
  return 0;
}
