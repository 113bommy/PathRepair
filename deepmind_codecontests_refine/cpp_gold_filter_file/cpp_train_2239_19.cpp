#include <bits/stdc++.h>
int main() {
  long long int x, y, z, a, b, c, d, min[5], i;
  scanf("%lld %lld %lld", &x, &y, &z);
  min[0] = (x + y) * 2;
  min[1] = (y + z) * 2;
  min[2] = (x + z) * 2;
  min[3] = x + y + z;
  for (i = 0; i < 4; i++) {
    if (min[0] > min[i]) min[0] = min[i];
  }
  printf("%lld", min[0]);
  return 0;
}
