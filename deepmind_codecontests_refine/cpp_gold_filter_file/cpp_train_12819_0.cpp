#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
int vis[55][55], a[2505][2], b[2505][2];
;
char mp[55][55];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n;
int r1, c1, r2, c2;
void dfs(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int ax = x + dx[i];
    int ay = y + dy[i];
    if (ax < 1 || ax > n || ay < 1 || ay > n) continue;
    if (mp[ax][ay] == '1') continue;
    if (vis[ax][ay] > 0) continue;
    ;
    vis[ax][ay] = 1;
    dfs(ax, ay);
  }
}
void dfs2(int x, int y) {
  for (int i = 0; i < 4; i++) {
    int ax = x + dx[i];
    int ay = y + dy[i];
    if (ax < 1 || ax > n || ay < 1 || ay > n) continue;
    if (mp[ax][ay] == '1') continue;
    if (vis[ax][ay] > 0) continue;
    vis[ax][ay] = 2;
    dfs2(ax, ay);
  }
}
int main() {
  scanf("%d", &n);
  scanf("%d%d", &r1, &c1);
  scanf("%d%d", &r2, &c2);
  for (int i = 1; i <= n; i++) {
    scanf("%s", mp[i] + 1);
  }
  vis[r1][c1] = 1;
  dfs(r1, c1);
  if (vis[r2][c2] == 1) {
    printf("0\n");
    return 0;
  } else {
    vis[r2][c2] = 2;
    dfs2(r2, c2);
    int g = 0, k = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (vis[i][j] == 1) {
          a[++g][0] = i;
          a[g][1] = j;
        } else if (vis[i][j] == 2) {
          b[++k][0] = i;
          b[k][1] = j;
        }
      }
    }
    int ans = 999999999;
    for (int i = 1; i <= g; i++) {
      for (int j = 1; j <= k; j++) {
        ans = min(ans, (a[i][0] - b[j][0]) * (a[i][0] - b[j][0]) +
                           (a[i][1] - b[j][1]) * (a[i][1] - b[j][1]));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
