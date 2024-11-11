#include <bits/stdc++.h>
int main() {
  int n, p1, p2, p3, t1, t2, sum = 0;
  scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
  int i;
  int x[n], y[n];
  for (i = 0; i < n; i++) {
    scanf("%d %d", &x[i], &y[i]);
    sum += p1 * (y[i] - x[i]);
    if (i != 0) {
      int t = x[i] - y[i - 1];
      if (t >= t1) {
        sum += p1 * t1;
        t = t - t1;
        if (t >= t2) {
          sum += p2 * t2;
          t = t - t2;
          if (t > 0) {
            sum += p3 * t;
          }
        } else {
          sum += p2 * t;
        }
      } else {
        sum += p1 * t;
      }
    }
  }
  printf("%d", sum);
  return 0;
}
