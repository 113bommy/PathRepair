#include <bits/stdc++.h>
int main() {
  long long a, b, n, m, x, y, t1, t2, j, i, z;
  scanf("%lld %lld", &a, &b);
  t1 = sqrt(a);
  for (i = 1;; i++) {
    x = i * i + i;
    if (x == b) {
      t2 = i;
      break;
    } else if (x > b) {
      t2 = i - 1;
      break;
    }
  }
  y = t1;
  z = t2;
  for (i = 1;; i++) {
    if (i % 2 == 1)
      t1--;
    else
      t2--;
    if (t1 == 0 || t2 == 0) break;
  }
  if (y == z)
    printf("Vladik");
  else if (t2 == 0)
    printf("Valera");
  else
    printf("Vladik");
  return 0;
}
