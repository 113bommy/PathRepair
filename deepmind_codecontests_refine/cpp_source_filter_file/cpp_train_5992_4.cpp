#include <bits/stdc++.h>
int main() {
  int n, max, min, imax, imin, equal, aa;
  while ((scanf("%d", &n)) == 1) {
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    max = min = a[0];
    imin = imax = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] > max) {
        max = a[i];
        imax = i;
      } else if (a[i] < min) {
        min = a[i];
        imin = i;
      }
    }
    a[imin] = a[imax] = -1;
    equal = min + max;
    printf("%d %d\n", imin + 1, imax + 1);
    for (int i = 0; i < n; i++) {
      if (a[i] == -1) continue;
      aa = a[i];
      for (int j = 0; j < n; j++) {
        if (i == j || a[j] == -1) continue;
        if (aa + a[j] == equal) {
          a[i] = a[j] = -1;
          printf("%d %d\n", j + 1, i + 1);
          break;
        }
      }
    }
  }
  return 0;
}
