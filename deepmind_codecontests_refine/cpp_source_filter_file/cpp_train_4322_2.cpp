#include <bits/stdc++.h>
const long long MaxN = 2050;
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
const double eps = 1e-9;
double f[MaxN][MaxN][2][2], p;
long long a[MaxN], pre[MaxN], nxt[MaxN], n, h;
inline double dfs(long long l, long long r, long long x, long long y) {
  if (l > r) return 0;
  if (f[l][r][x][y] > eps) return f[l][r][x][y];
  register double s = 0;
  s += 0.5 * p * (dfs(l + 1, r, 0, y) + std::min(a[l] - a[l - 1] - x * h, h));
  s += 0.5 * (1 - p) *
       (dfs(l, r - 1, x, 0) + std::min(a[r + 1] - a[r] - y * h, h));
  if (nxt[l] >= r)
    s += 0.5 * (1 - p) * (a[r] - a[l] + std::min(a[r + 1] - a[r] - x * h, h));
  else
    s += 0.5 * (1 - p) * (dfs(nxt[l] + 1, r, 1, y) + a[nxt[l]] - a[l] + h);
  if (pre[r] <= l)
    s += 0.5 * p * (a[r] - a[l] + std::min(a[l] - a[l - 1] - y * h, h));
  else
    s += 0.5 * p * (dfs(l, pre[r] - 1, x, 1) + a[r] - a[pre[r]] + h);
  return f[l][r][x][y] = s;
}
signed main(void) {
  read(n, h);
  std::cin >> p;
  for (long long i = 1; i <= n; ++i) read(a[i]);
  std::sort(a + 1, a + n + 1);
  a[0] = -1e18, a[n + 1] = 1e18;
  for (long long i = 1; i <= n; ++i) {
    pre[i] = nxt[i] = i;
    for (long long j = i + 1; j <= n; ++j)
      if (a[j] - a[j - 1] < h)
        nxt[i] = j;
      else
        break;
    for (long long j = i - 1; j; --j)
      if (a[j + 1] - a[j] < h)
        pre[i] = j;
      else
        break;
  }
  std::printf("%.99lf\n", dfs(1, n, 0, 0));
  return 0;
}
