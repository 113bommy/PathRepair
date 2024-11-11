#include <bits/stdc++.h>
int main() {
  int n, i, j, count = 0;
  double x;
  scanf("%d", &n);
  int m[n], r[n];
  for (i = 1; i < n; i++) {
    scanf("%d", &m[i]);
  }
  for (i = 0; i < n; i++) {
    scanf("%d", &r[i]);
  }
  for (i = 0; i < 100000; i++) {
    for (j = 0; j < n; j++) {
      if ((i % m[j]) == r[j]) {
        count++;
        break;
      }
    }
  }
  x = count / 100000;
  printf("%lf", x);
  return 0;
}
