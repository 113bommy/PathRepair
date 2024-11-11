#include <bits/stdc++.h>
int main() {
  int a, b, n, x, y, z, w, j, i, e = 0, t, k;
  scanf("%d %d %d", &a, &b, &n);
  x = a;
  w = b;
  if (a < 0) x = a * -1;
  if (b < 0) {
    w = b * -1;
    y = w;
  }
  y = w;
  for (i = 0; i <= y; i++) {
    z = 1;
    if (i == 0)
      z = 1;
    else
      for (k = 1; k <= n; k++) z = z * i;
    t = z * x;
    if (t == y) {
      j = i;
      e = 1;
      break;
    }
  }
  if (a == 0 && b == 0)
    printf("%d\n", n / 2);
  else if (e == 0)
    printf("No solution\n");
  else if (a < 0 && b > 0)
    printf("%d\n", j * -1);
  else if (a > 0 && b < 0)
    printf("%d\n", j * -1);
  else
    printf("%d\n", j);
}
