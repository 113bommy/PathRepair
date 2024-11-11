#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, k, l, u, v;
  long long bty = 0;
  vector<long long> G[100001];
  scanf("%d %d", &n, &m);
  for (i = 0; i < m; i++) {
    scanf("%d %d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  long long dp[100001] = {0};
  for (i = 1; i <= n; i++) {
    dp[i] = 1;
    for (j = 0; j < G[i].size(); j++) {
      if (i > G[i][j]) dp[i] = max(dp[i], dp[G[i][j]] + 1);
    }
    bty = max(bty, dp[i] * (long long)G[i].size());
  }
  printf("%d\n", bty);
  return (0);
}
