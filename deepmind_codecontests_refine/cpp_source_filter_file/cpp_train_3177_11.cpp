#include <bits/stdc++.h>
int n, i, a, b, c, x, y, z, con = 0;
int main() {
  scanf("%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z);
  while (x < a || y < b || z < c) {
    con = 0;
    if (a - 2 >= x) {
      if (b < y)
        b++, a -= 2, con = 1;
      else if (c < z)
        c++, a -= 2, con = 1;
    } else if (b - 2 >= y) {
      if (a < x)
        a++, b -= 2, con = 1;
      else if (c < z)
        c++, b -= 2, con = 1;
    } else if (c - 2 >= z) {
      if (a < x)
        a++, c -= 2, con = 1;
      else if (b < y)
        b++, c -= 2, con = 1;
    }
    if (con == 0) {
      if (a >= x && b >= y && c >= z)
        printf("Yes\n");
      else
        printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  return 0;
}
