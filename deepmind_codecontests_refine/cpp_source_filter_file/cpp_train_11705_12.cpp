#include <bits/stdc++.h>
int main() {
  int a, b, c, i, j, flag, a1, b1, c1, x1, x2, x3, y1, y2, y3;
  while (scanf("%d %d", &a, &b) != EOF) {
    c = (int)pow(a, 2) + (int)pow(b, 2);
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
    x3 = 0;
    y3 = 0;
    for (i = 0, flag = 0; (int)pow(i, 2) <= (int)pow(a, 2) && flag == 0; i++) {
      a1 = (int)sqrt((int)pow(a, 2) - (int)pow(i, 2));
      if (((int)pow(a1, 2) + (int)pow(i, 2)) == (int)pow(a, 2) &&
          (int)pow(a1, 2) != 0 && (int)pow(i, 2) != 0) {
        flag = 1;
        x2 = i;
        y2 = a1;
        for (j = 0, flag = 0; (int)pow(j, 2) <= (int)pow(b, 2); j++) {
          b1 = (int)sqrt((int)pow(b, 2) - (int)pow(i, 2));
          if (((int)pow(b1, 2) + (int)pow(j, 2)) == (int)pow(b, 2) &&
              (int)pow(b1, 2) != 0 && (int)pow(j, 2) != 0) {
            x3 = j;
            y3 = b1;
            if (x2 == x3 || y2 == y3) {
              x3 = -1 * x3;
              y3 = -1 * y3;
            }
            if (((int)pow(x2 - x3, 2) + (int)pow(y2 - y3, 2)) == c) {
              flag = 1;
              break;
            }
          }
        }
      }
      if (flag == 1) break;
    }
    if (flag == 1)
      printf("YES\n%d %d\n%d %d\n%d %d\n", x1, y1, x2, y2, x3, y3);
    else
      printf("NO\n");
  }
  return 0;
}
