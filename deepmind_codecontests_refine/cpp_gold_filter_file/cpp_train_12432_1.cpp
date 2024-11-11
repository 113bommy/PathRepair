#include <bits/stdc++.h>
using namespace std;
struct road {
  int x, next;
} r[2505 * 4];
int N, M, INF;
int up[2505], st[2505], w;
int dp[2505][2505][3][3];
int ans[2505], vis[2505], size[2505];
void add(int x, int y) {
  r[++w].x = y, r[w].next = st[x];
  st[x] = w;
}
void Dfs(int x, int fr) {
  int i, mx, tmp;
  int a, b, cv, co, cu;
  vis[x]++, size[x] = 1;
  dp[x][0][0][0] = dp[x][1][1][0] = 0;
  dp[x][0][2][0] = 1;
  for (i = st[x]; i; i = r[i].next) {
    if ((tmp = r[i].x) == fr || vis[tmp] == 2) continue;
    if (!vis[tmp]) {
      Dfs(tmp, x);
      if (up[tmp] && up[tmp] != x) up[x] = up[tmp];
      size[x] += size[tmp];
      for (a = size[x]; a >= 0; a--)
        for (cu = 0; cu <= 2; cu++)
          for (co = 2; co >= 0; co--) {
            mx = -INF;
            for (b = max(0, a - size[x] + size[tmp]); b <= min(size[tmp], a);
                 b++)
              for (cv = 0; cv <= 2; cv++)
                if (cv + cu != 3)
                  if (up[tmp] == x)
                    mx = max(mx, dp[x][a - b][cu][co] + dp[tmp][b][cv][cu]);
                  else if (up[tmp])
                    mx = max(mx, dp[x][a - b][cu][0] + dp[tmp][b][cv][co]);
                  else
                    mx = max(mx, dp[x][a - b][cu][co] + dp[tmp][b][cv][0]);
            dp[x][a][cu][co] = mx;
          }
    } else
      for (a = 0, up[x] = tmp; a <= size[x]; a++) {
        dp[x][a][0][1] = dp[x][a][0][2] = dp[x][a][0][0];
        dp[x][a][1][1] = dp[x][a][1][0];
        dp[x][a][1][2] = dp[x][a][2][1] = -INF;
        dp[x][a][2][2] = dp[x][a][2][0];
      }
  }
  vis[x] = 2;
}
int main() {
  int i, j;
  int fr, to;
  scanf("%d %d", &N, &M);
  for (i = 1; i <= M; i++) {
    scanf("%d %d", &fr, &to);
    add(fr, to), add(to, fr);
  }
  memset(dp, 200, sizeof(dp)), INF = -dp[0][0][0][0];
  Dfs(1, 0);
  for (i = 0; i <= N; i++)
    for (j = 0; j < 3; j++) ans[i] = max(ans[i], dp[1][i][j][0]);
  for (i = 0; i <= N; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
