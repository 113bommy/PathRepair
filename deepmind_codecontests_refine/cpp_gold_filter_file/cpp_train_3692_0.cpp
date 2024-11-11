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
  while (c <= 32) c = _buff.get();
  return c;
}
int n;
struct node {
  int fa, go[2];
  long long val, lzv, s, d, all;
  long long ssd;
  node() { fa = go[0] = go[1] = val = lzv = s = d = all = ssd = 0; }
  void addval(long long v) {
    all += 2 * v * d;
    lzv += v;
    val += v;
  }
} a[200111];
void pushdown(int p) {
  long long &lzv = a[p].lzv;
  if (lzv) {
    if (a[p].go[0]) a[a[p].go[0]].addval(lzv);
    if (a[p].go[1]) a[a[p].go[1]].addval(lzv);
    lzv = 0;
  }
}
void update(int p) {
  a[p].ssd = a[p].s * a[p].d + a[a[p].go[0]].ssd + a[a[p].go[1]].ssd;
}
int getdir(int p) {
  return a[a[p].fa].go[0] == p ? 0 : (a[a[p].fa].go[1] == p ? 1 : -1);
}
void rotate(int p, bool d) {
  int q = a[p].go[d];
  int r = a[q].go[d ^ 1];
  if (getdir(p) != -1) a[a[p].fa].go[getdir(p)] = q;
  a[q].go[d ^ 1] = p;
  a[p].go[d] = r;
  a[q].fa = a[p].fa;
  a[p].fa = q;
  if (r) a[r].fa = p;
  update(p);
}
void pushroute(int p) {
  if (getdir(p) != -1) pushroute(a[p].fa);
  pushdown(p);
}
void debug() {
  for (int p = 0; p <= n; p++) {
    cerr << p << ":" << a[p].go[0] << "," << a[p].go[1] << " " << a[p].fa
         << " val=" << a[p].val << " s=" << a[p].s << " d=" << a[p].d << " "
         << a[p].all << " ssd=" << a[p].ssd << endl;
  }
}
void splay(int p, int t = -1) {
  pushroute(p);
  while (getdir(p) != -1 && a[p].fa != t) {
    int q = a[p].fa, r = a[q].fa;
    int dq = getdir(p), dr = getdir(q);
    if (dr == -1 || r == t)
      rotate(q, dq);
    else {
      if (dq == dr)
        rotate(r, dr), rotate(q, dq);
      else
        rotate(q, dq), rotate(r, dr);
    }
  }
  update(p);
}
int leftmost(int p) {
  assert(a[p].go[0] >= 0);
  return a[p].go[0] > 0 ? leftmost(a[p].go[0]) : p;
}
int access(int p) {
  assert(p > 0);
  int ret = p;
  for (splay(p), a[p].go[1] = 0, a[p].d = a[p].val; a[p].fa; splay(p)) {
    splay(a[p].fa);
    int fa = a[p].fa, lm = leftmost(p);
    splay(lm);
    a[fa].d = a[fa].val - a[lm].val;
    splay(p);
    assert(a[p].fa > 0);
    a[a[p].fa].go[1] = p;
    update(a[p].fa);
    ret = a[p].fa;
  }
  return ret;
}
long long curans;
void subtree_addval(int p, long long v) {
  curans += 2 * a[p].ssd * v;
  a[p].addval(v);
}
void node_adds(int p, long long v) {
  access(p);
  curans += v * a[p].all;
  a[p].s += v;
  update(p);
}
void cut(int x, int p) {
  access(x);
  splay(p);
  a[p].d = a[p].val - a[x].val;
  assert(a[x].fa == p);
  a[p].go[1] = 0;
  a[x].fa = 0;
  update(p);
  subtree_addval(p, -a[x].val);
}
void link(int x, int p) {
  access(p);
  access(x);
  a[x].fa = p;
  a[p].d = a[p].val;
  update(p);
  subtree_addval(p, a[x].val);
}
int getlca(int x, int y) {
  access(x);
  return access(y);
}
int q, p[100111], s[100111];
int main() {
  n = getnum();
  for (int i = 2; i <= n; i++) p[i] = getnum();
  for (int i = 1; i <= n; i++) s[i] = getnum();
  for (int i = 1; i <= n; i++) {
    node_adds(i, s[i]);
    curans += s[i];
    a[i].val = a[i].d = a[i].all = 1;
    splay(i);
  }
  for (int i = 2; i <= n; i++) {
    link(i, p[i]);
  }
  q = getnum();
  printf("%.10lf\n", 1.0 * curans / n / n);
  for (int _ = 1; _ <= q; _++) {
    char op = getreal();
    int x, y;
    x = getnum(), y = getnum();
    if (op == 'P') {
      int lca = getlca(x, y);
      if (x == lca) swap(x, y);
      cut(x, p[x]);
      p[x] = y;
      link(x, p[x]);
    } else {
      node_adds(x, y - s[x]);
      s[x] = y;
    }
    printf("%.10lf\n", 1.0 * curans / n / n);
  }
  return 0;
}
