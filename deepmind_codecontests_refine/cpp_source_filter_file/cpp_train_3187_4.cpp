#include <bits/stdc++.h>
using namespace std;
long long a, b, res, u;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  if (b == 0) return a;
  while (b > 0) {
    long long c = a % b;
    a = b;
    b = c;
  }
  return a;
}
int main() {
  scanf("%I64d %I64d", &a, &b);
  while (b > 0) {
    u = gcd(a, b);
    a /= u, b /= u;
    long long l = sqrt(a), c, ma = 0;
    c = a;
    for (int i = 2; i <= l; i++) {
      if (c % i == 0) ma = max(ma, b / c * c);
      while (c % i == 0) c /= i;
    }
    if (c > 1) ma = max(ma, b / c * c);
    res += b - ma;
    b = ma;
  }
  printf("%I64d", res);
  return 0;
}
