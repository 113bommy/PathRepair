#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return f ? x : -x;
}
const long long N = 3e5 + 5;
long long n, L, a[N], b[N], ans;
bool check(long long x) {
  long long l = 1, r = n * 3;
  for (long long i = 1; i <= n; i++) {
    while (a[i] - b[l] > x) l++;
    while (b[r] - a[i] > x) r--;
    l++;
    r++;
  }
  return l <= r;
}
long long l, r;
signed main() {
  n = read(), r = L = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= n; i++) {
    b[i] = read();
    b[i + n] = b[i] - L;
    b[i + n * 2] = b[i] + L;
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n * 3 + 1);
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid;
      r = mid - 1;
    } else
      l = mid + 1;
  }
  printf("%lld", ans);
  return 0;
}
