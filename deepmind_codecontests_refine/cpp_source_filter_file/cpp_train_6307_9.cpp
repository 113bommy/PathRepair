#include <bits/stdc++.h>
using namespace std;
const int maxn = 7050;
int dp[2][maxn];
vector<int> g[2];
int state[2][maxn];
void dfs(int player, int cur, int n) {
  if (state[player][cur] == 1) return;
  state[player][cur] = 1;
  for (int i = 0; i < g[player].size(); i++) {
    int v = (cur + g[player][i]) % n;
    if (v == 0) {
      dp[player][cur] = 1;
      return;
    }
  }
  int cnt = 0;
  for (int i = 0; i < g[player].size(); i++) {
    int v = (cur + g[player][i]) % n;
    dfs(player ^ 1, v, n);
    if (dp[player ^ 1][v] == (-1)) {
      dp[player][cur] = 1;
      return;
    }
    if (dp[player ^ 1][v] == 1) {
      cnt++;
    }
  }
  if (cnt == g[player].size()) dp[player][cur] = (-1);
  return;
}
void WORK(int n) {
  for (int i = 0; i <= n; i++) dp[0][i] = dp[1][i] = 2;
  for (int k = 1; k <= 5; k++) {
    memset(state, 0, sizeof(state));
    for (int i = 1; i <= n; i++) {
      dfs(0, i % n, n);
      dfs(1, i % n, n);
    }
  }
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < 2; i++) {
      g[i].clear();
      int cnt;
      scanf("%d", &cnt);
      while (cnt--) {
        int x;
        scanf("%d", &x);
        g[i].push_back(x);
      }
    }
    WORK(n);
    for (int i = 0; i < 2; i++) {
      for (int j = 1; j < n; j++) {
        if (dp[i][j] == 1)
          printf("Win ");
        else if (dp[i][j] == (-1))
          printf("Lose ");
        else
          printf("Loop ");
      }
      printf("\n");
    }
  }
  return 0;
}
