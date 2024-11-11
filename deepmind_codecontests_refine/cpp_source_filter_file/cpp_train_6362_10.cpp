#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k;
void BF1() {
  long long len = (r - l + 1 + n) % n;
  if (len == 0) len = n;
  for (int i = (int)(n); i >= (int)(0); i--) {
    long long rem = (k - 1) % (i + n) + 1;
    if (rem >= len && rem <= len + min(1ll * i, len))
      if (i + n - rem >= n - len &&
          i + n - rem <= n - len + min(1ll * i, n - len))
        return printf("%d\n", i), void(0);
    rem = (k) % (i + n) + 1;
    if (rem > len && rem <= len + min(1ll * i, len))
      if (i + n - rem >= n - len &&
          i + n - rem <= n - len + min(1ll * i, n - len))
        return printf("%d\n", i), void(0);
  }
  puts("-1");
}
void BF2() {
  long long ans = -1;
  long long len = (r - l + 1 + n) % n;
  if (len == 0) len = n;
  if (k >= len && k <= 2 * len) ans = min(len, k - len + 1) + n - len;
  for (int rnd = (int)(1); rnd <= (int)((k + 1) / n); rnd++) {
    long long rem = k - len - rnd * n;
    if (rem >= 0 && rem <= rnd * n + len) {
      long long s1 = rem % rnd, s2 = rem / rnd - s1;
      if (s2 > n - len) {
        long long T = s2 - (n - len);
        T = (T + rnd) / (rnd + 1);
        s1 += T * rnd;
        s2 -= T * (rnd + 1);
      }
      if (s1 >= 0 && s2 >= 0 && s1 <= len && s2 <= n - len)
        ans = max(ans, s1 + s2);
    }
    ++rem;
    if (rem >= 0 && rem <= rnd * n + len) {
      long long s1 = rem % rnd, s2 = rem / rnd - s1;
      if (s2 > n - len) {
        long long T = s2 - (n - len);
        T = (T + rnd) / (rnd + 1);
        s1 += T * rnd;
        s2 -= T * (rnd + 1);
      }
      if (s1 >= 0 && s2 > 0 && s1 <= len && s2 <= n - len)
        ans = max(ans, s1 + s2);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%lld%lld%lld%lld", &n, &l, &r, &k);
  k / n >= n ? BF1() : BF2();
}
