#include <bits/stdc++.h>
using namespace std;
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
  while (c <= 32) c = _buff.get();
  return c;
}
const int maxn = 500111;
const int mod = 1e9 + 7;
long long qpow(long long x, long long k) {
  return k == 0 ? 1
                : 1ll * qpow(1ll * x * x % mod, k >> 1) * (k & 1 ? x : 1) % mod;
}
struct node {
  int mn, mx;
  node *tl, *tr;
  int ladj, radj, ans, l_ask_r, r_ask_l;
  void init(int v) {
    mn = mx = v;
    tl = tr = NULL;
    ans = 0;
    l_ask_r = r_ask_l = ans = 0;
    ladj = radj = -233;
  }
  void compute() {
    mn = min(tl->mn, tr->mn);
    mx = max(tl->mx, tr->mx);
    l_ask_r = tr->query(tl->mn, -1);
    r_ask_l = tl->query(1e7, tr->mx);
    if (tl->tr) {
      tl->tr->radj = tr->mx;
      tl->tr->ladj = -233;
      tl->tr->ans = tl->tr->query(tl->tl->mn, tr->mx);
    }
    if (tr->tl) {
      tr->tl->ladj = tl->mn;
      tr->tl->radj = -233;
      tr->tl->ans = tr->tl->query(tl->mn, tr->tr->mx);
    }
  }
  int get_ans() { return query(1e7, -1) + 1; }
  int query(int x, int y) {
    if (tl == NULL) return 0;
    if (x <= y) return 0;
    if (x <= mn || mx <= y) return 0;
    int ret = (min(x, tl->mn) > max(y, tr->mx));
    if (x >= tl->mx && max(y, tr->mx) == tr->mx)
      ret += r_ask_l;
    else if (x == tr->ladj && max(y, tr->mx) == tr->mx)
      ret += tl->ans;
    else
      ret += tl->query(x, max(y, tr->mx));
    if (y <= tr->mn && min(x, tl->mn) == tl->mn)
      ret += l_ask_r;
    else if (y == tl->radj && min(x, tl->mn) == tl->mn)
      ret += tr->ans;
    else
      ret += tr->query(min(x, tl->mn), y);
    return ret;
  }
};
int n, q;
int a[maxn];
node *build_single(int v) {
  node *ret = new node;
  ret->init(v);
  return ret;
}
node *build(int l, int r) {
  if (l == r) return build_single(a[l]);
  node *ret = new node;
  int m = l + r >> 1;
  ret->tl = build(l, m);
  ret->tr = build(m + 1, r);
  ret->compute();
  return ret;
}
void modify(int x, int v, node *p, int l, int r) {
  if (l == r) {
    p->init(v);
    return;
  }
  int m = l + r >> 1;
  if (x <= m)
    modify(x, v, p->tl, l, m);
  else
    modify(x, v, p->tr, m + 1, r);
  p->compute();
}
int main() {
  n = getnum(), q = getnum();
  for (int i = 1; i <= n; i++) {
    a[i] = getnum();
  }
  node *rt = build(1, n);
  for (int i = 1; i <= q; i++) {
    int x, v;
    x = getnum(), v = getnum();
    modify(x, v, rt, 1, n);
    putnum(rt->get_ans()), putchar('\n');
  }
  return 0;
}
