#include <bits/stdc++.h>
int main() {
  int a, b, c, x, y, z;
  scanf("%d%d%d", &a, &b, &c);
  if (a > b && a > c) {
    x = a;
    y = b;
    z = c;
  }
  if (c > b && a < c) {
    x = c;
    y = b;
    z = a;
  }
  if (a < b && b > c) {
    x = b;
    y = a;
    z = c;
  }
  if (x < (y + z))
    printf("0");
  else
    printf("%d", x - y - z + 1);
}
