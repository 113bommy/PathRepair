#include <bits/stdc++.h>
using namespace std;
template <class t>
inline t read(t &x) {
  char c = getchar();
  bool f = 0;
  x = 0;
  while (!isdigit(c)) f |= c == '-', c = getchar();
  while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  if (f) x = -x;
  return x;
}
template <class t>
inline void write(t x) {
  if (x < 0)
    putchar('-'), write(-x);
  else {
    if (x > 9) write(x / 10);
    putchar('0' + x % 10);
  }
}
const long long N = 2e5 + 5;
long long n, m, ans[N << 1], match[N];
pair<long long, long long> a[N], b[N * 3];
void cf(long long l, long long r, long long w) {
  ans[l] += w;
  ans[r + 1] -= w;
}
signed main() {
  read(m);
  read(n);
  for (long long i = 1, x; i <= n; i++) a[i] = {read(x) + m, i};
  for (long long i = 1, x; i <= n; i++) b[i] = {read(x), i};
  sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
  for (long long i = 1; i <= n << 1; i++)
    b[i + n] = {b[i].first + m, b[i].second};
  for (long long i = 1; i <= n; i++) ans[0] += a[i].first;
  for (long long i = 1; i <= n; i++) {
    long long p = lower_bound(b + 1, b + 1 + n * 3, a[i]) - b;
    if (p > i && p - i <= n << 1) ans[p - i] -= 2 * a[i].first;
  }
  for (long long i = 1; i <= n * 3; i++) {
    if (i <= n) {
      cf(0, i - 1, -b[i].first);
      continue;
    }
    if (i > n << 1) {
      cf(i - n, n << 1, b[i].first);
      continue;
    }
    long long p = upper_bound(a + 1, a + 1 + n, b[i]) - a;
    cf(i - p + 1, i - 1, b[i].first);
    cf(i - n, i - p, -b[i].first);
  }
  long long mi = ans[0], dis = 0;
  for (long long i = 1; i <= n << 1; i++) {
    ans[i] += ans[i - 1];
    if (ans[i] < mi) mi = ans[i], dis = i;
  }
  for (long long i = 1; i <= n; i++)
    match[a[i].second] = b[(i + dis - 1) % n + 1].second;
  write(mi);
  puts("");
  for (long long i = 1; i <= n; i++) write(match[i]), putchar(' ');
}
