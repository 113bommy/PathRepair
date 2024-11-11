#include <bits/stdc++.h>
int main() {
  int n, k, x, a[10000], i, j, sum = 0, m;
  scanf("%d %d %d", &n, &k, &x);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n - k; i++) {
    sum = sum + k;
  }
  m = k * x;
  printf("%d", sum + m);
  return 0;
}
