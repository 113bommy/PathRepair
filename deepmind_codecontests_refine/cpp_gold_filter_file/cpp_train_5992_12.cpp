#include <bits/stdc++.h>
int main() {
  long int n, i, j, a[102], s = 0, d;
  scanf("%ld", &n);
  for (i = 0; i < n; i++) {
    scanf("%ld", &a[i]);
    s += a[i];
  }
  d = s / (n / 2);
  if (n == 2)
    printf("%ld %ld\n", 1, 2);
  else {
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        if (i == j) continue;
        if ((a[i] + a[j]) == d) {
          printf("%ld %ld\n", i + 1, j + 1);
          a[j] = 0;
          a[i] = 0;
          break;
        }
      }
    }
  }
  return 0;
}
