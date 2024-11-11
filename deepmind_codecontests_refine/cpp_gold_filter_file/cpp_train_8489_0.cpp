#include <bits/stdc++.h>
int main() {
  int n, k, j, i, ans;
  double t;
  scanf("%d %d %lf", &n, &k, &t);
  t = (t * n * k / 100);
  ans = t;
  for (i = 0, j = k; j < t; j += k, i++) {
    printf("%d ", k);
  }
  if (i < n) {
    printf("%d", ans - j + k);
    i++;
  }
  for (i; i < n; i++) {
    printf(" 0");
  }
  putchar(10);
  return 0;
}
