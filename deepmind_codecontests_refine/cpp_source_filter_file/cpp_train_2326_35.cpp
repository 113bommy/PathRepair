#include <bits/stdc++.h>
int main() {
  int d, n, a[2010], i, ans = 0, sum = 0;
  scanf("%d", &d);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  sum -= a[0];
  printf("%d\n", (n - 1) * d - sum);
  return 0;
}
