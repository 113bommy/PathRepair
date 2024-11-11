#include <bits/stdc++.h>
using namespace std;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int main() {
  int n, m, i, x, cnt, j;
  cin >> n >> m;
  char a[n + 1][m + 1];
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1, cnt = 0; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (a[i][j] == 'P') {
        for (int k = 0; k < 4; k++) {
          int x = j + fx[k];
          int y = i + fy[k];
          if (y >= 1 && y <= n and x >= 1 && x <= m) {
            if (a[y][x] == 'W') {
              a[i][j] = '.';
              a[y][x] = '.';
              cnt++;
              break;
            }
          }
        }
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
