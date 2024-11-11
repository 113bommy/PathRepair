#include <bits/stdc++.h>
int main() {
  int a, b, c, d, e, f, n, sum1 = 0, sum2 = 0;
  scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
  n = abs(a - c);
  int x = abs(a - b);
  sum1 = x * d;
  sum2 = (n * e) + 2 * f + 1 + x * e;
  if (sum2 < sum1)
    printf("YES\n");
  else
    printf("NO\n");
}
