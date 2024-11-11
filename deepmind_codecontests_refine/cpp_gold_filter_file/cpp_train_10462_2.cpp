#include <bits/stdc++.h>
using namespace std;
long long judge(long long a, long long b, long long c, long long l) {
  if (a < b + c) return 0;
  long long t = min(a - b - c, l);
  return (t + 2) * (t + 1) / 2;
}
int main() {
  long long a, b, c, l;
  while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &l)) {
    long long ans = 0;
    for (long long i = 0; i <= l; i++) {
      ans += (i + 2) * (i + 1) / 2;
      ans -= judge(a + i, b, c, l - i);
      ans -= judge(b + i, a, c, l - i);
      ans -= judge(c + i, b, a, l - i);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
