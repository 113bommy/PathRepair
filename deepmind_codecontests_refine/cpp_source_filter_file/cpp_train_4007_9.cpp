#include <bits/stdc++.h>
int a[1003][1003] = {0};
int main() {
  int wi, le, n;
  scanf("%d%d%d", &wi, &le, &n);
  int i;
  int f = 0;
  int ans = 0;
  for (i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (f) continue;
    a[x][y] = 1;
    if (a[x][y - 1] == 1 && a[x + 1][y - 1] == 1 && a[x + 1][y] == 1) {
      f = 1;
      ans = i + 1;
      continue;
    }
    if (a[x][y + 1] == 1 && a[x + 1][y + 1] == 1 && a[x + 1][y] == 1) {
      f = 1;
      ans = i + 1;
      continue;
    }
    if (a[x][y + 1] == 1 && a[x - 1][y + 1] == 1 && a[x + 1][y] == 1) {
      f = 1;
      ans = i + 1;
      continue;
    }
    if (a[x][y - 1] == 1 && a[x - 1][y - 1] == 1 && a[x - 1][y] == 1) {
      f = 1;
      ans = i + 1;
      continue;
    }
  }
  printf("%d\n", ans);
}
