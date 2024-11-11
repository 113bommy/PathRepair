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
const int MAXN = 500005;
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
       !isalpha(c) && c != EOF;
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
       isalpha(c);
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
char st[1005], ST[1005];
long long f[1005][1005];
int ch[MAXN][26], num = 0, n, m, K, nodenum = 1, a[MAXN];
pair<int, int> flag[MAXN];
void solve(int x) {
  if (!x) return;
  for (int i = 25; i >= 0; --i) solve(ch[x][i]);
  if (flag[x].first) a[++num] = x;
}
void insert(int l, int r) {
  int nw = 1;
  for (int i = l; i <= r; ++i) {
    if (!ch[nw][st[i] - 'a']) ch[nw][st[i] - 'a'] = ++nodenum;
    nw = ch[nw][st[i] - 'a'];
  }
  flag[nw] = make_pair(l, r);
}
long long check(int x) {
  int len = 0;
  for (int i = flag[a[x]].first; i <= flag[a[x]].second; ++i) ST[++len] = st[i];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= m; ++j) f[i][j] = 0;
  f[0][0] = 1;
  for (int i = 0; i < n; ++i) {
    int id = len;
    for (int j = 1; j <= len && i + j - 1 <= n; ++j)
      if (st[i + j] < ST[j]) {
        id = INF;
        break;
      } else if (st[i + j] > ST[j]) {
        id = j;
        break;
      }
    if (i + id <= n) {
      for (int j = 0; j < m; ++j)
        if (f[i + id][j + 1] < loo) f[i + id][j + 1] += f[i][j];
    }
    for (int j = 1; j <= m; ++j)
      if (f[i + 1][j] < loo) f[i + 1][j] += f[i][j];
  }
  return f[n][m];
}
signed main() {
  read(n), read(m), read(K), reads(st);
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) insert(i, j);
  solve(1);
  int l = 1, r = num;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid) >= K)
      r = mid;
    else
      l = mid + 1;
  }
  for (int i = flag[a[l]].first; i <= flag[a[l]].second; ++i) putc(st[i]);
  return 0;
}
