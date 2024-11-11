#include <bits/stdc++.h>
using namespace std;
long long n, m, l, r, mid, T, ss;
bool calc(long long k, long long n) {
  if (--n <= 0) return 1;
  long long now = 1, L = k * m, l;
  for (long long i = 1; i <= k; ++i) {
    now = now * (k - i + 1) / i;
    l = min(now, L / i);
    n -= l, L -= l * i;
    if (now > L / i) break;
    if (n <= 0) return 1;
  }
  return n <= 0;
}
int main() {
  scanf("%I64d", &T);
  while (T--) {
    scanf("%I64d%I64d", &n, &m);
    l = 0, r = n - 1;
    while (l < r) {
      mid = (l + r) / 2;
      if (calc(mid, n))
        r = mid;
      else
        l = mid + 1;
    }
    printf("%I64d\n", l);
  }
  return 0;
}
