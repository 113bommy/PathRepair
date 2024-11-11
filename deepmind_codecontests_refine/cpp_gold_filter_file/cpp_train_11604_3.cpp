#include <bits/stdc++.h>
using namespace std;
vector<int> edge[100005];
long long dp[100005][2];
int c[100005], n;
void dfs(int u) {
  dp[u][0] = 1;
  dp[u][1] = 0;
  for (unsigned int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    dfs(v);
    dp[u][1] = dp[u][1] * dp[v][0] + dp[u][0] * dp[v][1];
    dp[u][1] %= (1000000000 + 7);
    dp[u][0] *= dp[v][0];
    dp[u][0] %= (1000000000 + 7);
  }
  if (c[u])
    dp[u][1] = dp[u][0];
  else {
    dp[u][0] += dp[u][1];
    dp[u][0] %= (1000000000 + 7);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int p;
    scanf("%d", &p);
    edge[p].push_back(i);
  }
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  dfs(0);
  printf("%I64d\n", dp[0][1]);
  return 0;
}
