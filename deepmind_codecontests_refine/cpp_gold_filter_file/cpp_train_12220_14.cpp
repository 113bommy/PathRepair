#include <bits/stdc++.h>
int main() {
  int x, y, ans;
  int i, j;
  while (scanf("%d%d", &x, &y) != EOF) {
    if ((x == 0 && y == 0) || (x == 1 && y == 0)) {
      printf("0\n");
      continue;
    }
    if (x > 0 && (-x + 1 < y && y <= x)) ans = 1 + 4 * (x - 1);
    if (y > 0 && (-y <= x && x < y)) ans = 2 + 4 * (y - 1);
    if (x < 0 && (x <= y && y < -x)) ans = 3 + 4 * (-x - 1);
    if (y < 0 && (y < x && x <= -y + 1)) ans = 4 + 4 * (-y - 1);
    printf("%d\n", ans);
  }
}
