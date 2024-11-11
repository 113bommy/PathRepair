#include <bits/stdc++.h>
int main() {
  long long a, b, c, x, y, z;
  scanf("%lld%lld%lld", &a, &b, &c);
  if ((a + b + c) % 2 == 0) {
    x = (a + b - c) / 2;
    y = (b + c - a) / 2;
    z = (c + a - b) / 2;
    if (x >= 0 && y >= 0 && z >= 0)
      printf("%lld %lld %lld\n", x, y, z);
    else
      printf("Impossible\n");
  } else
    printf("Impossible\n");
  return 0;
}
