#include <bits/stdc++.h>
int main() {
  int a, b, c, n, f;
  scanf("%d%d%d%d", &a, &b, &c, &n);
  f = n - ((a + b) - c);
  if (c > a || c > b)
    printf("-1");
  else if (f <= 0)
    printf("-1");
  else
    printf("%d", f);
  return 0;
}
