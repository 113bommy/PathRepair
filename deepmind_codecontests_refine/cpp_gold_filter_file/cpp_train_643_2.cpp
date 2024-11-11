#include <bits/stdc++.h>
int s[5];
int main() {
  int t, x0, y0;
  int x, y;
  int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0, a6 = 0, a7 = 0, a8 = 0;
  scanf("%d %d %d\n", &t, &x0, &y0);
  for (int i1 = 1; i1 <= t; i1++) {
    scanf("%d %d\n", &x, &y);
    if (x < x0) {
      if (y > y0) {
        a1++;
      } else if (y == y0) {
        a4++;
      } else {
        a6++;
      }
    } else if (x == x0) {
      if (y > y0) {
        a2++;
      } else {
        a7++;
      }
    } else {
      if (y > y0) {
        a3++;
      } else if (y == y0) {
        a5++;
      } else {
        a8++;
      }
    }
  }
  s[1] = a1 + a2 + a3;
  s[2] = a6 + a7 + a8;
  s[3] = a1 + a4 + a6;
  s[4] = a3 + a5 + a8;
  int max = -1;
  int p;
  for (int i2 = 1; i2 <= 4; i2++) {
    if (s[i2] >= max) {
      max = s[i2];
      p = i2;
    }
  }
  printf("%d\n", max);
  int b1 = 0, b2 = 0;
  if (p == 1) {
    b2++;
  } else if (p == 2) {
    b2--;
  } else if (p == 3) {
    b1--;
  } else {
    b1++;
  }
  printf("%d %d\n", x0 + b1, y0 + b2);
}
