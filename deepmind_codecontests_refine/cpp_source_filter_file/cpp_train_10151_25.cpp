#include <bits/stdc++.h>
using namespace std;
long long t, w, b;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
bool judge(long long a, long long b, long long c) {
  if (log(1.0 * a) + log(1.0 * b) - log(1.0 * gcd(a, b)) > log(1.0 * c))
    return true;
  return false;
}
int main(int argc, char const *argv[]) {
  scanf("%ld%lld%lld", &t, &w, &b);
  if (w == b) {
    printf("1/1\n");
    return 0;
  }
  long long x, y = t;
  if (judge(w, b, t))
    x = min(w - 1, min(b - 1, t));
  else {
    long long l = lcm(w, b), g = t / l;
    if (l * g + min(w, b) <= t)
      x = (g + 1) * min(w, b) - 1;
    else
      x = g * (min(w, b) - g) - 1;
  }
  printf("%lld/%lld\n", x / gcd(x, y), y / gcd(x, y));
  return 0;
}
