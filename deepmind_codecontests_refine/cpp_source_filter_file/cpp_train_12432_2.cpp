#include <bits/stdc++.h>
using namespace std;
const int maxn = 2555;
int n, m, inf, root[maxn], dp[maxn][maxn][3][3], ans[maxn], vis[maxn],
    size[maxn];
int tot = 1, N[maxn << 1], F[maxn << 1], V[maxn << 1];
void add(int x, int y) { ++tot, V[tot] = y, N[tot] = F[x], F[x] = tot; }
void dfs(int x, int f) {
  int mx;
  vis[x]++;
  size[x] = 1;
  dp[x][0][0][0] = dp[x][1][1][0] = 0;
  dp[x][0][2][0] = 1;
  for (int p = F[x]; p > 0; p = N[p]) {
    int y = V[p];
    if (y == f || vis[y] == 2) continue;
    if (!vis[y]) {
      dfs(y, x);
      if (root[y] && root[y] != x) root[x] = root[y];
      size[x] += size[y];
      for (int s1 = size[x]; s1 >= 0; s1--)
        for (int c1 = 0; c1 <= 2; c1++)
          for (int c2 = 2; c2 >= 0; c2--) {
            mx = -inf;
            for (int s2 = max(0, s1 - size[x] + size[y]);
                 s2 <= min(size[y], s1); s2++)
              for (int c3 = 0; c3 <= 2; c3++)
                if (c1 + c3 != 3) {
                  if (root[y] == x) {
                    mx = max(mx, dp[x][s1 - s2][c1][c2] + dp[y][s2][c3][c1]);
                  } else if (root[y] != 0) {
                    mx = max(mx, dp[x][s1 - s2][c1][0] + dp[y][s2][c3][c2]);
                  } else {
                    mx = max(mx, dp[x][s1 - s2][c1][c2] + dp[y][s2][c3][0]);
                  }
                }
            dp[x][s1][c1][c2] = mx;
          }
    } else {
      root[x] = y;
      for (int s = 0; s <= size[x]; s++) {
        dp[x][s][0][1] = dp[x][s][0][2] = dp[x][s][0][0];
        dp[x][s][1][1] = dp[x][s][1][0];
        dp[x][s][1][2] = dp[x][s][2][1] = -inf;
        dp[x][s][2][2] = dp[x][s][2][0];
      }
    }
  }
  vis[x] = 2;
}
void input() {
  tot = 1;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b);
    add(b, a);
  }
}
void solve() {
  memset(root, 0, sizeof root);
  memset(vis, 0, sizeof vis);
  memset(dp, 200, sizeof dp);
  inf = -dp[0][0][0][0];
  dfs(1, 0);
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < 3; j++) ans[i] = max(ans[i], dp[1][i][j][0]);
  for (int i = 0; i <= n; i++) printf("%d ", ans[i]);
  printf("\n");
}
int main() {
  input();
  solve();
  return 0;
}
