#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
const int inf = 0x3f3f3f3f;
int dis[maxn][maxn];
int mp[maxn][maxn];
int dp[maxn][maxn];
void floyd(int n) {
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) {
        if (dis[i][k] != inf && dis[k][j] != inf)
          dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
}
void work() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    dis[i][i] = 0;
    for (int j = i + 1; j <= n; j++) {
      mp[i][j] = mp[j][i] = dis[i][j] = dis[j][i] = inf;
    }
  }
  for (int i = 1; i <= m; i++) {
    int x, y, l;
    scanf("%d %d %d", &x, &y, &l);
    mp[y][x] = mp[x][y] = dis[x][y] = dis[y][x] = l;
  }
  floyd(n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++)
        if (dis[i][k] != inf && dis[k][j] != inf && mp[k][j] != inf && j != k) {
          if (dis[i][k] + mp[k][j] == dis[i][j]) {
            dp[i][j]++;
          }
        }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++) {
      ans = 0;
      for (int k = 1; k <= n; k++)
        if (dis[i][k] + dis[k][j] == dis[i][j]) ans += dp[i][k];
      printf("%d ", ans);
    }
}
int main() {
  work();
  return 0;
}
