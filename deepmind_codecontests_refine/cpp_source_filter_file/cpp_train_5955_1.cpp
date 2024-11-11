#include <bits/stdc++.h>
using namespace std;
int T;
long long n, m;
inline long long Fin(long long w) {
  if (!w) return m * (m + 1) / 2;
  long long p = w / m, x = Fin(p), t = w % m;
  return m * ((m * m + 1) * p + m * t) + m * (m + 1) / 2 +
         max(0ll, min(m, (m * m + 1) * p + t * m + m - x));
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%lld%lld", &n, &m);
    long long p = (n - 1) / (m * m + 1), x = Fin(p),
              v1 = (p % m + 1 + m * (p / m)), o = (n - 1) % (m * m + 1);
    printf("%lld\n", (n == x)
                         ? (v1 * (m + 1))
                         : (n + p * m + ((o - (n > x)) / m) - v1 + (x > n)));
  }
  return 0;
}
