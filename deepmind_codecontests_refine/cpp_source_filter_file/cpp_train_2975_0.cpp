#include <bits/stdc++.h>
int main() {
  int x1, y1, x2, y2, x3, y3;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
  printf("%d %d\n", x1 + x2 - x3, y1 + y2 - y3);
  printf("%d %d\n", x1 + x3 - x2, y1 + y3 - y2);
  printf("%d %d\n", x3 + x2 - x1, y2 + y3 - y1);
  return 0;
}
