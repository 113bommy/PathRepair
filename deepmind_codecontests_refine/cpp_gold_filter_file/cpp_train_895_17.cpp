#include <bits/stdc++.h>
using namespace std;
const int Imx = 2147483647;
const long long Lbig = 2e18;
const int mod = 1e9 + 7;
struct fastio {
  char s[100000];
  int it, len;
  fastio() { it = len = 0; }
  inline char get() {
    if (it < len) return s[it++];
    it = 0;
    len = fread(s, 1, 100000, stdin);
    if (len == 0)
      return EOF;
    else
      return s[it++];
  }
  bool notend() {
    char c = get();
    while (c == ' ' || c == '\n') c = get();
    if (it > 0) it--;
    return c != EOF;
  }
} _buff;
inline long long getnum() {
  long long r = 0;
  bool ng = 0;
  char c;
  c = _buff.get();
  while (c != '-' && (c < '0' || c > '9')) c = _buff.get();
  if (c == '-') ng = 1, c = _buff.get();
  while (c >= '0' && c <= '9') r = r * 10 + c - '0', c = _buff.get();
  return ng ? -r : r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline char getreal() {
  char c = _buff.get();
  while (c == ' ' || c == '\n') c = _buff.get();
  return c;
}
bitset<4096> a[100111];
int n, k, q, w[12][100111];
int main() {
  n = getnum(), k = getnum(), q = getnum();
  for (int i = 0; i < k; i++) {
    for (int j = 1; j <= n; j++) {
      w[i][j] = getnum();
    }
  }
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < 4096; j++) a[i][j] = (j >> i) & 1;
  }
  int tot = k;
  while (q--) {
    int cmd, x, y;
    cmd = getnum(), x = getnum(), y = getnum();
    if (cmd == 1) {
      x--;
      y--;
      a[tot++] = a[x] | a[y];
    } else if (cmd == 2) {
      x--;
      y--;
      a[tot++] = a[x] & a[y];
    } else {
      x--;
      int ans = 0;
      for (int i = 0; i < k; i++) {
        int msk = 0;
        for (int j = 0; j < k; j++) msk |= (w[j][y] >= w[i][y]) << j;
        if (a[x][msk]) ans = max(ans, w[i][y]);
      }
      putnum(ans), putchar('\n');
    }
  }
  return 0;
}
