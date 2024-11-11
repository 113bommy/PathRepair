#include <bits/stdc++.h>
using namespace std;
int main() {
  int a1, b1, c1;
  int a2, b2, c2;
  while (scanf("%d%d%d", &a1, &b1, &c1) != EOF) {
    scanf("%d%d%d", &a2, &b2, &c2);
    if ((a1 == 0 && b1 == 0) || (a2 == 0 && b2 == 0)) {
      if ((a1 == 0 && b1 == 0 && c1 != 0) || (a2 == 0 && b2 == 0 && c2 != 0)) {
        printf("0\n");
      } else
        printf("-1\n");
      continue;
    }
    if ((a1 == 0 && b2 == 0) || (b1 == 0 && a2 == 0)) {
      printf("1\n");
      continue;
    }
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    if (a1 == 0) {
      x1 = 0, y1 = -c1 * 1.0 / b1;
      x2 = 1, y2 = -c1 * 1.0 / b1;
    } else if (b1 == 0) {
      x1 = -c1 * 1.0 / a1, y1 = 0;
      x2 = -c1 * 1.0 / a1, y2 = 1;
    } else {
      x1 = 0, y1 = -c1 * 1.0 / b1;
      x2 = 1, y2 = (-c1 - a1) * 1.0 / b1;
    }
    x1 = x1 - x2;
    y1 = y1 - y2;
    if (a2 == 0) {
      x3 = 0, y3 = -c2 * 1.0 / b2;
      x4 = 1, y4 = -c2 * 1.0 / b2;
    } else if (b2 == 0) {
      x3 = -c2 * 1.0 / a2, y3 = 0;
      x4 = -c2 * 1.0 / a2, y4 = 1;
    } else {
      x3 = 0, y3 = -c2 * 1.0 / b2;
      x4 = 1, y4 = (-c2 - a2) * 1.0 / b2;
    }
    x3 = x3 - x4;
    y3 = y3 - y4;
    if (fabs((x1 * y3 - y1 * x3) < 1e-12)) {
      if (fabs(x2 * a2 + y2 * b2 + c2) < 1e-12) {
        printf("-1\n");
      } else
        printf("0\n");
    } else
      printf("1\n");
  }
  return 0;
}
