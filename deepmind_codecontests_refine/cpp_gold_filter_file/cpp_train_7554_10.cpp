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
const int MAXN = 5005;
const int G = 3;
const int Gi = (mods + 1) / G;
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
       (c != '0' && c != '1') && c != EOF;
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
       c == '0' || c == '1';
       c = (iS == iT ? (iT = ((iS = ibuf) + fread(ibuf, 1, SIZE, stdin)),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    st[++n] = c;
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
int tmp[MAXN], g[MAXN], f[MAXN][15], n, m;
vector<int> e[MAXN], E[MAXN], P[MAXN];
int quick_pow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1ll * ret * x % mods;
    x = 1ll * x * x % mods;
  }
  return ret;
}
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
void dfs(int x, int father) {
  for (auto v : E[x]) {
    if (v == father) continue;
    P[x].push_back(v), dfs(v, x);
  }
}
void tree_dp(int x, int father) {
  for (auto v : e[x]) {
    if (v == father) continue;
    tree_dp(v, x);
  }
  for (int i = 1; i <= m; ++i) {
    int len = (int)P[i].size();
    for (int k = 0; k < 1 << len; ++k) g[k] = 0;
    g[0] = 1;
    for (auto v : e[x]) {
      if (v == father) continue;
      for (int k = 0; k < 1 << len; ++k) tmp[k] = g[k];
      for (int k = 0; k < 1 << len; ++k)
        for (int p = 0; p < len; ++p)
          if (!((k >> p) & 1))
            g[k | (1 << p)] =
                upd(g[k | (1 << p)], 1ll * tmp[k] * f[v][P[i][p]] % mods);
    }
    f[x][i] = g[(1 << len) - 1];
  }
}
void Tree_dp(int x, int father) {
  for (auto v : E[x]) {
    if (v == father) continue;
    Tree_dp(v, x);
  }
  for (int i = 1; i <= m; ++i) {
    int len = (int)P[i].size();
    for (int k = 0; k < 1 << len; ++k) g[k] = 0;
    g[0] = 1;
    for (auto v : E[x]) {
      if (v == father) continue;
      for (int k = 0; k < 1 << len; ++k) tmp[k] = g[k];
      for (int k = 0; k < 1 << len; ++k)
        for (int p = 0; p < len; ++p)
          if (!((k >> p) & 1))
            g[k | (1 << p)] =
                upd(g[k | (1 << p)], 1ll * tmp[k] * f[v][P[i][p]] % mods);
    }
    f[x][i] = g[(1 << len) - 1];
  }
}
signed main() {
  read(n);
  for (int i = 1, u, v; i < n; ++i)
    read(u), read(v), e[u].push_back(v), e[v].push_back(u);
  read(m);
  for (int i = 1, u, v; i < m; ++i)
    read(u), read(v), E[u].push_back(v), E[v].push_back(u);
  int ans = 0, _ans = 0;
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= m; ++j) P[j].clear();
    dfs(i, 0);
    tree_dp(1, 0);
    for (int j = 1; j <= n; ++j) ans = upd(ans, f[j][i]);
    Tree_dp(1, 0);
    _ans = upd(_ans, f[1][i]);
  }
  print(1ll * ans * quick_pow(_ans, mods - 2) % mods);
  return 0;
}
