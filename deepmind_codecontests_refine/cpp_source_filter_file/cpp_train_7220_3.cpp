#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, v;
};
vector<node> q[3005];
int dp[3005][2];
int cost[3005];
int ss;
int min(int a, int b) { return a < b ? a : b; }
void dfs(int x, int f, int w, int sum) {
  if (f == -1) {
    dp[x][0] = 0;
    dp[x][1] = 0;
  } else {
    dp[x][0] = dp[f][0] + w;
    dp[x][1] = min(dp[f][0], dp[f][1]) + w ^ 1;
  }
  cost[x] = sum;
  int i;
  for (i = 0; i < q[x].size(); i++) {
    node z = q[x][i];
    int j = z.x;
    if (j == f) continue;
    dfs(j, x, z.v, sum + z.v);
    ss += z.v;
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int i;
    for (i = 1; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      node z;
      z.x = b;
      z.v = 0;
      q[a].push_back(z);
      z.x = a;
      z.v = 1;
      q[b].push_back(z);
    }
    int ans = 1000000000;
    for (i = 1; i <= n; i++) {
      ss = 0;
      dfs(i, -1, 0, 0);
      for (int j = 1; j <= n; j++) {
        ans = min(ans, ss + min(dp[j][0], dp[j][1]) - cost[j]);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
