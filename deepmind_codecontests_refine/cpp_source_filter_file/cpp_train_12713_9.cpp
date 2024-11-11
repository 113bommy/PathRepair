#include <bits/stdc++.h>
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int g, r, b;
  g = n * 5;
  r = n * 2;
  b = n * 8;
  int rem, sum = 0;
  sum += g / 3;
  rem = g % 3;
  if (rem > 0) sum += 1;
  sum += r / n;
  rem = r % n;
  if (rem > 0) sum += 1;
  sum += b / n;
  rem = b % n;
  if (rem > 0) sum += 1;
  printf("%d\n", sum);
  return 0;
}
