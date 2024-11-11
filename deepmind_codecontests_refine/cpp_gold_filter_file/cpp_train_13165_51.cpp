#include <bits/stdc++.h>
int main() {
  int t[11] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2}, p = 0, q = 0, cp = 0, cq = 0;
  unsigned n = 0, i = 0;
  scanf("%d", &n);
  p = n / 10;
  q = n % 10;
  for (i = 0; i <= 9; i++) {
    if (p == i) cp = t[i];
    if (q == i) cq = t[i];
  }
  printf("%d", cq * cp);
  return 0;
}
