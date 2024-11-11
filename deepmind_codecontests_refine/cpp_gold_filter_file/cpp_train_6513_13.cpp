#include <bits/stdc++.h>
using namespace std;
char nc() {
  static char buf[1 << 25], *p = buf, *q = buf;
  if (p == q && (q = (p = buf) + fread(buf, 1, 1 << 25, stdin), p == q))
    return EOF;
  return *p++;
}
template <class T>
void rd(T& x) {
  short f = 1;
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
}
template <class T>
void wr(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) wr(x / 10);
  putchar(x % 10 + 48);
}
int n, a, b, k;
char s[200010];
int pos[200010];
signed main() {
  rd(n), rd(a), rd(b), rd(k);
  scanf("%s", s + 1);
  int ans = 0, d = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '0') {
      if (++d == b) {
        d = 0;
        pos[++ans] = i;
      }
    } else
      d = 0;
  }
  ans -= a - 1;
  wr(ans), putchar('\n');
  for (int i = 1; i <= ans; i++) wr(pos[i]), putchar(' ');
}
