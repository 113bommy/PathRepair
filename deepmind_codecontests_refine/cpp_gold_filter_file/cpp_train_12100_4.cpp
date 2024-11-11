#include <bits/stdc++.h>
int main() {
  int i, j, t, p, r, s;
  int a[4];
  scanf("%d", &t);
  for (i = 0; i < t; i++) {
    for (j = 0; j < 4; j++) {
      scanf("%d", &a[j]);
    }
    p = a[1] - a[0];
    r = a[2] + a[3];
    if (p % r == 0)
      printf("%d\n", p / r);
    else
      printf("-1\n");
  }
}
