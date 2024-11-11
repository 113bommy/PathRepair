#include <bits/stdc++.h>
long long a, e = 1e18;
int main() {
  scanf("%lld", &a);
  long long l = 0, r = e - 1, k = a - e % a * 9 % a * 9 % a;
  printf("%lld %lld\n", l + k, r + k);
  return 0;
}
