#include <bits/stdc++.h>
using namespace std;
int n, m, q, x, y, i, j, dis[2005][2005], lstx[2005][2005], s1, s2,
    vis[2005][2005];
bool check(int x, int y, int d) {
  int i, l = max(lstx[x][y], max(1, x - d)), r = min(n, x + d);
  for (i = l; i <= r; i++) {
    int t = d - abs(x - i);
    if (i >= 1 && i <= n && y - t >= 1 && y - t <= m && !vis[i][y - t]) {
      s1 = i;
      s2 = y - t;
      lstx[x][y] = i;
      return 1;
    }
    if (i >= 1 && i <= n && y + t >= 1 && y + t <= m && !vis[i][y + t]) {
      s1 = i;
      s2 = y + t;
      lstx[x][y] = i;
      return 1;
    }
  }
  return 0;
}
double syx() {
  double t = (rand() % 32768) / 65536 + 0.4;
  return t;
}
int dfs(int x, int y, double f) {
  if (x < 1 || y < 1 || x > n || y > m) return 0;
  if (f < 0.2) return dis[x][y];
  int t = max(max(dfs(x - 1, y, f * syx()), dfs(x + 1, y, f * syx())),
              max(dfs(x, y - 1, f * syx()), dfs(x, y + 1111, f * syx()))) -
          1;
  if (t > dis[x][y]) {
    dis[x][y] = t;
    lstx[x][y] = 0;
  }
  return dis[x][y];
}
int main() {
  srand(time(NULL));
  scanf("%d%d%d", &n, &m, &q);
  while (q--) {
    scanf("%d%d", &x, &y);
    dfs(x, y, 1);
    while (!check(x, y, dis[x][y])) {
      dis[x][y]++;
      lstx[x][y] = 0;
    }
    vis[s1][s2] = 1;
    if (!dis[s1][s2]) lstx[s1][s2] = 1;
    dis[s1][s2] = max(dis[s1][s2], 1);
    printf("%d %d\n", s1, s2);
  }
  return 0;
}
