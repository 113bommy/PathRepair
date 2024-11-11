#include <bits/stdc++.h>
int main() {
  int n, k, x, a[100000], i, j, sum = 0, m;
  scanf("%d %d %d", &n, &k, &x);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (i = 0; i < n - k; i++) {
    sum = sum + a[i];
  }
  m = k * x;
  printf("%d", sum + m);
  return 0;
}
