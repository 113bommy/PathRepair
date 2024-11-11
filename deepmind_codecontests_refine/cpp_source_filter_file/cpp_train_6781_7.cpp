#include <bits/stdc++.h>
int n, x, y;
int f[100001];
int main() {
  while (scanf("%d", &n) != EOF) {
    int i, j, k, t;
    memset(f, 0, sizeof(f));
    for (i = 1; i <= n; i++) {
      t = 0;
      scanf("%d %d", &x, &y);
      for (j = 1; j < sqrt(x); j++)
        if (x % j == 0) {
          if (f[j] < i - y) t++;
          f[j] = i;
          if (f[x / j] < i - y) t++;
          f[x / j] = i;
        }
      if (j * j == x && j > y) {
        if (f[j] < i - y) t++;
        f[j] = i;
      }
      printf("%d\n", t);
    }
  }
  return 0;
}
