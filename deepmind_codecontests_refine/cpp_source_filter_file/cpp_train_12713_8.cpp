#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int g, r, b;
  g = n * 5;
  r = n * 2;
  b = n * 8;
  int rem, sum = 0;
  sum += g / 5;
  rem = g % 5;
  if (rem > 0) sum += 1;
  sum += r / 2;
  rem = r % 2;
  if (rem > 0) sum += 1;
  sum += b / 8;
  rem = b % 8;
  if (rem > 0) sum += 1;
  printf("%d\n", sum);
  return 0;
}
