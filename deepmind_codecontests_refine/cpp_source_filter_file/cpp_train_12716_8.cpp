#include <bits/stdc++.h>
int main(void) {
  long long int a, b, c;
  scanf("%lld %lld %lld", &a, &b, &c);
  if (a < b)
    printf("%lld", a + 2 * c + b - 1);
  else if (a > b)
    printf("%lld", 2 * c + 2 * b + 1);
  else
    printf("%lld", 2 * c + 2 * b);
}
