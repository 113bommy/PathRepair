#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char c = getchar();
  long long x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
long long get(long long x, long long y, long long o) {
  if (x == 1) return 1;
  long long t = x / 4;
  if (o == 2) {
    if (y <= t) return get(t, y, o);
    if (y <= 2 * t) return get(t, y - t, o) + 2 * t;
    if (y <= 3 * t) return get(t, y - t * 2, o) + 3 * t;
    return get(t, y - 3 * t, o) + t;
  } else {
    if (y <= t) return get(t, y, o);
    if (y <= 2 * t) return get(t, y - t, o) + 3 * t;
    if (y <= 3 * t) return get(t, y - t * 2, o) + t;
    return get(t, y - t * 3, o) + t * 2;
  }
}
inline long long work() {
  long long n = read(), now = 0, c = 0, op = n % 3;
  n = (n - 1) / 3 + 1;
  while (now + (1ll << c) < n) now += (1ll << c), c += 2;
  long long res = now * 3;
  if (op == 1) return res + n - now;
  if (op == 2) return res + (1ll << c) + get(1LL << c, n - now, 2);
  return res + (1ll << c) * 2 + get(1LL << c, n - now, 3);
}
signed main() {
  long long T = read();
  while (T--) printf("%lld\n", work());
  return 0;
}
