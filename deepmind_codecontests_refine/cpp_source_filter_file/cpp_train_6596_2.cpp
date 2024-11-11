#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  bool f = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ '0');
    c = getchar();
  }
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
long long n, k, s[101], a[101], maxn, now, ans;
signed main() {
  n = read();
  k = read();
  for (register long long i = 1; i <= n; ++i) a[i] = read();
  for (register long long i = 1; i <= n; ++i) s[i] = read();
  for (register long long i = 1; i <= n; ++i) {
    maxn = max(maxn, s[i]);
    now += s[i];
    if (now >= a[i])
      now -= a[i], ans += a[i];
    else {
      while (now < a[i]) now += maxn, ans += k;
      now -= a[i], ans += a[i];
    }
  }
  cout << ans;
  return 0;
}
