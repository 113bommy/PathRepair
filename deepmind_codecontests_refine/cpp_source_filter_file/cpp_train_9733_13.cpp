#include <bits/stdc++.h>
int main() {
  int n, i, s = 0, a[3], b[3], l;
  scanf("%d", &n);
  for (i = 0; i < 3; i++) scanf("%d%d", &a[i], &b[i]);
  l = n - a[1] - a[2];
  if (l <= b[0]) {
    printf("%d %d %d\n", l, a[1], a[2]);
  } else {
    l = l - b[0];
    if (a[1] + l <= b[1]) {
      printf("%d %d %d", b[0], a[1] + l, a[2]);
    } else {
      l = l - b[1];
      if (l + a[2] <= b[2]) {
        printf("%d %d %d\n", b[0], b[1], l + a[2]);
      }
    }
  }
  return 0;
}
