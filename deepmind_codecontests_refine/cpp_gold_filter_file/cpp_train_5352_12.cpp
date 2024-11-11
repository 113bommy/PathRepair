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
const int MAXN = 100005;
const int MAXM = 4005;
const int MX = 100000;
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
int n, m, sz, cnt = 0, Cnt = 0, Mn[MAXN], Mx[MAXN], nxt[MAXN], pre[MAXN],
              lst[MAXN], a[MAXN], Ans[MAXN], L[MAXN], flag[MAXN];
struct Qnode {
  int l, r, id;
} Q[MAXN];
int compare(Qnode a, Qnode b) {
  if ((a.l - 1) / sz != (b.l - 1) / sz) return (a.l - 1) / sz < (b.l - 1) / sz;
  return a.r < b.r;
}
void Add(int x) {
  if (Mx[a[x]] == 0)
    Mx[a[x]] = Mn[a[x]] = x, flag[a[x]] = 1, ++cnt, ++Cnt;
  else {
    upmax(Mx[a[x]], x);
    upmin(Mn[a[x]], x);
    if (L[Mx[a[x]]] > Mn[a[x]]) Cnt -= flag[a[x]], flag[a[x]] = 0;
  }
}
void Del(int x) {
  if (Mx[a[x]] == Mn[a[x]])
    Mx[a[x]] = 0, Mn[a[x]] = INF, flag[a[x]] = 0, --cnt, --Cnt;
  else {
    if (Mx[a[x]] == x) Mx[a[x]] = pre[Mx[a[x]]];
    if (Mn[a[x]] == x) Mn[a[x]] = nxt[Mn[a[x]]];
    if (L[Mx[a[x]]] <= Mn[a[x]]) Cnt += flag[a[x]] ^ 1, flag[a[x]] = 1;
  }
}
void Init() {
  for (int i = 1; i <= MX; ++i) Mx[i] = 0, Mn[i] = INF;
  for (int i = 1; i <= MX; ++i) lst[i] = -1;
  for (int i = 1; i <= n; ++i) pre[i] = lst[a[i]], lst[a[i]] = i;
  for (int i = 1; i <= MX; ++i) lst[i] = -1;
  for (int i = n; i >= 1; --i) nxt[i] = lst[a[i]], lst[a[i]] = i;
  for (int i = 1; i <= MX; ++i) lst[i] = -1;
  for (int i = 1; i <= n; ++i) {
    if (pre[i] == -1)
      L[i] = i;
    else if (i - pre[i] == lst[a[i]])
      L[i] = L[pre[i]];
    else
      L[i] = pre[i], lst[a[i]] = i - pre[i];
  }
}
signed main() {
  read(n), sz = (int)sqrt(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  Init();
  read(m);
  for (int i = 1; i <= m; ++i) read(Q[i].l), read(Q[i].r), Q[i].id = i;
  sort(Q + 1, Q + m + 1, compare);
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    while (l > Q[i].l) Add(--l);
    while (r < Q[i].r) Add(++r);
    while (l < Q[i].l) Del(l++);
    while (r > Q[i].r) Del(r--);
    Ans[Q[i].id] = cnt - (Cnt > 0);
  }
  for (int i = 1; i <= m; ++i) print(Ans[i] + 1), putc('\n');
  return 0;
}
