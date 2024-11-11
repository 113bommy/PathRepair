#include <bits/stdc++.h>
int main() {
  int a, b, c, d, i, j, x, y;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  i = (3 * a) / 10;
  j = a - ((a * c) / 250);
  x = (3 * b) / 10;
  y = b - ((b * d) / 250);
  int m, n;
  m = i < j ? j : i;
  n = x < y ? y : x;
  if (m > n) {
    printf("Misha");
  } else if (n > m) {
    printf("Vasya");
  } else {
    printf("Tie");
  }
  return 0;
}
