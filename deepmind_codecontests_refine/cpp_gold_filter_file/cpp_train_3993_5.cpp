#include <bits/stdc++.h>
int main() {
  long long a, b, c;
  scanf("%I64d", &a);
  scanf("%I64d", &b);
  scanf("%I64d", &c);
  long long ag, bg;
  if ((a % c) == 0)
    ag = a / c;
  else
    ag = (a / c) + 1;
  if ((b % c) == 0)
    bg = b / c;
  else
    bg = (b / c) + 1;
  long long product = ag * bg;
  printf("%I64d", product);
  return 0;
}
