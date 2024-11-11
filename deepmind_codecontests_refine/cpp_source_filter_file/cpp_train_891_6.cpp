#include <bits/stdc++.h>
using namespace std;
const long long inf = 1LL << 61;
const long long mod = 1000000007;
const int maxn = 7010;
int n;
bool vis[2][maxn];
vector<int> vec[2];
int dp[2][maxn];
int dfs(int idx, int m) {
  if (dp[idx][m]) return dp[idx][m];
  if (vis[idx][m]) return dp[idx][m];
  vis[idx][m] = true;
  int sum = 0;
  for (auto u : vec[idx]) {
    int v = (m + u) % n;
    if (v == 0) v = n;
    if (v == 1) {
      dp[idx][m] = 1;
      return dp[idx][m];
    }
    int t = dfs((idx + 1) % 2, v);
    if (t == -1) {
      dp[idx][m] = 1;
      return dp[idx][m];
    } else if (t == 1) {
      sum++;
    }
  }
  if (sum == (int)vec[idx].size()) {
    dp[idx][m] = -1;
  } else {
    dp[idx][m] = 0;
  }
  return dp[idx][m];
}
int main() {
  std::ios::sync_with_stdio(false);
  int k1, k2, s;
  scanf("%d", &n);
  scanf("%d", &k1);
  for (int i = 0; i < k1; i++) {
    scanf("%d", &s);
    vec[0].push_back(s);
  }
  scanf("%d", &k2);
  for (int i = 0; i < k2; i++) {
    scanf("%d", &s);
    vec[1].push_back(s);
  }
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < 5; i++) {
    memset(vis, 0, sizeof(vis));
    for (int j = 2; j <= n; j++) {
      dfs(0, j);
      dfs(1, j);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 2; j <= n; j++) {
      if (dp[i][j] == 1) {
        printf("Win");
      } else if (dp[i][j] == -1) {
        printf("Lose");
      } else {
        printf("Loop");
      }
      printf("%c", j == n ? '\n' : ' ');
    }
  }
  return 0;
}
