#include <bits/stdc++.h>
int main() {
  int x1, y1, x2, y2;
  scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
  x1 = x2 - x1;
  y1 = y2 - y1;
  int x, y;
  scanf("%d%d", &x, &y);
  if (x1 < 0) x1 = -x1;
  if (y1 < 0) y1 = -y1;
  if (x1 % x != 0 || y1 % y != 0)
    printf("NO\n");
  else {
    x1 /= x;
    y1 /= y;
    if ((x1 ^ y1) & 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
    }
  }
  return 0;
}
