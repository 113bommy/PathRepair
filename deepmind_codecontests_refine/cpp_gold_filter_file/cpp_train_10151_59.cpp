#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  long long t, w, b;
  while (scanf("%I64d%I64d%I64d", &t, &w, &b) == 3) {
    if (w > b) swap(w, b);
    long long g = gcd(w, b);
    if (g == w) {
      long long c = w - 1;
      long long d = t / b;
      long long ans = d * w;
      c = t - d * b;
      ans += min(c, w - 1);
      c = gcd(ans, t);
      printf("%I64d", ans / c);
      printf("%c", '/');
      printf("%I64d\n", t / c);
    } else {
      long long c = w / g;
      long long ans = 0;
      if (t / b < c) {
        ans = min(w - 1, t);
      } else {
        c = c * b;
        long long d = t / c;
        ans = d * w;
        long long nu = t - d * c;
        ans += min(w - 1, nu);
      }
      c = gcd(ans, t);
      printf("%I64d", ans / c);
      printf("%c", '/');
      printf("%I64d\n", t / c);
    }
  }
  return 0;
}
