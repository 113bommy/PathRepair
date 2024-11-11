#include <bits/stdc++.h>
using namespace std;
char str[1000 + 5][1005];
bool vis[1000 + 5][1000 + 5];
int cnt[1000 + 5][1000 + 5];
string DIMA = "DIMA";
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool endless = 0;
void dfs(int x, int y, int n) {
  if (endless) return;
  n = (n + 1) % 4;
  int num = 0;
  for (int i = 0; i <= 3; i++) {
    int x1 = x + dx[i];
    int y1 = y + dy[i];
    if (str[x1][y1] == DIMA[n]) {
      if (vis[x1][y1]) {
        endless = 1;
        return;
      } else if (!cnt[x1][y1]) {
        vis[x1][y1] = 1;
        dfs(x1, y1, n);
        num = max(num, cnt[x1][y1]);
        vis[x1][y1] = 0;
      } else
        num = max(num, cnt[x1][y1]);
    }
  }
  if (!cnt[x][y] && n == 0) num++;
  cnt[x][y] = num;
  return;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  memset(vis, 0, sizeof(vis));
  memset(cnt, 0, sizeof(cnt));
  memset(str, 0, sizeof(str));
  for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)
      if (str[i][j] == 'D' && !cnt[i][j]) {
        dfs(i, j, 0);
        ans = max(ans, cnt[i][j]);
      }
  }
  if (endless)
    printf("Poor Inna!\n");
  else if (ans == 0)
    printf("Poor Dima!\n");
  else
    printf("%d", ans);
  return 0;
}
