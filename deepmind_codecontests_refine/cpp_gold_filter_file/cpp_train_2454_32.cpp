#include <bits/stdc++.h>
int main() {
  int x, y, z, c = 0, p, a, b;
  scanf("%d%d%d", &x, &y, &z);
  while (1) {
    if (x >= 1) {
      c++;
      x = x - 1;
    } else
      break;
    if (y >= 2) {
      c++;
      y = y - 2;
    } else
      break;
    if (z >= 4) {
      c++;
      z = z - 4;
    } else
      break;
  }
  p = c / 3;
  a = p * 1 + p * 2 + p * 4;
  printf("%d\n", a);
}
