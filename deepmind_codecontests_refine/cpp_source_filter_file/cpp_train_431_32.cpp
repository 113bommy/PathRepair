#include <bits/stdc++.h>
using namespace std;
char buf[1 << 21], *p1 = buf, *p2 = buf;
namespace wode {
template <typename T>
inline void read(T &x) {
  static char ch;
  bool f = 1;
  for (x = 0,
      ch = (p1 == p2 &&
                    (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                ? EOF
                : *p1++);
       !isdigit(ch);
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    if (ch == '-') f = 0;
  for (; isdigit(ch);
       x = (x << 1) + (x << 3) + (ch ^ 48),
       ch = (p1 == p2 &&
                     (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2)
                 ? EOF
                 : *p1++))
    ;
  x = f ? x : -x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
inline void print(T x, char ap) {
  print(x);
  if (ap) putchar(ap);
}
template <typename T>
inline T max(T x, T y) {
  return x < y ? y : x;
}
template <typename T>
inline T min(T x, T y) {
  return x < y ? x : y;
}
template <typename T>
inline void chkmax(T &x, T y) {
  x = x < y ? y : x;
}
template <typename T>
inline void chkmin(T &x, T y) {
  x = x < y ? x : y;
}
}  // namespace wode
using wode::chkmax;
using wode::chkmin;
using wode::print;
using wode::read;
int a[500001], b[500001], tot[500001], t, n, m, len, len1;
bool vis[300001];
int main() {
  read(t);
  while (t--) {
    memset(vis, false, 3 * n + 1);
    read(n), read(m), len = len1 = 0;
    for (register int i = 1; i <= m; ++i) read(a[i]), read(b[i]);
    for (register int i = 1; i <= m; ++i)
      if (!vis[a[i]] && !vis[b[i]])
        vis[a[i]] = vis[b[i]] = true, tot[++len] = i;
    if (len >= n) {
      puts("Mathcing");
      for (register int i = 1; i <= n; ++i) print(tot[i], ' ');
      puts("");
      continue;
    }
    puts("Indset");
    for (register int i = 1; i <= 3 * n; ++i) {
      if (!vis[i]) print(i, ' '), ++len1;
      if (len1 == n) break;
    }
    puts("");
  }
  return 0;
}
