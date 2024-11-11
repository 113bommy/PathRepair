#include <bits/stdc++.h>
int main() {
  int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9;
  scanf("%d %d", &x1, &y1);
  scanf("%d %d", &x2, &y2);
  scanf("%d %d", &x3, &y3);
  printf("3\n");
  x4 = x1 + (x2 - x3);
  y4 = y1 + (y2 - y3);
  x5 = x1 + (x3 - x2);
  y5 = y1 + (y3 - y2);
  x6 = x2 + (x3 - x1);
  y6 = y2 + (y3 - y1);
  x7 = x2 + (x1 - x3);
  y7 = y2 + (y1 - y3);
  x8 = x3 + (x1 - x2);
  y8 = y3 + (y1 - y2);
  x9 = x3 + (x2 - x1);
  y9 = y3 + (y2 - y1);
  printf("%d %d\n", x4, y4);
  if ((x5 != x4) || (y5 != y4)) {
    printf("%d %d\n", x5, y5);
  }
  if (((x6 == x4) && (y6 == y4)) || ((x6 == x5) && (y6 == y5))) {
  } else {
    printf("%d %d\n", x6, y6);
  }
  if (((x7 == x4) && (y7 == y4)) || ((x7 == x5) && (y7 == y5)) ||
      ((x7 == x6) && (y7 == y6))) {
  } else {
    printf("%d %d\n", x7, y7);
  }
  if (((x8 == x4) && (y8 == y4)) || ((x8 == x5) && (y8 == y5)) ||
      ((x8 == x6) && (y8 == y6)) || ((x8 == x7) && (y8 == y7))) {
  } else {
    printf("%d %d\n", x8, y8);
  }
  if (((x9 == x4) && (y9 == y4)) || ((x9 == x5) && (y9 == y5)) ||
      ((x9 == x6) && (y9 == y6)) || ((x9 == x7) && (y9 == y7)) ||
      ((x9 == x8) && (y9 == y8))) {
  } else {
    printf("%d %d\n", x8, y8);
  }
  return 0;
}
