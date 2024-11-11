#include <bits/stdc++.h>
using namespace std;
int T;
const int N = 2e5 + 10;
long long a[N], t[31], p[31];
void prework() {
  p[1] = 1;
  for (long long i = 2; i <= 31; ++i) {
    p[i] = p[i - 1] * 2;
  }
}
void cal(long long x) {
  for (long long i = 31; i >= 1; --i) {
    if (x >= p[i]) {
      x -= p[i];
      t[i]++;
    }
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    long long n, ag = 1;
    memset(t, 0, sizeof t);
    scanf("%lld", &n);
    prework();
    for (long long i = 1; i <= n; ++i) {
      scanf("%lld", a + i);
      if (a[i]) ag = 0;
      long long x = a[i];
      cal(x);
    }
    if (ag) {
      for (long long i = 1; i <= n; ++i) printf("%lld ", i);
      puts("");
      continue;
    }
    ag = 0;
    for (long long i = 1; i <= 31; ++i) {
      if (!ag && t[i])
        ag = t[i];
      else if (t[i])
        ag = gcd(ag, t[i]);
    }
    for (long long i = 1; i <= n; ++i)
      if (!ag || !(ag % i)) printf("%lld ", i);
    puts("");
  }
  return 0;
}
