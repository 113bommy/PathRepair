#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[5][maxn];
int xhd[20005][5];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= 4; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  int x = 2, y = 1;
  int ans = 0;
  int cnt = 0;
  int t = 0;
  while (1) {
    t++;
    if (t >= 100000) break;
    if (cnt >= k) break;
    if (x == 2 && a[x][y] == a[x - 1][y] && a[x][y] != 0) {
      ans++;
      xhd[ans][1] = a[x][y];
      xhd[ans][2] = x - 1;
      xhd[ans][3] = y;
      a[x][y] = 0;
      cnt++;
    }
    if (x == 3 && a[x][y] == a[x + 1][y] && a[x][y] != 0) {
      ans++;
      xhd[ans][1] = a[x][y];
      xhd[ans][2] = x + 1;
      xhd[ans][3] = y;
      a[x][y] = 0;
      cnt++;
    }
    int nx = x, ny = y;
    if (nx == 2) {
      ny++;
      if (ny > n) {
        nx = 3;
        ny = n;
      }
    } else if (nx == 3) {
      ny--;
      if (ny < 1) {
        nx = 2;
        ny = 1;
      }
    }
    if (a[x][y] != 0 && a[nx][ny] == 0) {
      ans++;
      xhd[ans][1] = a[x][y];
      xhd[ans][2] = nx;
      xhd[ans][3] = ny;
      a[nx][ny] = a[x][y];
      a[x][y] = 0;
    }
    x = nx;
    y = ny;
  }
  if (cnt < k) {
    printf("-1\n");
    return 0;
  }
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) {
    printf("%d %d %d\n", xhd[i][1], xhd[i][2], xhd[i][3]);
  }
  return 0;
}
