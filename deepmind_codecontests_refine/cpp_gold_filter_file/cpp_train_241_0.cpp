#include <bits/stdc++.h>
using namespace std;
long long check(long long a, long long b, long long c) {
  long long z = min(b, c);
  a += z;
  b -= z;
  c -= z;
  if (b == 0) b = c;
  if (b % 2 == 1) return 1;
  return a;
}
void lemon() {
  long long a, b, c;
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  long long max = check(a, b, c);
  if (check(b, a, c) > max) max = check(b, a, c);
  if (check(c, a, b) > max) max = check(c, a, b);
  printf("%I64d\n", a + b + c - max);
}
int main() {
  lemon();
  return 0;
}
