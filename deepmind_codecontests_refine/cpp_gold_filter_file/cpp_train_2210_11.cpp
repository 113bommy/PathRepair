#include <bits/stdc++.h>
int main() {
  long long int n, a[11] = {0}, b[11] = {0}, x, p, z = 0;
  long long int t = 0, q = 0;
  scanf("%I64d", &n);
  for (x = 0; x < n; x++) {
    scanf("%I64d", &p);
    if (p > 0)
      a[p]++;
    else if (p < 0)
      b[abs(p)]++;
    else
      z++;
  }
  for (x = 1; x <= 10; x++) t = t + (a[x] * b[x]);
  q = (z * (z - 1)) / 2;
  t = t + (ceil(q));
  printf("%I64d", t);
  return (0);
}
