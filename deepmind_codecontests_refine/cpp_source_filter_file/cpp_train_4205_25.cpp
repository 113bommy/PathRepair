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
inline int lowbit(int x) { return x & (-x); }
signed main(void) {
  int n, m;
  read(n, m);
  if (m == 3 && (n > 4)) return std::puts("-1"), 0;
  for (int i = 1; i <= m; ++i)
    write(i - 1), std::putchar(32), write(i * (i - 1) / 2), std::puts("");
  register int x = n - m;
  for (int i = m; i > m - x; --i)
    write(100000 + i - 1), std::putchar(32), write(i * (i - 1) / 2),
        std::puts("");
  return 0;
}
