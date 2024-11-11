#include <bits/stdc++.h>
int main() {
  int a, b;
  scanf("%d", &a);
  scanf("%d", &b);
  int i, n, m, sum = 0;
  n = (b - a) / 2;
  m = (b - a) - n;
  for (i = 1; i <= n; i++) {
    sum = sum + i;
  }
  for (i = 1; i <= m; i++) {
    sum = sum + i;
  }
  printf("%d", sum);
  return 0;
}
