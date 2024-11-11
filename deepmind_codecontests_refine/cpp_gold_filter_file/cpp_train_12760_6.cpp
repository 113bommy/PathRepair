#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int arr[32];
int dp[400][400][32][8];
bool vis[400][400];
int n;
void dfs(int curx, int cury, int level, int dir) {
  if (dp[curx][cury][level][dir]) {
    return;
  }
  if (level == n) {
    return;
  }
  dp[curx][cury][level][dir] = 1;
  vis[curx][cury] = true;
  for (int i = 1; i < arr[level]; i++) {
    curx += dx[dir];
    cury += dy[dir];
    vis[curx][cury] = true;
  }
  dfs(curx + dx[(dir + 1) % 8], cury + dy[(dir + 1) % 8], level + 1,
      (dir + 1) % 8);
  dfs(curx + dx[(dir + 7) % 8], cury + dy[(dir + 7) % 8], level + 1,
      (dir + 7) % 8);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  dfs(200, 200, 0, 0);
  int ans = 0;
  for (int i = 0; i < 400; i++) {
    for (int j = 0; j < 400; j++) {
      if (vis[i][j]) {
        ans++;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
