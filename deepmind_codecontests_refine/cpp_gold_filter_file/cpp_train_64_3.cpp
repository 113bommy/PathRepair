#include <bits/stdc++.h>
int main() {
  int n, x = 1, y = 1000000, s1 = 0, s2 = 0, z;
  scanf("%d", &n);
  while (n > 0) {
    scanf("%d", &z);
    if (z <= 1000000 / 2) {
      x = z;
    } else {
      if (y > z) {
        y = z;
      }
    }
    n--;
  }
  if ((x - 1) > 1000000 - y) {
    printf("%d", x - 1);
  } else {
    printf("%d", 1000000 - y);
  }
  return 0;
}
