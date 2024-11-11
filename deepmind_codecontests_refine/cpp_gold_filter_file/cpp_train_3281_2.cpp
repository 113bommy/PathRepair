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
const int MAXN = 50005;
const int MAXM = 4005;
const int MX = 1000000;
const int G = 3;
const int mods = 1e9 + 7;
const int Gi = (mods + 1) / G;
const int SZ = 62;
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
pair<long long, long long> b[MAXN], c[MAXN];
int nodenum, ch[MAXN * 20][2], bel[MAXN], L[MAXN], R[MAXN], S[MX + 5];
int id[MAXN], a[MAXN], Ans[305][305], mx[MAXN][305], sz, n, m;
void clear() {
  for (int i = 1; i <= nodenum; ++i) ch[i][0] = ch[i][1] = 0;
  nodenum = 1;
}
void insert(int x) {
  int nw = 1;
  for (int i = 19; i >= 0; --i) {
    if (!ch[nw][(x >> i) & 1]) ch[nw][(x >> i) & 1] = ++nodenum;
    nw = ch[nw][(x >> i) & 1];
  }
}
int query(int x) {
  int nw = 1, ans = 0;
  for (int i = 19; i >= 0; --i) {
    int t = (x >> i) & 1;
    if (ch[nw][t ^ 1])
      nw = ch[nw][t ^ 1], ans |= (1 << i);
    else
      nw = ch[nw][t];
  }
  return ans;
}
void Init() {
  for (int i = 1; i <= MX; ++i) S[i] = S[i - 1] ^ i;
  for (int i = 1; i <= n; ++i) bel[i] = (i - 1) / sz + 1;
  for (int i = 1; i <= n; ++i)
    if (!L[bel[i]]) L[bel[i]] = i;
  for (int i = n; i >= 1; --i)
    if (!R[bel[i]]) R[bel[i]] = i;
  for (int i = 1; i <= n; ++i) b[i] = make_pair(a[i], S[a[i]]);
  for (int i = 1; i <= bel[n]; ++i) sort(b + L[i], b + R[i] + 1);
  for (int i = 1; i <= n; ++i) c[i] = make_pair(a[i], S[a[i] - 1]);
  for (int i = 1; i <= bel[n]; ++i) sort(c + L[i], c + R[i] + 1);
}
void Solve() {
  for (int i = 1; i <= n; ++i) id[i] = i;
  sort(id + 1, id + n + 1, [&](int x, int y) { return a[x] < a[y]; });
  for (int i = 1; i <= bel[n]; ++i) {
    clear();
    for (int j = 1, nw = L[i]; j <= n; ++j) {
      while (nw <= R[i] && c[nw].first <= a[id[j]]) insert(c[nw++].second);
      upmax(mx[id[j]][i], query(S[a[id[j]]]));
    }
    clear();
    for (int j = n, nw = R[i]; j >= 1; --j) {
      while (nw >= L[i] && b[nw].first >= a[id[j]]) insert(b[nw--].second);
      upmax(mx[id[j]][i], query(S[a[id[j]] - 1]));
    }
  }
  for (int i = 1; i <= bel[n]; ++i)
    for (int j = 1; j <= bel[n]; ++j)
      for (int k = L[i]; k <= R[i]; ++k) upmax(Ans[i][j], mx[k][j]);
}
int get(int x, int y) {
  return a[x] <= a[y] ? (S[a[y]] ^ S[a[x] - 1]) : (S[a[x]] ^ S[a[y] - 1]);
}
int getans(int l, int r) {
  int ans = 0;
  if (bel[l] == bel[r]) {
    for (int i = l; i <= r; ++i)
      for (int j = i; j <= r; ++j) upmax(ans, get(i, j));
    return ans;
  }
  for (int i = l; i <= R[bel[l]]; ++i)
    for (int j = bel[l] + 1; j <= bel[r] - 1; ++j) upmax(ans, mx[i][j]);
  for (int i = L[bel[r]]; i <= r; ++i)
    for (int j = bel[l] + 1; j <= bel[r] - 1; ++j) upmax(ans, mx[i][j]);
  for (int i = bel[l] + 1; i <= bel[r] - 1; ++i)
    for (int j = i; j <= bel[r] - 1; ++j) upmax(ans, Ans[i][j]);
  for (int i = l; i <= R[bel[l]]; ++i)
    for (int j = i; j <= R[bel[l]]; ++j) upmax(ans, get(i, j));
  for (int i = L[bel[r]]; i <= r; ++i)
    for (int j = i; j <= r; ++j) upmax(ans, get(i, j));
  for (int i = l; i <= R[bel[l]]; ++i)
    for (int j = L[bel[r]]; j <= r; ++j) upmax(ans, get(i, j));
  return ans;
}
signed main() {
  read(n), read(m), sz = (int)sqrt(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  Init();
  Solve();
  while (m--) {
    int l, r;
    read(l), read(r);
    print(getans(l, r));
    putc('\n');
  }
  return 0;
}
