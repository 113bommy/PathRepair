#include <bits/stdc++.h>
using namespace std;
inline void __CIN__() {
  ios::sync_with_stdio(false);
  cin.tie(0);
}
char buf;
inline int xint() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  int x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline long long xll() {
  while (buf = getchar(), buf < '0' || buf > '9')
    ;
  long long x = buf - '0';
  for (; buf = getchar(), buf >= '0' && buf <= '9'; x = x * 10 + buf - '0')
    ;
  return x;
}
inline string xstring() {
  while (buf = getchar(), buf == ' ' || buf == '\n')
    ;
  string x = "";
  for (x += buf; buf = getchar(), buf != ' ' && buf != '\n'; x += buf)
    ;
  return x;
}
int n, q, p1, p2;
int c[100005], s[100005];
inline void modify(int x, int v) {
  s[x] += v;
  for (; x <= n; x += x & -x) c[x] += v;
}
inline int query(int x) {
  int ans = 0;
  for (; x; x -= x & -x) ans += c[x];
  return ans;
}
int main() {
  n = xint();
  q = xint();
  for (int i = 1; i <= n; ++i) modify(i, 1);
  int l = 1, r = n, ck = 0;
  for (int i = 0; i < q; ++i) {
    if (xint() == 1) {
      p1 = xint();
      bool fg = p1 * 2 > r - l + 1;
      if (ck == 1)
        p1 = r - p1;
      else
        p1 = l + p1 - 1;
      int cl = p1 - l + 1, cr = r - p1;
      if (cl <= cr) {
        for (int i = 1; i <= p1; ++i) modify(2 * p1 + 1 - i, s[i]);
        l = p1 + 1;
      } else {
        for (int i = p1 + 1; i <= r; ++i) modify(2 * p1 + 1 - i, s[i]);
        r = p1;
      }
      ck ^= fg;
    } else {
      p1 = xint();
      p2 = xint();
      if (ck == 0) {
        printf("%d\n", query(p2 + l - 1) - query(p1 + l - 1));
      } else
        printf("%d\n", query(r - p1) - query(r - p2));
    }
  }
  return 0;
}
