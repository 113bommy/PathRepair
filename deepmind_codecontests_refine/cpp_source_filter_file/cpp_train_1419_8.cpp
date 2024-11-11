#include <bits/stdc++.h>
int main() {
  long a, b;
  scanf("%ld%ld", &a, &b);
  long a1 = a, b1 = b;
  while ((a1 % b1 > 0) && (b1 % a1 > 0))
    if (a1 > b1)
      a1 %= b1;
    else
      b1 %= a1;
  if (a1 % b1 == 0) a1 %= b1;
  if ((a - b == b1) || (b - a == b1))
    printf("Equal");
  else if (a < b)
    printf("Dasha");
  else if (b < a)
    printf("Masha");
}
