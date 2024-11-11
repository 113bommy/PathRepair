#include <bits/stdc++.h>
int main(void) {
  int limit;
  long long int r, s, f, c, x, y;
  scanf("%d", &limit);
  for (int i = 0; i < limit; i++) {
    scanf("%lld %lld %lld %lld", &r, &s, &f, &c);
    x = r / c;
    if (x >= c) {
      y = (x / s) * f;
      printf("%lld", x + y);
      printf("\n");
    } else {
      printf("%lld", x);
      printf("\n");
    }
  }
  return 0;
}
