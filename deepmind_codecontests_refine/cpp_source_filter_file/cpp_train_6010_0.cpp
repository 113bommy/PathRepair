#include <bits/stdc++.h>
using namespace std;
int n;
long long a, b, q;
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
bool check(long long x, long long y) {
  if (y % x == 0) return 1;
  long long t = gcd(x, y);
  if (t == 1) return 0;
  return check(y / t, t);
}
void doit() {
  scanf("%lld %lld %lld", &a, &b, &q);
  b /= gcd(a, b);
  if (check(b, q))
    printf("Finite\n");
  else
    printf("Infinite\n");
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    doit();
  }
}
