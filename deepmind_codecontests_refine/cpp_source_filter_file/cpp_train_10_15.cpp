#include <bits/stdc++.h>
int main() {
  int q, i;
  long long int l, d, r, x;
  scanf("%d", &q);
  for (i = 1; i <= q; i++) {
    scanf("%lld%lld%lld", &l, &r, &d);
    if (l / d == 1 && l % d != 0)
      printf("%d", d);
    else if (l / d > 1)
      printf("%d", d);
    else {
      x = r / d;
      printf("%d/n", (x + 1) * d);
    }
  }
  return 0;
}
