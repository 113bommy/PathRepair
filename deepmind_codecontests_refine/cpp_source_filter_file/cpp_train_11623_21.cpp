#include <bits/stdc++.h>
int main() {
  int a[4];
  int e = -1;
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);
  if (a[3] < a[1]) {
    if ((a[2] > a[3] ? a[2] : a[3]) <= (2 * (a[2] > a[3] ? a[3] : a[2]))) {
      if ((2 * a[3]) >= a[1]) {
        a[1] = 2 * a[1];
        if (a[0] < a[1]) a[0] = a[1] + 1;
      }
      printf("%d\n%d\n%d", a[0], a[1], (a[2] > a[3] ? a[2] : a[3]));
    } else
      printf("%d", e);
  } else
    printf("%d", e);
}
