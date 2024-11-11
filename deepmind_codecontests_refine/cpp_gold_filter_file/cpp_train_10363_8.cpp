#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int M = 505;
char mp[M][M];
int id[M][M];
bool vis[M][M];
int sum[M * M];
int mark[M * M];
int cnt = 0;
int n, m;
int rx[] = {0, 1, 0, -1};
int ry[] = {-1, 0, 1, 0};
bool check(int x, int y) { return x >= 1 && x <= n && y >= 1 && y <= n; }
void dfs(int x, int y) {
  id[x][y] = cnt;
  sum[cnt]++;
  for (int j = 0; j < 4; j++) {
    int x1 = x + rx[j], y1 = y + ry[j];
    if (check(x1, y1) && !id[x1][y1] && mp[x1][y1] == '.') {
      dfs(x1, y1);
    }
  }
}
int now;
void add(int x, int y, int z) {
  if (mark[id[x][y]] != z) {
    now += sum[id[x][y]];
    mark[id[x][y]] = z;
  }
}
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(id, 0, sizeof(id));
    memset(mark, 0, sizeof(mark));
    memset(vis, 0, sizeof(vis));
    memset(sum, 0, sizeof(sum));
    for (int j = 1; j <= n; j++) scanf("%s", mp[j] + 1);
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (!id[j][k] && mp[j][k] == '.') {
          cnt++;
          dfs(j, k);
        }
      }
    }
    int ans = 0;
    for (int j = 1; j + m - 1 <= n; j++) {
      int _back[M * M];
      memcpy(_back, sum, sizeof(sum));
      for (int k = j; k <= j + m - 1; k++) {
        for (int i = 1; i <= m; i++) {
          if (id[k][i]) sum[id[k][i]]--;
        }
      }
      for (int k = 1; k + m - 1 <= n; k++) {
        now = 0;
        for (int i = 0; i < m; i++) {
          add(j - 1, k + i, j * n + k);
          add(j + m, k + i, j * n + k);
          add(j + i, k - 1, j * n + k);
          add(j + i, k + m, j * n + k);
        }
        ans = max(m * m + now, ans);
        for (int i = 0; i < m; i++) {
          if (id[j + i][k]) sum[id[j + i][k]]++;
          if (id[j + i][k + m]) sum[id[j + i][k + m]]--;
        }
      }
      memcpy(sum, _back, sizeof(_back));
    }
    printf("%d\n", ans);
  }
  return 0;
}
