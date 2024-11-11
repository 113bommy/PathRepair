#include <bits/stdc++.h>
using namespace std;
void go(int &x1, int &y1, int &x2, int &y2) {
  int lo, hi, mi, z;
  lo = y1, hi = y2;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    printf("? %d %d %d %d\n", x1, y1, x2, mi);
    fflush(stdout);
    scanf("%d", &z);
    if (z < 1)
      lo = mi + 1;
    else
      hi = mi;
  }
  y2 = lo;
  lo = y1, hi = y2;
  while (lo < hi) {
    mi = (lo + hi + 1) / 2;
    printf("? %d %d %d %d\n", x1, mi, x2, y2);
    fflush(stdout);
    scanf("%d", &z);
    if (z < 1)
      hi = mi - 1;
    else
      lo = mi;
  }
  y1 = lo;
  lo = x1, hi = x2;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    printf("? %d %d %d %d\n", x1, y1, mi, y2);
    fflush(stdout);
    scanf("%d", &z);
    if (z < 1)
      lo = mi + 1;
    else
      hi = mi;
  }
  x2 = lo;
  lo = x1, hi = x2;
  while (lo < hi) {
    mi = (lo + hi + 1) / 2;
    printf("? %d %d %d %d\n", mi, y1, x2, y2);
    fflush(stdout);
    scanf("%d", &z);
    if (z < 1)
      hi = mi - 1;
    else
      lo = mi;
  }
  x1 = lo;
}
int main() {
  int n, lo, hi, mi, z1, z2;
  int x11, y11, x12, y12;
  int x21, y21, x22, y22;
  scanf("%d", &n);
  lo = 1, hi = n - 1;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    printf("? %d %d %d %d\n", 1, 1, mi, n);
    fflush(stdout);
    scanf("%d", &z1);
    printf("? %d %d %d %d\n", mi + 1, 1, n, n);
    fflush(stdout);
    scanf("%d", &z2);
    if (z1 == 1 && z2 == 1)
      lo = hi = mi;
    else if (z1 == 0)
      lo = mi + 1;
    else
      hi = mi - 1;
  }
  printf("? %d %d %d %d\n", 1, 1, lo, n);
  fflush(stdout);
  scanf("%d", &z1);
  printf("? %d %d %d %d\n", lo + 1, 1, n, n);
  fflush(stdout);
  scanf("%d", &z2);
  if (z1 == 1 && z2 == 1) {
    x11 = 1, y11 = 1, x12 = lo, y12 = n;
    go(x11, y11, x12, y12);
    x21 = lo + 1, y21 = 1, x22 = n, y22 = n;
    go(x21, y21, x22, y22);
    printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22,
           y22);
    fflush(stdout);
    return 0;
  }
  lo = 1, hi = n - 1;
  while (lo < hi) {
    mi = (lo + hi) / 2;
    printf("? %d %d %d %d\n", 1, 1, n, mi);
    fflush(stdout);
    scanf("%d", &z1);
    printf("? %d %d %d %d\n", 1, mi + 1, n, n);
    fflush(stdout);
    scanf("%d", &z2);
    if (z1 == 1 && z2 == 1)
      lo = hi = mi;
    else if (z1 == 0)
      lo = mi + 1;
    else
      hi = mi - 1;
  }
  x11 = 1, y11 = 1, x12 = n, y12 = lo;
  go(x11, y11, x12, y12);
  x21 = 1, y21 = lo + 1, x22 = n, y22 = n;
  go(x21, y21, x22, y22);
  printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
  fflush(stdout);
}
