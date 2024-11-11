#include <bits/stdc++.h>
int main() {
  int n, a[1000], b[1000], i, j, c, d, e, f, l = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }
  for (i = 0; i < n; i++) {
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    for (j = 0; j < n; j++) {
      if (a[j] > a[i] && b[j] == b[i]) {
        c++;
      }
      if (a[j] < a[i] && b[j] == b[i]) {
        d++;
      }
      if (a[j] == a[i] && b[j] < b[i]) {
        e++;
      }
      if (a[j] == a[i] && b[j] > b[i]) {
        f++;
      }
    }
    if (c > 0 && d > 0 && e > 0 && f > 0) {
      l++;
    }
  }
  printf("%d", l);
  return 0;
}
