#include <bits/stdc++.h>
int main() {
  int a, b, i, c1 = 0, c0 = 0, c2 = 0, k, j;
  scanf("%d %d", &a, &b);
  for (i = 1; i <= 6; i++) {
    k = abs(a - i);
    j = abs(b - i);
    if (k > j) {
      c1++;
    } else if (k < j) {
      c2++;
    } else {
      c0++;
    }
  }
  printf("%d %d %d", c1, c0, c2);
  return 0;
}
