#include <bits/stdc++.h>
using namespace std;
int g[60][60];
char ss[110];
int sx, sy;
int gx, gy;
int res[60];
int lim;
bool can[300];
bool have;
int cc;
int vis[60][60];
int n, m;
int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
int dis[60][60];
string pre[60][60];
struct point {
  int x, y;
};
char chs[10];
bool cmp(const int &cmp1, const int &cmp2) { return chs[cmp1] < chs[cmp2]; }
int minv;
int bfs() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      vis[i][j] = 0;
    }
  }
  point p0 = {sx, sy};
  queue<point> q;
  q.push(p0);
  vis[sx][sy] = 1;
  dis[sx][sy] = 0;
  pre[sx][sy][0] = -1;
  while (!q.empty()) {
    point p = q.front();
    q.pop();
    if (minv < dis[gx][gy]) return -1;
    if (p.x == gx && p.y == gy) {
      return dis[gx][gy];
    }
    for (int d = 0; d < 4; d++) {
      point np = {p.x + dir[d][0], p.y + dir[d][1]};
      if (g[np.x][np.y] != -1 && (can[g[np.x][np.y]] || g[np.x][np.y] == 'T')) {
        if (vis[np.x][np.y]) {
          if (dis[np.x][np.y] == dis[p.x][p.y] + 1) {
            if (pre[np.x][np.y] > pre[p.x][p.y] + (char)g[np.x][np.y]) {
              pre[np.x][np.y] = pre[p.x][p.y] + (char)g[np.x][np.y];
            }
          }
        } else {
          vis[np.x][np.y] = 1;
          dis[np.x][np.y] = dis[p.x][p.y] + 1;
          pre[np.x][np.y] = pre[p.x][p.y] + (char)g[np.x][np.y];
          q.push(np);
        }
      }
    }
  }
  return -1;
}
char ans[5100];
char tmp2[5100];
int ansxx;
void dfs(int cur) {
  if (cur == lim) {
    have = true;
    int ret = bfs();
    if (ret != -1) {
      if (minv > ret) {
        minv = ret;
        strcpy(ans, pre[gx][gy].c_str());
      } else if (minv == ret) {
        if (strcmp(ans, pre[gx][gy].c_str()) > 0) {
          strcpy(ans, pre[gx][gy].c_str());
        }
      }
    }
  } else {
    int base = (cur == 0) ? 0 : (res[cur - 1] + 1);
    for (int i = base; i < cc; i++) {
      res[cur] = i;
      can[ss[i]] = true;
      dfs(cur + 1);
      can[ss[i]] = false;
    }
  }
}
int main() {
  char str[110];
  int tvis[300];
  scanf("%d%d%d", &n, &m, &lim);
  cc = 0;
  memset(tvis, 0, sizeof(tvis));
  for (int i = 1; i <= n; i++) {
    scanf("%s", str);
    for (int j = 1; j <= m; j++) {
      g[i][j] = str[j - 1];
      if (g[i][j] == 'S') {
        sx = i;
        sy = j;
      } else if (g[i][j] == 'T') {
        gx = i;
        gy = j;
      } else {
        if (!tvis[g[i][j]]) {
          tvis[g[i][j]] = 1;
          ss[cc++] = g[i][j];
        }
      }
    }
  }
  for (int i = 0; i <= n + 1; i++) {
    g[i][0] = g[i][m + 1] = -1;
  }
  for (int i = 0; i <= m + 1; i++) {
    g[0][i] = g[n + 1][i] = -1;
  }
  sort(ss, ss + cc);
  memset(can, 0, sizeof(can));
  have = false;
  minv = 1 << 30;
  dfs(0);
  if (!have) {
    for (int i = 0; i < cc; i++) {
      can[ss[i]] = true;
    }
    int ret = bfs();
    if (ret != -1) {
      if (minv > ret) {
        minv = ret;
        strcpy(ans, pre[gx][gy].c_str());
      } else if (minv == ret) {
        if (strcmp(ans, pre[gx][gy].c_str()) > 0) {
          strcpy(ans, pre[gx][gy].c_str());
        }
      }
    }
  }
  if (minv == 1 << 30) {
    printf("%d\n", -1);
  } else {
    ans[minv - 1] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}
