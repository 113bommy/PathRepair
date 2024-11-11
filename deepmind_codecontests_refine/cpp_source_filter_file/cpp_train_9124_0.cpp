#include <bits/stdc++.h>
using namespace std;
namespace io {
const int SIZE = (1 << 21) + 1;
char ibuf[SIZE], *iS, *iT, obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1, c,
                                       qu[55];
int f, qr;
inline void flush() {
  fwrite(obuf, 1, oS - obuf, stdout);
  oS = obuf;
}
inline void putc(char x) {
  *oS++ = x;
  if (oS == oT) flush();
}
template <class I>
inline void read(I &x) {
  for (f = 1, c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                              (iS == iT ? EOF : *iS++))
                            : *iS++);
       c < '0' || c > '9';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    if (c == '-') f = -1;
  for (x = 0; c <= '9' && c >= '0';
       c = (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin),
                       (iS == iT ? EOF : *iS++))
                     : *iS++))
    x = x * 10 + (c & 15);
  x *= f;
}
template <class I>
inline void print(I x) {
  if (!x) putc('0');
  if (x < 0) putc('-'), x = -x;
  while (x) qu[++qr] = x % 10 + '0', x /= 10;
  while (qr) putc(qu[qr--]);
}
struct Flusher_ {
  ~Flusher_() { flush(); }
} io_flusher_;
}  // namespace io
using io ::print;
using io ::putc;
using io ::read;
const long long maxn = 1e5 + 100;
long long n, m;
char c[maxn];
long long fa[maxn], ch[maxn][26], bj[maxn], dep[maxn], id, root, now;
multiset<long long> a[maxn];
long long ans;
void add() {
  m = strlen(c + 1);
  now = root;
  for (long long i = 1; i <= m; i++) {
    if (ch[now][c[i] - 'a'] == 0) {
      ch[now][c[i] - 'a'] = ++id;
      fa[id] = now;
      dep[id] = dep[fa[id]] + 1;
    }
    now = ch[now][c[i] - 'a'];
  }
  bj[now] = 1;
}
multiset<long long>::iterator it;
void hb(long long x, long long y) {
  if (a[y].empty()) return;
  if (a[y].size() > a[x].size()) a[x].swap(a[y]);
  it = a[y].begin();
  for (; it != a[y].end(); ++it) {
    a[x].insert(*it);
  }
  a[y].clear();
}
void dfs(long long x) {
  long long f2 = 0;
  for (long long i = 0; i < 26; i++)
    if (ch[x][i]) {
      f2 = 1;
      dfs(ch[x][i]);
    }
  for (long long i = 0; i < 26; i++) {
    if (ch[x][i]) hb(x, ch[x][i]);
  }
  if (x == root) return;
  if (bj[x]) {
    a[x].insert(dep[x]);
    ans += dep[x];
    return;
  }
  it = a[x].end();
  --it;
  ans -= *it;
  a[x].erase(it);
  a[x].insert(dep[x]);
  ans += dep[x];
}
signed main() {
  read(n);
  root = id = 1;
  for (long long i = 1; i <= n; i++) scanf("%s", c + 1), add();
  dfs(root);
  printf("%lld\n", ans);
  return 0;
}
