#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-9;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 60;
const int mods = 1e9 + 7;
const int inv2 = (mods + 1) >> 1;
const int MAXN = 300005;
const int INF = 0x3f3f3f3f;
namespace FastIO {
constexpr int SIZE = (1 << 21) + 1;
int num = 0, f;
char ibuf[SIZE], obuf[SIZE], que[65], *iS, *iT, *oS = obuf,
                                                *oT = obuf + SIZE - 1, c;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char c) {
  *oS++ = c;
  if (oS == oT) flush();
}
inline void getc(char &c) {
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       !isdigit(c) && c != EOF;
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    ;
}
inline void reads(char *st) {
  char c;
  int n = 0;
  getc(st[++n]);
  for (c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++);
       isdigit(c);
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    st[++n] = c;
  st[n + 1] = '\0';
}
template <class I>
inline void read(I &x) {
  for (f = 1, c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c >= '0' && c <= '9';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = (x << 3) + (x << 1) + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (x < 0) putc('-'), x = -x;
  if (!x) putc('0');
  while (x) que[++num] = x % 10 + 48, x /= 10;
  while (num) putc(que[num--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_Flusher_;
}  // namespace FastIO
using FastIO ::print;
using FastIO ::putc;
using FastIO ::read;
using FastIO ::reads;
int f[15][16], tmp[15][16], cnt[16];
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
signed main() {
  int n, K, m;
  read(n), read(K), read(m);
  f[0][0] = 1;
  for (int i = 0; i < 1 << m; ++i) cnt[i] = cnt[i >> 1] + (i & 1);
  for (int i = n; i >= 1; --i) {
    for (int j = 0; j <= K; ++j)
      for (int k = 0; k < 1 << m; ++k) tmp[j][k] = f[j][k], f[j][k] = 0;
    for (int j = 0; j <= K; ++j)
      for (int k = 0; k < 1 << m; ++k) {
        f[j][k >> 1] = upd(f[j][k >> 1], tmp[j][k]);
        f[j + 1][(k >> 1) | (1 << (m - 1))] =
            upd(f[j + 1][(k >> 1) | (1 << (m - 1))],
                1ll * (cnt[k] + 1) * tmp[j][k]);
      }
  }
  int ans = 0;
  for (int i = 0; i < 1 << m; ++i) ans = upd(ans, f[K][i]);
  print(ans);
  return 0;
}
