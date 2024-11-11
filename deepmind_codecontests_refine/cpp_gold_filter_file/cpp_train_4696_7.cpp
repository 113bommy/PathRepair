#include <bits/stdc++.h>
long long a, b, x, y;
long long gcd(long long q, long long w) {
  if (!w) return q;
  return gcd(w, q % w);
}
int main() {
  scanf("%I64d %I64d %I64d %I64d", &a, &b, &x, &y);
  long long G = gcd(x, y);
  x /= G;
  y /= G;
  long long ans = std::min((long long)(a / x), (long long)(b / y));
  printf("%I64d", ans);
  return 0;
}
