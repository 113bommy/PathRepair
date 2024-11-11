#include <bits/stdc++.h>
int main() {
  int t, n, x, y, d;
  long long min;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    scanf("%d %d %d", &n, &x, &y);
    d = 1;
    while ((y - x) % d != 0 || y - d * (n - 1) > x) d++;
    if (y - d * (n - 1) < x)
      min = y - d * (n - 1);
    else
      min = x;
    while (min < 1) min += d;
    for (int j = 0; j < n; j++) {
      printf("%lld ", min);
      min += d;
    }
    printf("\n");
  }
}
