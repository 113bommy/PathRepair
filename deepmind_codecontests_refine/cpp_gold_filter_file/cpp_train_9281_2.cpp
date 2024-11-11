#include <bits/stdc++.h>
template <class t>
inline void read(t &s) {
  s = 0;
  register long long f = 1;
  register char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
  s *= f;
  return;
}
template <class t, class... A>
inline void read(t &x, A &...a) {
  read(x);
  read(a...);
}
template <class t>
inline void write(t x) {
  if (x < 0) putchar('-'), x = -x;
  long long buf[21], top = 0;
  while (x) buf[++top] = x % 10, x /= 10;
  if (!top) buf[++top] = 0;
  while (top) putchar(buf[top--] ^ '0');
  return;
}
inline void setIn(std::string s) {
  freopen(s.c_str(), "r", stdin);
  return;
}
inline void setOut(std::string s) {
  freopen(s.c_str(), "w", stdout);
  return;
}
inline void setIO(std::string s = "") {
  setIn(s + ".in");
  setOut(s + ".out");
  return;
}
template <class t>
inline bool checkmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool checkmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline long long lowbit(long long x) { return x & (-x); }
const long long MaxN = 5e5 + 50;
const long long p = 1e9 + 7;
std::vector<long long> dr;
long long a[MaxN], b[MaxN], cnt, n;
struct BIT {
  long long tr[MaxN];
  inline void add(long long x, long long k) {
    while (x <= cnt) (tr[x] += k) >= p && (tr[x] -= p), x += lowbit(x);
  }
  inline long long ask(long long x) {
    register long long res = 0;
    while (x) (res += tr[x]) >= p && (res -= p), x ^= lowbit(x);
    return res;
  }
} pre, suf;
signed main(void) {
  read(n);
  for (long long i = 1; i <= n; ++i) read(a[i]), dr.push_back(a[i]);
  std::sort((dr).begin(), (dr).end()),
      dr.erase(std::unique((dr).begin(), (dr).end()), dr.end());
  for (long long i = 1; i <= n; ++i)
    b[i] = std::lower_bound((dr).begin(), (dr).end(), a[i]) - dr.begin() + 1;
  cnt = (long long)dr.size();
  for (long long i = 1; i <= n; ++i) suf.add(b[i], n - i + 1);
  register long long ans = 0;
  for (long long i = 1; i <= n; ++i) {
    suf.add(b[i], p - (n - i + 1));
    (ans += (i * (n - i + 1) % p + (n - i + 1) * pre.ask(b[i] - 1) % p +
             i * suf.ask(b[i] - 1) % p) %
            p * a[i] % p) %= p;
    pre.add(b[i], i);
  }
  write(ans), std::puts("");
  return 0;
}
