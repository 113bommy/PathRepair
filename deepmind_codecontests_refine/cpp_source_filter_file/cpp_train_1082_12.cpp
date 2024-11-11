#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long flag = 1;
  long long x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
const long long inf = 0x3f3f3f3f;
const long long N = 1e5 + 10;
long long a[N], b[N];
long long n, m;
long long l = 0, r = inf + 1;
inline long long Abs(long long a) { return a < 0 ? -a : a; }
inline bool check(long long times) {
  long long lcos = 1, rcos = 1;
  for (long long i = 1; i <= n; i++) {
    long long pos =
        Abs(b[rcos] - b[lcos]) + min(Abs(b[lcos] - a[i]), Abs(b[rcos] - a[i]));
    while (pos <= times && rcos <= m) {
      rcos++;
      pos = Abs(b[rcos] - b[lcos]) +
            min(Abs(b[lcos] - a[i]), Abs(b[rcos] - a[i]));
    }
    lcos = rcos;
    if (rcos > m) return true;
  }
  return false;
}
signed main() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) b[i] = read();
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%lld\n", l);
  return 0;
}
