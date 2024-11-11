#include <bits/stdc++.h>
template <typename T>
inline void qr(T &x) {
  register char ch = getchar(), lst = ' ';
  while ((ch > '9') || (ch < '0')) lst = ch, ch = getchar();
  while ((ch >= '0') && (ch <= '9'))
    x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  if (lst == '-') x = -x;
}
namespace IO {
char buf[120];
}
template <typename T>
inline void qw(T x, const char aft, const bool pt) {
  if (x < 0) {
    x = -x, putchar('-');
  }
  register int top = 0;
  do {
    IO::buf[++top] = x % 10 + '0';
  } while (x /= 10);
  while (top) putchar(IO::buf[top--]);
  if (pt) putchar(aft);
}
template <typename T>
inline T mmax(const T a, const T b) {
  return a > b ? a : b;
}
template <typename T>
inline T mmin(const T a, const T b) {
  return a < b ? a : b;
}
template <typename T>
inline T mabs(const T a) {
  return a < 0 ? -a : a;
}
template <typename T>
inline void mswap(T &_a, T &_b) {
  T _temp = _a;
  _a = _b;
  _b = _temp;
}
const int maxn = 110;
const int fx[] = {1, 0, -1, 0};
const int fy[] = {0, 1, 0, -1};
int w, h, n, cnt;
int ans[10010];
bool cutup[maxn][maxn], cutrt[maxn][maxn], vis[maxn][maxn];
int dfs(const int x, const int y);
int main() {
  qr(w);
  qr(h);
  qr(n);
  int a, b, c, d;
  while (n--) {
    a = b = c = d = 0;
    qr(a);
    qr(b);
    qr(c);
    qr(d);
    if (a == c)
      for (register int j = b + 1; j <= d; ++j) cutup[a][j] = true;
    else
      for (register int j = a + 1; j <= c; ++j) cutrt[j][b] = true;
  }
  for (register int i = 1; i <= w; ++i) {
    for (register int j = 1; j <= h; ++j)
      if (!vis[i][j]) {
        ans[++cnt] = dfs(i, j);
      }
  }
  std::sort(ans + 1, ans + 1 + cnt);
  for (register int i = 1; i < cnt; ++i) qw(ans[i], ' ', true);
  qw(ans[cnt], '\n', true);
  return 0;
}
int dfs(const int x, const int y) {
  if (vis[x][y]) return 0;
  vis[x][y] = true;
  int _ans = 1;
  if ((x < w) && (!cutup[x][y])) _ans += dfs(x + 1, y);
  if ((y < h) && (!cutrt[x][y])) _ans += dfs(x, y + 1);
  if ((x > 1) && (!cutup[x - 1][y])) _ans += dfs(x - 1, y);
  if ((y > 1) && (!cutrt[x][y - 1])) _ans += dfs(x, y - 1);
  return _ans;
}
