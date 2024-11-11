#include <bits/stdc++.h>
using namespace std;
unsigned long long gcd(unsigned long long a, unsigned long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
unsigned long long lcm(unsigned long long a, unsigned long long b) {
  return a / gcd(a, b) * b;
}
int main() {
  unsigned long long t, w, b;
  while (scanf("%I64d%I64d%I64d", &t, &w, &b) != EOF) {
    unsigned long long ans;
    if (log(w) + log(b) - log(gcd(w, b)) > log(t)) {
      ans = min(t, min(w, b) - 1);
    } else {
      unsigned long long l = lcm(w, b);
      ans = min(w, b);
      ans *= t / l;
      ans += min(t % l, min(w, b) - 1);
    }
    unsigned long long g = gcd(ans, t);
    printf("%I64d/%I64d\n", ans / g, t / g);
  }
  return 0;
}
