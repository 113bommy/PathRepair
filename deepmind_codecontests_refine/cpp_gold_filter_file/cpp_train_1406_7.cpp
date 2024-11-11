#include <bits/stdc++.h>
using namespace std;
int n, x, y;
vector<int> adj[5010];
int dp[5010][5010][2];
int leafs[5010];
int isleaf[5010];
int mem[5010][2];
int dp2[5010][2];
void dfs(int curr, int p) {
  for (int i = 0; i < adj[curr].size(); ++i) {
    int u = adj[curr][i];
    if (u != p) {
      dfs(u, curr);
      leafs[curr] += leafs[u];
    }
  }
  if (leafs[curr] == 0) {
    isleaf[curr] = 1;
    leafs[curr] = 1;
  }
}
void solve(int curr, int p) {
  int cnt = 0;
  for (int i = 0; i < adj[curr].size(); ++i) {
    int u = adj[curr][i];
    if (u == p) continue;
    cnt++;
    solve(u, curr);
  }
  if (cnt == 0) {
    dp[curr][0][0] = 0;
    dp[curr][1][1] = 0;
    return;
  }
  dp[curr][0][0] = 0;
  dp[curr][0][1] = cnt;
  for (int i = 0; i < adj[curr].size(); ++i) {
    int u = adj[curr][i];
    if (u == p) continue;
    for (int j = 0; j <= leafs[curr]; ++j) dp2[j][0] = dp2[j][1] = 0x3f3f3f3f;
    for (int j = 1; j <= leafs[u]; ++j) {
      for (int k = 0; k <= leafs[curr]; ++k)
        mem[k][0] = dp[curr][k][0], mem[k][1] = dp[curr][k][1];
      for (int k = leafs[curr] - j; k >= 0; --k) {
        mem[k + j][0] = min(mem[k + j][0], mem[k][0] + dp[u][j][0]);
        mem[k + j][0] = min(mem[k + j][0], mem[k][0] + dp[u][j][1] + 1);
        mem[k + j][1] = min(mem[k + j][1], mem[k][1] + dp[u][j][0]);
        mem[k + j][1] = min(mem[k + j][1], mem[k][1] + dp[u][j][1] - 1);
      }
      for (int k = 0; k <= leafs[curr]; ++k) {
        dp2[k][0] = min(dp2[k][0], mem[k][0]),
        dp2[k][1] = min(dp2[k][1], mem[k][1]);
      }
    }
    for (int j = 0; j <= leafs[curr]; ++j) {
      dp[curr][j][0] = min(dp[curr][j][0], dp2[j][0]);
      dp[curr][j][1] = min(dp[curr][j][1], dp2[j][1]);
    }
  }
}
int main(void) {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int st = 1;
  for (int i = 1; i <= n; ++i) {
    if (adj[i].size() != 1) st = i;
  }
  dfs(st, st);
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      dp[i][j][0] = dp[i][j][1] = 0x3f3f3f3f;
    }
  }
  solve(st, st);
  cout << min(dp[st][leafs[st] / 2][0], dp[st][leafs[st] / 2][1]) << "\n";
  return 0;
}
