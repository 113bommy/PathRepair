#include <bits/stdc++.h>
using namespace std;
const int N = 501;
int n, D;
int dt[N][N], dis[N][N], sx[N], g[N][N], tot, L[N], R[N], k, sz[N],
    tmp[2][N][N];
short dp[N][N][N];
bool u[N];
void get(int st, int x, int ds) {
  u[x] = true;
  dis[st][x] = ds;
  for (int i = 1; i <= n; i++)
    if (g[x][i] && !u[i]) {
      get(st, i, ds + g[x][i]);
    }
}
void ddfs(int x) {
  L[x] = R[x] = ++k;
  u[x] = true;
  sz[x] = 1;
  for (int i = 1; i <= n; i++)
    if (g[x][i] && !u[i]) {
      ddfs(i);
      R[x] = R[i];
      sz[x] += sz[i];
    }
}
void dfs(int x, int ff) {
  u[x] = true;
  for (int i = 1; i <= n; i++)
    if (g[x][i] && i != ff) dfs(i, x);
  int pre = 0, now = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j <= tot && j <= sz[x]; j++)
      for (int h = 1; h <= n; h++) tmp[i][j][h] = -1;
  for (int i = 1; i <= n; i++)
    if (dis[x][i] <= D) {
      int j1 = 0, k1 = 0;
      if (L[i] >= L[x] && L[i] <= R[x]) j1 = 1;
      if (!sx[i]) k1 = 1;
      tmp[pre][j1][i] = k1;
    }
  int pv = 1;
  for (int i = 1; i <= n; i++)
    if (g[x][i] && i != ff) {
      int rd = min(pv, tot) + 1;
      for (int j = 0; j <= rd; j++)
        for (int h = 1; h <= n; h++) tmp[now][j][h] = -1;
      for (int j = 0; j <= rd; j++) {
        for (int h = 1; h <= n; h++)
          if (tmp[pre][j][h] != -1) {
            for (int z = 0; z + j <= tot + 1 && z <= sz[i] + 1; z++) {
              int j1, tp;
              if (L[h] >= L[i] && L[h] <= R[i]) {
                if (dp[i][z][h] == -1) continue;
                j1 = z + j - 1;
                tp = tmp[pre][j][h] + dp[i][z][h] - (sx[h] == 0);
              } else {
                j1 = z + j;
                if (dp[i][z][h] == -1 && dt[i][z] == -1) continue;
                if (dp[i][z][h] == -1)
                  tp = tmp[pre][j][h] + dt[i][z];
                else if (dt[i][z] == -1)
                  tp = tmp[pre][j][h] + dp[i][z][h] - (sx[h] == 0);
                else
                  tp = tmp[pre][j][h] +
                       min(dp[i][z][h] - (sx[h] == 0), dt[i][z]);
              }
              if (tmp[now][j1][h] == -1 || tmp[now][j1][h] > tp)
                tmp[now][j1][h] = tp;
            }
          }
      }
      pv += sz[i];
      pre = 1 - pre;
      now = 1 - now;
    }
  for (int i = 0; i < N; i++) {
    for (int j = 1; j <= n; j++) {
      dp[x][i][j] = tmp[pre][i][j];
      if (L[j] >= L[x] && L[j] <= R[x]) {
        if (dp[x][i][j] != -1 && (dt[x][i] == -1 || dt[x][i] > dp[x][i][j])) {
          dt[x][i] = dp[x][i][j];
        }
      }
    }
  }
}
int main() {
  int T, i, ca = 1;
  {
    scanf("%d%d", &n, &D);
    memset(g, 0, sizeof(g));
    tot = 0;
    for (i = 1; i <= n; i++) {
      scanf("%d", &sx[i]);
      tot += sx[i];
    }
    for (i = 1; i < n; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if (!g[a][b] || (g[a][b] && g[a][b] > c)) g[a][b] = g[b][a] = c;
    }
    k = 0;
    memset(u, 0, sizeof(u));
    ddfs(1);
    for (i = 1; i <= n; i++) {
      memset(u, 0, sizeof(u));
      get(i, i, 0);
    }
    memset(u, 0, sizeof(u));
    memset(dt, -1, sizeof(dt));
    dfs(1, 0);
    int r = -1;
    for (i = 1; i <= n; i++) {
      if (dp[1][tot][i] != -1 && (r == -1 || r > dp[1][tot][i]))
        r = dp[1][tot][i];
    }
    printf("%d\n", r);
  }
  return 0;
}
