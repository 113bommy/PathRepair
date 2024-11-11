#include <bits/stdc++.h>
namespace FastIO {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
inline void wrap() {
  *oS++ = '\n';
  if (oS == oT) flush();
}
template <class I>
inline void gi(I &x) {
  I sign = 1;
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') sign = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= sign;
}
inline int gi() {
  int x, sign = 1;
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') sign = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  return x * sign;
}
inline long long gl() {
  long long x, sign = 1;
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') sign = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  return x * sign;
}
template <class I>
inline void print(I &x) {
  if (!x) putc('0');
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
template <class I>
inline void println(I &x) {
  if (!x) putc('0');
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
  wrap();
}
}  // namespace FastIO
using namespace std;
const int N = 2000;
int n, m, same[N + 5][N + 5], len[N + 5][N + 5];
char s[N + 5][N + 5];
long long ans;
struct Node {
  int a, b, c, l;
  bool operator==(const Node &rhs) const {
    return a == rhs.a && b == rhs.b && c == rhs.c && l == rhs.l;
  }
} a[N + 5][N + 5];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
  for (int j = 1; j <= m; ++j)
    for (int i = n, l; i >= 1; --i) {
      same[i][j] = (s[i][j] != s[i + 1][j] ? 1 : same[i + 1][j] + 1);
      l = same[i][j];
      if (same[i + l][j] == l && same[i + 2 * l][j] >= l &&
          s[i][j] != s[i + l][j] && s[i + l][j] != s[i + 2 * l][j])
        a[i][j] = Node{s[i][j], s[i + l][j], s[i + 2 * l][j], l};
      else
        a[i][j] = Node{s[i][j], s[i + l][j], s[i + 2 * l][j], 0};
    }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (a[i][j].l == 0)
        len[i][j] = 0;
      else {
        len[i][j] = (a[i][j] == a[i][j - 1] ? len[i][j - 1] + 1 : 1);
        ans += len[i][j];
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
