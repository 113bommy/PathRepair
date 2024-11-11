#include <bits/stdc++.h>
using namespace std;
inline int ReadInt() {
  int o = 0, ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) o = o * 10 + ch - '0', ch = getchar();
  return o;
}
int n, b, q, c[5000 + 10], d[5000 + 10], sz[5000 + 10],
    dp[5000 + 10][5000 + 10][2];
vector<int> g[5000 + 10];
void dfs(int u) {
  dp[u][0][0] = 0;
  dp[u][1][0] = c[u];
  dp[u][1][1] = c[u] - d[u];
  sz[u] = 1;
  for (auto v : g[u]) {
    dfs(v);
    for (int i = sz[u]; i >= 0; i--) {
      for (int j = sz[v]; j >= 0; j--) {
        dp[u][i + j][0] = min(dp[u][i + j][0], dp[u][i][0] + dp[v][j][0]);
        dp[u][i + j][1] =
            min(dp[u][i + j][1], dp[u][i][1] + min(dp[v][j][0], dp[v][j][1]));
      }
    }
    sz[u] += sz[v];
  }
}
int main() {
  while (~scanf("%d%d", &n, &b)) {
    for (int i = 0; i <= n; i++) g[i].clear();
    memset(dp, 60, sizeof(dp));
    for (int i = 1, x; i <= n; i++) {
      c[i] = ReadInt();
      d[i] = ReadInt();
      if (i >= 2) {
        x = ReadInt();
        g[x].push_back(i);
      }
    }
    dfs(1);
    int ans;
    for (int i = 0; i <= n; i++)
      if (min(dp[1][i][1], dp[1][i][0]) <= b) ans = i;
    printf("%d\n", ans);
  }
  return 0;
}
