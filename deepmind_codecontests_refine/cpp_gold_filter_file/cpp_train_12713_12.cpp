#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int g, r, b;
  g = n * 5;
  r = n * 2;
  b = n * 8;
  int rem, sum = 0;
  sum += g / k;
  rem = g % k;
  if (rem > 0) sum += 1;
  sum += r / k;
  rem = r % k;
  if (rem > 0) sum += 1;
  sum += b / k;
  rem = b % k;
  if (rem > 0) sum += 1;
  printf("%d\n", sum);
  return 0;
}
