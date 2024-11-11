#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int i, x, y, min = n - 1;
  for (i = 1; i <= n; i++) {
    if ((n % i) == 0) {
      if (abs(i - (n / i)) < min) {
        x = i;
        y = n / i;
        min = abs(x - y);
      }
    }
  }
  if (x > y)
    printf("%d %d\n", y, x);
  else
    printf("%d %d\n", x, y);
}
