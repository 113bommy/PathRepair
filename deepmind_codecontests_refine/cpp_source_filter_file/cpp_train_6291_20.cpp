#include <bits/stdc++.h>
int main() {
  int n, a[105], b[105][105], i, j, s, min;
  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &a[i]);
  for (i = 0; i < n; i++) {
    for (j = 0; j < a[i]; j++) scanf("%d", &b[i][j]);
  }
  min = 5000000;
  for (i = 0; i < n; i++) {
    s = 0;
    for (j = 0; j < a[i]; j++) {
      s += (b[i][j] * 5);
    }
    s += (n * 15);
    if (min > s) min = s;
  }
  printf("%d\n", min);
  return 0;
}
