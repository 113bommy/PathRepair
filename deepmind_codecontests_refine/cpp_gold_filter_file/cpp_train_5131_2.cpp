#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
long long cal(long long ci) {
  long long ans = ci * a;
  long long mil = 1;
  ans -= b * ((ci - 1) * d + 1 + 1) * ci / 2 - b * ci;
  return ans;
}
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (a > b * c) {
      puts("-1");
      continue;
    }
    if (a <= b) {
      printf("%lld\n", a);
      continue;
    }
    long long t = a / b + 1;
    long long ci = (t - 1) / d + 1;
    printf("%lld\n", cal(ci));
  }
}
