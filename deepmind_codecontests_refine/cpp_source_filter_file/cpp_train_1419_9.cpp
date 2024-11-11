#include <bits/stdc++.h>
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long a, b, c;
  long x, y;
  scanf("%lld %lld", &a, &b);
  c = (a * b) / gcd(a, b);
  x = (c / a) - 1;
  y = (c / b) - 1;
  if (a > b)
    x++;
  else
    y++;
  if (x == y)
    printf("Equal\n");
  else if (x > y)
    printf("Dasha\n");
  else
    printf("Masha\n");
  return 0;
}
