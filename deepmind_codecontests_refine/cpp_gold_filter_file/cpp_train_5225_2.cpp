#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y <= x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x <= y ? x = y, 1 : 0;
}
const long double eps = 1e-9;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 60;
const int MAXN = 300005;
const int MAXM = 4005;
const int MAXP = 7000000;
const int MX = 20;
const int G = 3;
const int mods = 998244353;
const int Gi = (mods + 1) / G;
const int SZ = 10;
const int inv2 = (mods + 1) >> 1;
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
       (c == ' ' || c == '\0' || c == '\n') && c != EOF;
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
       c != ' ' && c != '\0' && c != '\n' && c != EOF;
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    st[++n] = c;
  st[++n] = '\0';
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
inline void putstr(string st) {
  for (int i = 0; i < (int)st.size(); ++i) putc(st[i]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_Flusher_;
}  // namespace FastIO
using FastIO ::getc;
using FastIO ::print;
using FastIO ::putc;
using FastIO ::putstr;
using FastIO ::read;
using FastIO ::reads;
long long c[505][505];
vector<pair<long long, long long> > U[505][505], R[505][505];
long long f[2][505][505][2];
signed main() {
  int n, m, K;
  read(n), read(m), read(K);
  while (K--) {
    int x, y, d, t, e, S = 0;
    read(x), read(y), read(d), read(t), read(e);
    if (x + y >= t && (x + y - t) % 4 == 0) S |= 1, c[x][y] += e;
    if (x + y >= t + 1 && (x + y - t) % 4 == 1) S |= 2, c[x + d][y - d] += e;
    if (x + y + d >= t + 2 && (x + y + d - t) % 4 == 2)
      S |= 4, c[x + d][y] += e;
    if (x + y + d >= t + 3 && (x + y + d - t) % 4 == 3)
      S |= 8, c[x][y + d] += e;
    if (S == 5) R[x + d][y].push_back(make_pair(d, e));
    if (S == 6) U[x + d][y].push_back(make_pair(d, e));
    if (S == 9) U[x][y + d].push_back(make_pair(d, e));
  }
  memset(f, INF, sizeof f);
  int nw = 0;
  f[0][0][0][0] = f[0][0][0][1] = 0;
  for (int i = 0; i < n; ++i) {
    memset(f[nw ^ 1], INF, sizeof f[nw ^ 1]);
    for (int j = 0; j < m; ++j) {
      for (int k = 0; k <= i; ++k) {
        long long &t = f[nw][j][k][0];
        t += c[i][j];
        for (auto v : R[i][j])
          if (v.first <= k) t -= v.second;
        upmin(f[nw ^ 1][j][k + 1][0], t);
        upmin(f[nw][j + 1][1][1], t);
      }
      for (int k = 0; k <= j; ++k) {
        long long &t = f[nw][j][k][1];
        t += c[i][j];
        for (auto v : U[i][j])
          if (v.first <= k) t -= v.second;
        upmin(f[nw][j + 1][k + 1][1], t);
        upmin(f[nw ^ 1][j][1][0], t);
      }
    }
    nw ^= 1;
  }
  long long ans = loo;
  for (int i = 0; i < n; ++i) upmin(ans, f[nw ^ 1][m - 1][i][0]);
  for (int i = 0; i < m; ++i) upmin(ans, f[nw ^ 1][m - 1][i][1]);
  print(ans);
  return 0;
}
