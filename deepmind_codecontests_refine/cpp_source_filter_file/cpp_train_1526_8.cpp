#include <bits/stdc++.h>
using namespace std;
long long in() {
  long long a;
  scanf("%lld", &a);
  return a;
}
double din() {
  double a;
  scanf("%lf", &a);
  return a;
}
long long bigmod(long long b, long long p, long long md) {
  if (p == 0) return 1;
  if (p % 2 == 1) {
    return ((b % md) * bigmod(b, p - 1, md)) % md;
  } else {
    long long y = bigmod(b, p / 2, md);
    return (y * y) % md;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  int n = in(), a = in(), b = in();
  int ans = 1;
  while (abs(a - b) != 0) {
    a = ceil(a / 2.0);
    b = ceil(b / 2.0);
    n = ceil(n / 2.0);
    ans++;
  }
  if (n == 1)
    printf("Final!\n");
  else
    printf("%d\n", ans);
}
