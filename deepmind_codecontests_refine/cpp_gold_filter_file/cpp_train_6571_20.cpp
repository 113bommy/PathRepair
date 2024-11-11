#include <bits/stdc++.h>
using namespace std;
int xa, ya, xb, yb, xc, yc;
int main() {
  scanf("%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc);
  if (xa > xb || xa == xb && ya > yb) swap(xa, xb), swap(ya, yb);
  if (xa > xc || xa == xc && ya > yc) swap(xa, xc), swap(ya, yc);
  if (xb > xc || xb == xc && yb > yc) swap(xb, xc), swap(yb, yc);
  if (yb >= min(ya, yc) && yb <= max(ya, yc)) {
    int ymax = max(max(ya, yb), yc), ymin = min(min(ya, yb), yc);
    printf("%d\n", xc - xa + ymax - ymin + 1);
    if (ya <= yc) {
      for (int i = xa; i < xb; i++) printf("%d %d\n", i, ya);
      for (int i = ya; i < yb; i++) printf("%d %d\n", xb, i);
      for (int i = xb; i < xc; i++) printf("%d %d\n", i, yb);
      for (int i = yb; i <= yc; i++) printf("%d %d\n", xc, i);
    } else {
      for (int i = xa; i < xb; i++) printf("%d %d\n", i, ya);
      for (int i = ya; i > yb; i--) printf("%d %d\n", xb, i);
      for (int i = xb; i < xc; i++) printf("%d %d\n", i, yb);
      for (int i = yb; i >= yc; i--) printf("%d %d\n", xc, i);
    }
  } else {
    int ymax = max(max(ya, yb), yc), ymin = min(min(ya, yb), yc);
    printf("%d\n", xc - xa + ymax - ymin + 1);
    if (yb < min(ya, yc)) {
      if (ya <= yc) {
        for (int i = xa; i < xc; i++) printf("%d %d\n", i, ya);
        for (int i = ya; i <= yc; i++) printf("%d %d\n", xc, i);
        for (int i = yb; i < ya; i++) printf("%d %d\n", xb, i);
      } else {
        for (int i = ya; i >= yc; i--) printf("%d %d\n", xa, i);
        for (int i = xa + 1; i <= xc; i++) printf("%d %d\n", i, yc);
        for (int i = yb; i < yc; i++) printf("%d %d\n", xb, i);
      }
    } else {
      if (ya <= yc) {
        for (int i = ya; i <= yc; i++) printf("%d %d\n", xa, i);
        for (int i = xa + 1; i <= xc; i++) printf("%d %d\n", i, yc);
        for (int i = yc + 1; i <= yb; i++) printf("%d %d\n", xb, i);
      } else {
        for (int i = xa; i < xc; i++) printf("%d %d\n", i, ya);
        for (int i = ya; i >= yc; i--) printf("%d %d\n", xc, i);
        for (int i = ya + 1; i <= yb; i++) printf("%d %d\n", xb, i);
      }
    }
  }
  return 0;
}
