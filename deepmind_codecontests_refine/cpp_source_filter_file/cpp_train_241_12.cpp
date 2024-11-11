#include <bits/stdc++.h>
int main() {
  long long int a, b, c, high, low, mid;
  scanf("%i64d %i64d %i64d", &a, &b, &c);
  high = a > (b > c ? b : c) ? a : b > c ? b : c;
  low = a < (b < c ? b : c) ? a : b < c ? b : c;
  mid = (a + b + c) - (high + low);
  if ((mid - low) % 2 == 0)
    printf("%i64d", mid);
  else
    printf("%i64d", high);
  return 0;
}
