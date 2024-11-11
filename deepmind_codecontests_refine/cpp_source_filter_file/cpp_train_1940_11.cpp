#include <bits/stdc++.h>
using namespace std;
int n;
int adj[512][512];
long long int dp[512][512];
bool us[512][512];
long long int dp2[512][512];
bool us2[512][512];
long long int dfs(int lef, int rig);
inline long long int dfs2(int lef, int rig) {
  if (lef >= rig) return 1;
  if (us2[lef][rig]) {
    return dp2[lef][rig];
  }
  us2[lef][rig] = true;
  for (int j = rig; j > lef; j--) {
    dp2[lef][rig] += dfs(lef, j - 1) * dfs(j, rig);
    if (dp2[lef][rig] >= 9LL * 1000000007LL * 1000000007LL)
      dp2[lef][rig] -= 9LL * 1000000007LL * 1000000007LL;
  }
  if (dp2[lef][rig] >= 1000000007LL) dp2[lef][rig] %= 1000000007LL;
  return dp2[lef][rig];
}
inline long long int dfs(int lef, int rig) {
  if (us[lef][rig]) return dp[lef][rig];
  us[lef][rig] = true;
  if (lef == rig) {
    dp[lef][rig] = 1;
    return 1;
  }
  int cur = 0;
  for (int j = rig; j >= lef; j--) {
    if (adj[lef][j] == 0) continue;
    long long int ans1 = dfs2(lef, j) * dfs(j, rig);
    dp[lef][rig] += ans1;
    if (dp[lef][rig] >= 9LL * 1000000007LL * 1000000007LL)
      dp[lef][rig] -= 9LL * 1000000007LL * 1000000007LL;
  }
  if (dp[lef][rig] >= 1000000007LL) dp[lef][rig] %= 1000000007LL;
  return dp[lef][rig];
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }
  printf("%lld\n", dfs(0, n - 1));
  return 0;
}
