#include <bits/stdc++.h>
using namespace std;
map<int, int> g;
int p[50000], u[50000];
int main() {
  int i, j, n, m, t, k, l, x;
  for (scanf("%d%d%d", &n, &m, &k), t = 0, i = 1; i * i <= m; i++)
    if (m % i == 0) {
      p[t++] = i;
      if (i != m / i) p[t++] = m / i;
    }
  if (n % 2 == 0)
    printf("Marsel\n");
  else {
    sort(p, p + t);
    for (i = 1; i < t; i++) {
      for (l = 0, j = 1; j <= i; j++)
        if (p[i] % p[j] == 0 && p[i] / p[j] >= k) {
          if (p[j] % 2 == 0)
            u[0] = 1;
          else {
            x = g[p[i] / p[j]];
            {
              u[x] = 1;
              if (x > l) l = x;
            }
          }
        }
      for (j = 0; u[j]; j++)
        ;
      g[p[i]] = j;
      for (j = 0; j <= l; u[j] = 0, j++)
        ;
    }
    if (g[m])
      printf("Timur\n");
    else
      printf("Marsel\n");
  }
  return 0;
}
