#include <bits/stdc++.h>
int main() {
  long long int x, y, z, a, b;
  scanf("%lld%lld%lld", &x, &y, &z);
  a = x / z + (x % z != 0);
  b = y / z + (y % z != 0);
  printf("%lld\n", a * b);
}
