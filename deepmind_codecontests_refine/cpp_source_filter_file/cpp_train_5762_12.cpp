#include <bits/stdc++.h>
using namespace std;
int n, cnt, l, r, u, d, arr[2005][2005];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int x, int y) {
  arr[x][y] = 0;
  cnt++;
  if (x > d || (x == d && y > r)) {
    d = x;
    r = y;
  }
  if (x < u || (x == u && y < l)) {
    u = x;
    l = y;
  }
  for (int i = 0; i < 4; i++) {
    int newx = x + dx[i], newy = y + dy[i];
    if (newx < 0 || newx >= n || newy < 0 || newy >= n || !arr[newx][newy])
      continue;
    dfs(newx, newy);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) scanf("%d", arr[i] + j);
  }
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!arr[i][j]) continue;
      cnt = 0;
      d = -1;
      u = 20000;
      dfs(i, j);
      double dis = (u - d) * (u - d) + (r - l) * (r - l);
      double rec = dis / 2, cir = dis * acos(-1) / 4;
      (abs(dis - rec) > abs(dis - cir) ? y : x)++;
    }
  }
  printf("%d %d\n", x, y);
  return 0;
}
