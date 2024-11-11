#include <bits/stdc++.h>
int main() {
  int n, m, z, t, v, i;
  scanf("%d %d %d", &n, &m, &z);
  if (n == m)
    printf("%d", z / m);
  else if (n == 1 || m % n == 0)
    printf("%d", z / m);
  else if (m == 1 || n % m == 0)
    printf("%d", z / n);
  else {
    int p = 0;
    if (n < m)
      t = n, v = m;
    else
      t = m, v = n;
    for (i = 1; t * i <= z; i++)
      if (t * i % v == 0) p++;
    printf("%d", p);
  }
}
