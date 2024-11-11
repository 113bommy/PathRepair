#include <bits/stdc++.h>
using namespace std;
unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
  return a % b == 0 ? b : gcd(b, a % b);
}
int main() {
  unsigned long long int t, w, b;
  while (scanf("%I64d %I64d %I64d", &t, &w, &b) != EOF) {
    unsigned long long int r0, r1, s, min, r, ans = 0;
    if (w > b) {
      min = b;
      b = w;
      w = min;
    } else
      min = w;
    r0 = t / w;
    r1 = t % w;
    s = b / gcd(w, b);
    ans = r0 / s * min;
    if (r0 % s == 0)
      ans += r1;
    else if (r0 % s >= 1)
      ans = ans + min - 1;
    if (ans == 0)
      printf("%I64d/%I64d\n", ans, t);
    else {
      r = gcd(ans, t);
      printf("%I64d/%I64d\n", ans / r, t / r);
    }
  }
  return 0;
}
