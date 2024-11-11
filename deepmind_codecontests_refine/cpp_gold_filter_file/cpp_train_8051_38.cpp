#include <bits/stdc++.h>
int main() {
  int n, top = 0, i, b;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &b);
    top += b;
  }
  printf("%lf", (double)top / n);
  return 0;
}
