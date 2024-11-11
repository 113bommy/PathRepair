#include <bits/stdc++.h>
int main() {
  long long int a, b, c, high, low, mid;
  scanf("%I64d %I64d %I64d", &a, &b, &c);
  high = a > (b > c ? b : c) ? a : b > c ? b : c;
  low = a < (b < c ? b : c) ? a : b < c ? b : c;
  mid = (a + b + c) - (high + low);
  if ((mid - low) % 2 == 0)
    printf("%I64d", mid);
  else
    printf("%I64d", high);
  return 0;
}
