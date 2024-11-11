#include <bits/stdc++.h>
int main() {
  long long int x, y, z, i, j;
  scanf("%I64d %I64d %I64d", &x, &y, &z);
  i = (unsigned long long int)(x + y) / z;
  if (x % z + y % z >= z) {
    if (x % z >= y % z) {
      j = z - x % z;
    } else
      j = z - y % z;
  } else
    j = 0;
  printf("%I64d %I64d", i, j);
  return 0;
}
