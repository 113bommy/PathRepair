#include <bits/stdc++.h>
using namespace std;
const long long NR = 1e6 + 10;
void Min(long long& x, long long y) { x = min(x, y); }
void Max(long long& x, long long y) { x = max(x, y); }
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
long long n, L;
long long a[NR], b[NR];
bool check(long long len) {
  long long l = 1, r = 1, now = 0;
  for (long long i = 1; i <= n * 2; i++) {
    while (l <= 4 * n && b[l] < a[i] - len) l++;
    while (r <= 4 * n && b[r] <= a[i] + len) r++;
    r--;
    Max(now, l - i);
    if (r - i < now) return 0;
  }
  return 1;
}
signed main() {
  n = read(), L = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + n + 1);
  for (long long i = 1; i <= n; i++) b[i] = read();
  sort(b + 1, b + n + 1);
  for (long long i = 1; i <= n; i++) a[i] += L, a[i + n] = a[i] + L;
  for (long long i = 1; i <= n * 3; i++) b[i + n] = b[i] + L;
  long long l = 1, r = L / 2, res = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%lld\n", res);
  return 0;
}
