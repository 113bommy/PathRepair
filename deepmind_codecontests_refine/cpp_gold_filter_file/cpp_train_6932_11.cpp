#include <bits/stdc++.h>
using namespace std;
long long ext_gcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  long long d = ext_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool diophant(long long a, long long b, long long c, long long &x,
              long long &y) {
  long long d = ext_gcd(a, b, x, y);
  if (c % d != 0) return false;
  x *= c / d, y *= c / d;
  return true;
}
long long A, B, C;
int main() {
  scanf("%I64d%I64d%I64d", &A, &B, &C);
  long long x, y;
  if (diophant(A, B, -C, x, y))
    printf("%I64d %I64d\n", x, y);
  else
    printf("-1\n");
}
