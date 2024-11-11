#include <bits/stdc++.h>
using namespace std;
namespace io {
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
template <class I>
inline void gi(I &x) {
  for (c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
}
template <class I>
inline void print(I &x) {
  if (!x) putc('0');
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
}  // namespace io
using io ::gi;
using io ::print;
using io ::putc;
int n, num, K, sz[110], h[110], f[110][110][110], tmp[110][110], fac[110],
    inv[110], g[110];
struct node {
  int to, next;
} mp[110 << 1];
inline void ins(int x, int y) {
  mp[++num].to = y;
  mp[num].next = h[x];
  h[x] = num;
  mp[++num].to = x;
  mp[num].next = h[y];
  h[y] = num;
}
inline int add(int x, int y) {
  return x + y >= 1000000007 ? x + y - 1000000007 : x + y;
}
inline int dec(int x, int y) { return x < y ? x - y + 1000000007 : x - y; }
inline int qpow(int x, int y) {
  int t = 1;
  while (y) {
    if (y & 1) t = 1ll * t * x % 1000000007;
    x = 1ll * x * x % 1000000007;
    y >>= 1;
  }
  return t;
}
void dfs(int x, int fa, int szz) {
  sz[x] = 1;
  f[x][1][1] = 1;
  for (int i = h[x]; i; i = mp[i].next) {
    int y = mp[i].to;
    if (y == fa) continue;
    dfs(y, x, szz);
    for (int j = min(szz, sz[x]); j; --j) {
      for (int t1 = sz[x]; t1; --t1) {
        if (!f[x][j][t1]) continue;
        for (int k = min(szz, sz[y]); k; --k) {
          for (int t2 = sz[y]; t2; --t2) {
            tmp[j + k][t1] =
                add(tmp[j + k][t1], 1ll * f[x][j][t1] * f[y][k][t2] %
                                        1000000007 * t2 % 1000000007);
            tmp[j + k - 1][t1 + t2] =
                add(tmp[j + k - 1][t1 + t2],
                    1ll * f[x][j][t1] * f[y][k][t2] % 1000000007);
          }
        }
      }
    }
    sz[x] += sz[y];
    for (int j = 1; j <= min(szz, sz[x]); ++j)
      for (int k = sz[x]; k; --k) f[x][j][k] = tmp[j][k], tmp[j][k] = 0;
  }
}
inline int C(int x, int y) {
  return 1ll * fac[x] * inv[y] % 1000000007 * inv[x - y] % 1000000007;
}
int main() {
  gi(n);
  for (int i = 1; i < n; ++i) {
    int x, y;
    gi(x);
    gi(y);
    ins(x, y);
  }
  dfs(1, 0, n);
  g[n - 1] = 1;
  for (int j = 0; j <= n - 2; ++j) {
    for (int i = 1; i <= n; ++i) {
      g[j] = add(g[j], 1ll * f[1][n - j][i] * i % 1000000007);
    }
    if (n - j - 2 >= 0) g[j] = 1ll * g[j] * qpow(n, n - j - 2) % 1000000007;
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % 1000000007;
  inv[n] = qpow(fac[n], 1000000007 - 2);
  for (int i = n; i; --i) inv[i - 1] = 1ll * inv[i] * i % 1000000007;
  for (int j = 0; j < n; ++j) {
    int ans = g[j];
    for (int i = K + 1, tag = -1; i < n; ++i, tag = -tag) {
      if (tag == -1)
        ans = dec(ans, 1ll * C(i, K) * g[i] % 1000000007);
      else
        ans = add(ans, 1ll * C(i, K) * g[i] % 1000000007);
    }
    print(ans);
    putc(' ');
  }
  io::flush();
  return 0;
}
