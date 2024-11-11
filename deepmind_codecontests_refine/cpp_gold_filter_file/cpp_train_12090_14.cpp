#include <bits/stdc++.h>
int main() {
  long long int n;
  scanf("%lld", &n);
  while (n--) {
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld %lld\n", a, 2 * a);
  }
  return 0;
}
