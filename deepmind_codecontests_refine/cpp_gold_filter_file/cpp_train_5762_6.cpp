#include <bits/stdc++.h>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
bool a[2010][2010];
int n;
int kp;
short x[4000010], y[4000010];
bool u[2010][2010];
int s[2010][2010];
void dfs(int cx, int cy) {
  x[kp] = cx;
  y[kp] = cy;
  u[cx][cy] = true;
  kp++;
  for (int q = 0; q < (int)(4); q++) {
    int nx = cx + dx[q];
    int ny = cy + dy[q];
    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
      if (a[nx][ny] && !u[nx][ny]) dfs(nx, ny);
  }
}
bool isBorder(int cx, int cy) {
  if (cx == 0 || cy == 0 || cx == n - 1 || cy == n - 1) return true;
  for (int q = 0; q < (int)(4); q++) {
    int nx = cx + dx[q];
    int ny = cy + dy[q];
    if (a[nx][ny] == 0) return true;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  int z;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++) {
      scanf("%d", &z);
      a[i][j] = z;
    }
  for (int q = 0; q < (int)(2); q++) {
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++)
        s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + a[i][j];
    for (int i = 0; i < (int)(n); i++)
      for (int j = 0; j < (int)(n); j++) {
        if (i < 4 || j < 4)
          a[i][j] = 0;
        else {
          int ss = s[i + 1][j + 1] - s[i + 1][j - 4] - s[i - 4][j + 1] +
                   s[i - 4][j - 4];
          a[i][j] = ss > 12;
        }
      }
  }
  int ci = 0, sq = 0;
  for (int i = 0; i < (int)(n); i++)
    for (int j = 0; j < (int)(n); j++)
      if (a[i][j] && !u[i][j]) {
        kp = 0;
        dfs(i, j);
        double sx = 0, sy = 0;
        for (int i = 0; i < (int)(kp); i++) {
          sx += x[i];
          sy += y[i];
        }
        sx /= kp, sy /= kp;
        double maxD = -1, minD = 1e9;
        for (int i = 0; i < (int)(kp); i++) {
          if (!isBorder(x[i], y[i])) continue;
          double d = (x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy);
          if (d < minD) minD = d;
          if (d > maxD) maxD = d;
        }
        if (maxD / minD < 1.5)
          ci++;
        else
          sq++;
      }
  printf("%d %d\n", ci, sq);
  return 0;
}
