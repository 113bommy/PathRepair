#include <bits/stdc++.h>
int a[1001][1001];
int n, i, j, s, m, x, t;
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; i++) {
    t = 0;
    for (j = 1; j <= n; j++) t = t ^ (a[i][j] ^ a[j][i]);
    s ^= t;
  }
  scanf("%d", &m);
  while (m) {
    m--;
    scanf("%d", &x);
    if (x == 1 || x == 2) {
      scanf("%d", &x);
      s ^= 1;
      continue;
    }
    printf("%d", s);
  }
}
