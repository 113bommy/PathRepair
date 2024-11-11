#include <bits/stdc++.h>
using namespace std;
const int Len = 2333333;
char buf[Len], *p1 = buf, *p2 = buf, duf[Len], *q1 = duf;
inline char gc();
inline int rd();
inline void pc(char c);
inline void rt(int x);
inline void flush();
template <class T>
inline T Max(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T Min(T a, T b) {
  return a < b ? a : b;
}
int n, d, l, r, s, ans, p[30000 + 5], dp[30000 + 5][333];
int main() {
  n = rd(), l = r = s = d = rd();
  while (n--) ++p[rd()];
  while (l > 1 && s + l - 1 <= 30000) s += --l;
  s = d, memset(dp, 128, sizeof(dp));
  while (s + r + 1 <= 30000) s += ++r;
  dp[d][d - l + 1] = ans = p[d];
  for (register int i = d + 1; i <= 30000; ++i)
    for (register int j = Min(r, i - 1); j >= l; --j) {
      dp[i][j - l + 1] = Max(Max(dp[i - j][j - l], dp[i - j][j - l + 1]),
                             dp[i - j][j - l + 2]) +
                         p[i],
                    ans = Max(ans, dp[i][j - l + 1]);
    }
  rt(ans);
  return flush(), 0;
}
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, Len, stdin), p1 == p2)
             ? -1
             : *p1++;
}
inline int rd() {
  char c;
  while (!isdigit(c = gc()) && c != '-')
    ;
  int f = c == '-' ? c = gc(), 1 : 0, x = c ^ 48;
  while (isdigit(c = gc())) x = ((x + (x << 2)) << 1) + (c ^ 48);
  return f ? -x : x;
}
inline void pc(char c) {
  q1 == duf + Len &&fwrite(q1 = duf, 1, Len, stdout), *q1++ = c;
}
inline void rt(int x) {
  x < 0 ? pc('-'), x = -x : 0, pc((x >= 10 ? rt(x / 10), x % 10 : x) + 48);
}
inline void flush() { fwrite(duf, 1, q1 - duf, stdout); }
