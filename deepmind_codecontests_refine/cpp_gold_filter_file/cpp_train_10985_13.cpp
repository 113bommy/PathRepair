#include <bits/stdc++.h>
template <class t>
inline void read(t &s) {
  s = 0;
  register int f = 1;
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
  int buf[21], top = 0;
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
inline bool ckmin(t &x, t y) {
  if (x > y) {
    x = y;
    return 1;
  }
  return 0;
}
template <class t>
inline bool ckmax(t &x, t y) {
  if (x < y) {
    x = y;
    return 1;
  }
  return 0;
}
inline int lowbit(int x) { return x & (-x); }
const int MaxN = 1e5 + 50;
long double p1[MaxN], p2[MaxN], sp1[MaxN], sp2[MaxN], a[MaxN], b[MaxN];
int n;
signed main(void) {
  read(n);
  for (int i = 1; i <= n; ++i) std::cin >> p1[i], sp1[i] = sp1[i - 1] + p1[i];
  for (int i = 1; i <= n; ++i) std::cin >> p2[i];
  for (int i = n; i; --i) sp2[i] = sp2[i + 1] + p2[i];
  for (int i = 1; i <= n; ++i) {
    register long double u = sp1[i] - sp2[i + 1] + 1.0L, v = sp1[i];
    register long double B = -u, C = v;
    register long double dlt = B * B - 4.0L * C + (1e-15L);
    assert(dlt >= 0);
    dlt = std::sqrt(dlt);
    register long double x = (-B - dlt) / 2.0L, y = (-B + dlt) / 2.0L;
    a[i] = std::min(x, y), b[i] = std::max(x, y);
  }
  for (int i = 1; i <= n; ++i) std::printf("%.7Lf ", a[i] - a[i - 1]);
  std::puts("");
  for (int i = 1; i <= n; ++i) std::printf("%.7Lf ", b[i] - b[i - 1]);
  std::puts("");
  return 0;
}
