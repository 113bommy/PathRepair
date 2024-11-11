#include <bits/stdc++.h>
int main() {
  int X[5051], Y[5051], count = 0, i, j, a, b, x, y, t;
  scanf("%d%d%d%d", &x, &y, &a, &b);
  for (j = a; j <= x; j++) {
    t = (j < y + 1) ? j : y + 1;
    for (i = b; i < t; i++) {
      X[count] = j;
      Y[count] = i;
      count++;
    }
  }
  printf("%d\n", count);
  for (i = 0; i < count; i++) printf("%d %d\n", X[i], Y[i]);
  return 0;
}
