#include <bits/stdc++.h>
using namespace std;
int sy, sx;
int grid[502][502], sum[502][502] = {0};
bool range(int y, int x) {
  return ((y >= 1) && (y <= sy) && (x >= 1) && (x <= sx));
}
int rect(int y1, int x1, int y2, int x2) {
  if (y2 < y1) swap(y1, y2);
  if (x2 < x1) swap(x1, x2);
  y1--, x1--;
  return (sum[y2][x2] - sum[y2][x1] - sum[y1][x2] + sum[y1][x1]);
}
int main() {
  if (0) freopen("in.txt", "r", stdin);
  int ans = -10000, cur;
  int i, j, k, y, x, y2, x2, s;
  scanf("%d%d", &sy, &sx);
  for (i = 1; i <= sy; i++)
    for (j = 1; j <= sx; j++) scanf("%d", &grid[i][j]);
  for (i = 1; i <= sy; i++)
    for (j = 1; j <= sy; j++)
      sum[i][j] =
          sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + grid[i][j];
  for (i = 1; i <= sy; i++)
    for (j = 1; j <= sx; j++)
      for (s = 0; s < 2; s++) {
        if (s == 0) {
          y = i, x = j;
          cur = 0;
        } else {
          y = i, x = j;
          cur = grid[y][x];
        }
        for (k = s + 1; k < 8; k += 2) {
          if (k > 1) {
            x--;
            if (!range(y, x)) break;
            cur += grid[y][x];
          }
          if (k > 1) x--;
          x2 = x;
          y2 = y + (k * 2 - 1) - 1;
          if (!range(y2, x2)) break;
          cur += rect(y, x, y2, x2);
          y = y2, x = x2;
          x++;
          y2 = y;
          x2 = x + (k * 2) - 1;
          if (!range(y2, x2)) break;
          cur += rect(y, x, y2, x2);
          y = y2, x = x2;
          y--;
          x2 = x;
          y2 = y - (k * 2) + 1;
          if (!range(y2, x2)) break;
          cur += rect(y, x, y2, x2);
          y = y2, x = x2;
          x--;
          y2 = y;
          x2 = x - (k * 2) + 1;
          if (!range(y2, x2)) break;
          cur += rect(y, x, y2, x2);
          y = y2, x = x2;
          ans = max(ans, cur);
        }
      }
  printf("%d\n", ans);
  return (0);
}
