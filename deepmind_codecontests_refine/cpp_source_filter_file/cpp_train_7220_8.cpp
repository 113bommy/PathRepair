#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;
struct edge {
  int next, to, w;
} e[maxn * 2];
int head[maxn], len;
void add(int x, int y, int z) {
  e[++len] = {head[x], y, z};
  head[x] = len;
}
int i, j, k, n, m, ci[maxn], w, x, ans, root, vis[maxn], can;
void dfs(int now, int fa) {
  vis[now] = 1;
  for (int i = head[now]; i; i = e[i].next) {
    int u = e[i].to;
    if (u == fa) continue;
    if (vis[u])
      ci[now] = 1;
    else
      dfs(u, now);
    if (ci[u] == 1) ci[now] = 1;
    if (ci[now]) ++w, x += e[i].w;
  }
}
int dp[maxn][5][2];
void dfs2(int now, int fa) {
  dp[now][1][0] = 0;
  int tmp[5][2];
  for (int i = head[now]; i; i = e[i].next) {
    int u = e[i].to;
    if (u == fa) continue;
    dfs2(u, now);
    memset(tmp, 0x2f, sizeof(tmp));
    if (e[i].w == 1) {
      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= j; k++) {
          tmp[j][0] = min(
              tmp[j][0], dp[now][j - k][0] + min(dp[u][k + 1][0], dp[u][k][1]));
          tmp[j][1] =
              min(tmp[j][1],
                  min(dp[now][j - k + 1][0] + min(dp[u][k][0], dp[u][k][1]) + 1,
                      dp[now][j - k][1] + min(dp[u][k][0], dp[u][k][1])));
        }
      }
    }
    if (e[i].w == 0) {
      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= j; k++) {
          tmp[j][0] = min(tmp[j][0], dp[now][j - k][0] +
                                         min(dp[u][k + 1][0], dp[u][k][1]) + 1);
          tmp[j][1] =
              min(tmp[j][1],
                  min(dp[now][j - k + 1][0] + min(dp[u][k][0], dp[u][k][1]),
                      dp[now][j - k][1] + min(dp[u][k + 1][0] + 1,
                                              min(dp[u][k][0], dp[u][k][1]))));
        }
      }
    }
    for (int j = 0; j <= 2; j++)
      for (int k = 0; k <= 1; k++) dp[now][j][k] = tmp[j][k];
  }
}
int main() {
  cin >> n;
  for (i = 1; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y, 1);
    add(y, x, 0);
  }
  memset(dp, 0x2f, sizeof(dp));
  for (i = 1; i <= n; i++)
    if (!vis[i]) {
      w = 0;
      x = 0;
      dfs(i, 0);
      if (ci[i]) {
        can += min(x, w - x);
        ans += min(x, w - x);
      } else
        root = i;
    }
  dfs2(root, 0);
  cout << min(min(min(dp[root][0][0], dp[root][0][1]) + ans - min(can, 2),
                  min(dp[root][1][0], dp[root][1][1]) + ans - min(can, 1)),
              min(dp[root][2][0], dp[root][2][1]) + ans)
       << endl;
  return 0;
}
