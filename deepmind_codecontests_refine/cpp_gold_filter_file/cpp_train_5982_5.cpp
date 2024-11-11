#include <bits/stdc++.h>
using namespace std;
long long dp[100005][2];
int color[100005], par[100005];
bool notLeaf[100005];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", par + i);
    notLeaf[par[i]] = true;
  }
  for (int i = 0; i < n; i++) scanf("%d", color + i);
  for (int i = 0; i < n; i++) {
    dp[i][0] = 1;
    dp[i][1] = color[i];
  }
  for (int i = n - 1; i > 0; i--) {
    if (!notLeaf[i]) {
      dp[i][color[i]] = 1;
      dp[i][color[i] ^ 1] = 0;
    }
    if (color[par[i]] == 1) {
      dp[par[i]][1] *= dp[i][1] + dp[i][0];
      dp[par[i]][1] %= 1000000007LL;
      dp[par[i]][0] = 0;
    } else {
      dp[par[i]][1] *= dp[i][1] + dp[i][0];
      dp[par[i]][1] %= 1000000007LL;
      dp[par[i]][1] += dp[i][1] * dp[par[i]][0];
      dp[par[i]][1] %= 1000000007LL;
      dp[par[i]][0] *= dp[i][1] + dp[i][0];
      dp[par[i]][0] %= 1000000007LL;
    }
  }
  printf("%I64d\n", dp[0][1]);
  return 0;
}
