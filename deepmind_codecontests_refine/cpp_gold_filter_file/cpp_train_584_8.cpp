#include <bits/stdc++.h>
using namespace std;
int T;
long long a;
long long mul(long long x, long long y, long long P) {
  long long z = 0;
  for (; y; y >>= 1, (x += x) %= P) {
    if (y & 1) (z += x) %= P;
  }
  return z;
}
long long qp(long long x, long long y, long long P) {
  long long z = 1;
  for (; y; y >>= 1, x = mul(x, x, P)) {
    if (y & 1) z = mul(z, x, P);
  }
  return z;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld", &a);
    int n = to_string(a).length();
    for (int m = 0;; m++) {
      long long b = -a & ((1LL << (n + m)) - 1);
      if ((a + b) % 5 == 0) b += 1LL << (n + m);
      if (!b && !m || to_string(b).length() <= m) {
        long long c = (a + b) >> (n + m), pw = 5;
        long long t = vector<long long>{-1, 0, 1, 3, 2}[c % 5];
        for (int i = 1; i < n + m; i++, pw *= 5) {
          while (qp(2, t, pw * 5) != c % (pw * 5)) {
            t += pw / 5 * 4;
          }
        }
        printf("%lld\n", t + n + m);
        break;
      }
      a *= 10;
    }
  }
  return 0;
}
