#include <bits/stdc++.h>
int main() {
  int t, n, i, x, y;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &x, &y, &n);
    i = n - n % x + y;
    if (i <= n)
      printf("%d\n", i);
    else
      printf("%d\n", i - x);
  }
}
