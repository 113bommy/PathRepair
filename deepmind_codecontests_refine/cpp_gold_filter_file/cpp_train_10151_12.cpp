#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  long long t, w, b;
  scanf("%lld", &t);
  scanf("%lld", &w);
  scanf("%lld", &b);
  long long G = gcd(w, b);
  double divi = (double)w * (double)b;
  long long L = (long long)(divi / G);
  long long ans = (t / L) * min(w, b) - 1;
  ans += min(t % L + 1, min(w, b));
  long long cd = gcd(ans, t);
  printf("%lld/%lld\n", ans / cd, t / cd);
  return 0;
}
