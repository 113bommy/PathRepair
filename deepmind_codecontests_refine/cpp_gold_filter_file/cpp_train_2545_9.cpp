#include <bits/stdc++.h>
int main(void) {
  int x1, y1, x2, y2, x3, y3, x4, y4, i, j, k, z = 0;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  if (x1 == x2 && y1 != y2) {
    k = abs(y1 - y2);
    if (x2 + k <= 1000 && x4 + k <= 1000) {
      x3 = x2 + k;
      x4 = x1 + k;
    } else {
      x3 = x2 - k;
      x4 = x1 - k;
    }
    y3 = y2;
    y4 = y1;
  } else if (x1 != x2 && y1 == y2) {
    k = abs(x1 - x2);
    if (y2 + k <= 1000 && y4 + k <= 1000) {
      y3 = y2 + k;
      y4 = y1 + k;
    } else {
      y3 = y2 - k;
      y4 = y1 - k;
    }
    x3 = x2;
    x4 = x1;
  } else if (x1 != x2 && y1 != y2 &&
             (x1 - x2 == y1 - y2 || x2 - x1 == y1 - y2)) {
    y3 = y2;
    x3 = x1;
    y4 = y1;
    x4 = x2;
  } else
    z = 1;
  if (z == 1)
    printf("-1");
  else
    printf("%d %d %d %d", x3, y3, x4, y4);
}
