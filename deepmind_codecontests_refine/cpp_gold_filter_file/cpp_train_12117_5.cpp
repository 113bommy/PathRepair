#include <bits/stdc++.h>
int main() {
  long n, i, j, X, D, x[101], d[101], p;
  scanf("%ld", &n);
  for (i = 1; i <= n; i++) scanf("%ld%ld", &x[i], &d[i]);
  p = 0;
  for (i = 1; i <= n; i++) {
    X = x[i] + d[i];
    D = d[i] * (-1);
    for (j = i + 1; j <= n; j++)
      if (x[j] == X && d[j] == D) {
        p = 1;
        break;
      }
    if (p == 1) break;
  }
  if (p == 1)
    printf("YES\n");
  else
    printf("NO\n");
}
