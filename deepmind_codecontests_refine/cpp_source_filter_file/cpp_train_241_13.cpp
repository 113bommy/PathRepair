#include <bits/stdc++.h>
int main() {
  long long int a, b, c, high, low, mid;
  scanf("%l64d %l64d %l64d", &a, &b, &c);
  high = a > (b > c ? b : c) ? a : b > c ? b : c;
  low = a < (b < c ? b : c) ? a : b < c ? b : c;
  mid = (a + b + c) - (high + low);
  if ((mid - low) % 2 == 0)
    printf("%l64d", mid);
  else
    printf("%l64d", high);
  return 0;
}
