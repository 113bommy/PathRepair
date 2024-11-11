#include <bits/stdc++.h>
int main() {
  long long a, b, c, d, i;
  scanf("%lld", &d);
  for (i = 0; i < d; i++) {
    scanf("%lld%lld", &a, &b);
    if (a <= b) {
      c = ((a - 1) * a) / 2;
      printf("%lld\n", c + 1);
    } else {
      c = (b * (b + 1)) / 2;
      printf("%lld\n", c);
    }
  }
}
