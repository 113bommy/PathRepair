#include <bits/stdc++.h>
int main() {
  long int sx, sy, n, x, y, a1 = 0, a2 = 0, a3 = 0, a4 = 0;
  scanf("%ld %ld %ld", &n, &sx, &sy);
  for (long int i = 0; i < n; i++) {
    scanf("%ld %ld", &x, &y);
    x -= sx;
    y -= sy;
    if (y > 0) a1++;
    if (x < 0) a2++;
    if (y < 0) a3++;
    if (x > 0) a4++;
  }
  if (a1 >= a2 && a1 >= a3 && a1 >= a4) {
    printf("%ld\n", a1);
    printf("%ld %ld\n", sx, sy + 1);
  } else if (a2 >= a1 && a2 >= a3 && a2 >= a4) {
    printf("%ld\n", a2);
    printf("%ld %ld\n", sx - 1, sy);
  } else if (a3 >= a1 && a3 >= a2 && a3 >= a4) {
    printf("%ld\n", a3);
    printf("%ld %ld\n", sx, sy - 1);
  } else {
    printf("%ld\n", a4);
    printf("%ld %ld\n", sx + 1, sy);
  }
  return 0;
}
