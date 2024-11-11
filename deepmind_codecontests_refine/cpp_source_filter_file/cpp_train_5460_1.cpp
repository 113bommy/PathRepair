#include <bits/stdc++.h>
using namespace std;
const long long N = 300010;
const long long mod = 1e9 + 9;
long long a, b, opt, s1[N], f[N], x, y;
struct tree {
  long long l, r, sum, lazy1, lazy2, len;
} s[N << 2];
inline void up(long long now) {
  s[now].sum = (s[now << 1].sum + s[now << 1 | 1].sum) % mod;
}
inline void add(long long now, long long n, long long m) {
  s[now].lazy1 = (s[now].lazy1 + n) % mod;
  s[now].lazy2 = (s[now].lazy2 + m) % mod;
  s[now].sum =
      (s[now].sum + n * f[s[now].len] % mod + m * f[s[now].len + 1] % mod - m) %
      mod;
}
inline void build(long long now, long long l, long long r) {
  s[now].l = l;
  s[now].r = r;
  s[now].len = r - l + 1;
  if (l == r) {
    s[now].sum = s1[l] % mod;
    return;
  }
  long long mid = (l + r) >> 1;
  build(now << 1, l, mid);
  build(now << 1 | 1, mid + 1, r);
  up(now);
}
inline void down(long long now) {
  if (!s[now].lazy1) return;
  long long n = (s[now].lazy1 * f[s[now << 1].len - 1] % mod +
                 s[now].lazy2 * f[s[now << 1].len] % mod) %
                mod;
  long long m = (s[now].lazy1 * f[s[now << 1].len] % mod +
                 s[now].lazy2 * f[s[now << 1].len + 1] % mod) %
                mod;
  add(now << 1, s[now].lazy1, s[now].lazy2);
  add(now << 1 | 1, n, m);
  s[now].lazy1 = s[now].lazy2 = 0;
}
inline void change(long long now, long long l, long long r) {
  if (s[now].l >= l && s[now].r <= r) {
    add(now, f[s[now].l - l + 1], f[s[now].l - l + 2]);
    return;
  }
  down(now);
  long long mid = (s[now].l + s[now].r) >> 1;
  if (l <= mid) change(now << 1, l, r);
  if (mid < r) change(now << 1 | 1, l, r);
  up(now);
}
inline long long query(long long now, long long l, long long r) {
  if (s[now].l >= l && s[now].r <= r) return s[now].sum;
  down(now);
  long long mid = (s[now].l + s[now].r) >> 1, ans = 0;
  if (l <= mid) ans = (ans + query(now << 1, l, r) % mod) % mod;
  if (mid < r) ans = (ans + query(now << 1 | 1, l, r) % mod) % mod;
  return ans;
}
signed main() {
  f[1] = f[2] = 1;
  for (long long i = 3; i <= N - 10; i++) f[i] = (f[i - 1] + f[i - 2]) % mod;
  scanf("%lld%lld", &a, &b);
  for (long long i = 1; i <= a; i++) scanf("%lld", &s1[i]);
  build(1, 1, a);
  for (long long i = 1; i <= b; i++) {
    scanf("%lld%lld%lld", &opt, &x, &y);
    if (opt == 1)
      change(1, x, y);
    else
      printf("%lld\n", (query(1, x, y) + mod) % mod);
  }
  return 0;
}
