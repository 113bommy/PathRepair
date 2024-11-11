#include <bits/stdc++.h>
int main() {
  int a, b, c, x, y, z, dif;
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);
  if (a >= b && a >= c) {
    x = a;
    y = b;
    z = c;
  } else if (b >= c && b >= a) {
    x = b;
    y = a;
    z = c;
  } else if (c >= b && c >= a) {
    x = c;
    y = b;
    z = a;
  }
  if (y + z <= x) {
    dif = x - y - z;
    printf("%d", dif + 1);
  } else
    printf("0");
}
