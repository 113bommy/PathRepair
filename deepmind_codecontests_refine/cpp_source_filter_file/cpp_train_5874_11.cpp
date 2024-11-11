#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
char g[N][N];
int dp[N * N + 1];
int n, m, ans;
bool cycle;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
char a[4] = {'D', 'I', 'M', 'A'};
vector<int> edge[N * N + 1];
int dfs(int u) {
  if (cycle) return 0;
  dp[u] = -2;
  int ans = 0;
  for (int i = 0; i < edge[u].size(); i++) {
    int v = edge[u][i];
    if (dp[v] == -2) {
      cycle = true;
      return 0;
    }
    if (dp[v] == -1) dfs(v);
    ans = max(ans, dp[v]);
  }
  return dp[u] = ans + 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  memset(dp, -1, sizeof(dp));
  ans = 0;
  cycle = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if ((g[i][j] == 'D' && g[nx][ny] == 'I') ||
            (g[i][j] == 'I' && g[nx][ny] == 'M') ||
            (g[i][j] == 'M' && g[nx][ny] == 'A') ||
            (g[i][j] == 'A' && g[nx][ny] == 'D'))
          edge[i * n + j].push_back(nx * n + ny);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] == 'D') {
        ans = max(ans, dfs(i * n + j));
        if (cycle) {
          i = n;
          break;
        }
      }
    }
  }
  if (cycle)
    printf("Poor Inna!\n");
  else if (ans < 4)
    printf("Poor Dima!\n");
  else
    printf("%d\n", ans / 4);
  return 0;
}
