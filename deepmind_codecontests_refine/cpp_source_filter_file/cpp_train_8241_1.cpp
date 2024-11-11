#include <bits/stdc++.h>
int main() {
  unsigned long long int n, t, m, x, y, i, z, b, s = 0;
  scanf("%llu", &t);
  while (t--) {
    scanf("%llu %llu", &n, &m);
    x = n / m;
    y = x % 10;
    if (n < m)
      printf("%d\n", 0);
    else if (n == m)
      printf("%d\n", 1);
    else {
      for (i = 1; i <= 9; i++) {
        z = m * i;
        z = z % 10;
        s = s + z;
        if (i == y) b = s;
      }
      if (y == 0) b = 0;
      x = x / 10;
      s = s * x + b;
      printf("%llu\n", s);
      s = 0;
    }
  }
  return 0;
}
