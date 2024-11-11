#include <bits/stdc++.h>
int a[1 << 18];
int main() {
  int n, r;
  scanf("%d%d", &n, &r);
  n = (1 << n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  printf("%.20lf\n", (double)sum / n);
  while (r--) {
    int x, y;
    scanf("%d%d", &x, &y);
    sum += y - a[x];
    a[x] = y;
    printf("%.20lf\n", (double)sum / n);
  }
  return 0;
}
