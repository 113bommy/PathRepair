#include <bits/stdc++.h>
int main() {
  int x1, y1, x2, y2;
  int x, y, max;
  scanf("%d%d", &x1, &y2);
  scanf("%d%d", &x2, &y2);
  if (x1 - x2 < 0)
    x = -(x1 - x2);
  else
    x = x1 - x2;
  if (y1 - y2 < 0)
    y = -(y1 - y2);
  else
    y = y1 - y2;
  if (x > y)
    max = x;
  else
    max = y;
  printf("%d", max);
  return 0;
}
