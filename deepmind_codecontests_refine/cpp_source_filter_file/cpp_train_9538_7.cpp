#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 500007;
class lctT {
 public:
  void link(int u, int v) {
    if (!iscon(u, v)) {
      croot(u);
      access(v);
      fa[u] = v;
      access(u);
    }
  }
  void cut(int u, int v) {
    croot(u);
    access(v);
    if (ch[v][0] == u) {
      ch[v][0] = fa[u] = 0;
      upd(v);
    }
  }
  int query(int u, int v) {
    croot(u);
    access(v);
    return data[v];
  }
  void upd(int u, int v, int x) {
    croot(u);
    access(v);
    tag[v] += x, nd[v] += x, data[v] += size[v] * x;
    upd(v);
  }

 private:
  void rot(int now) {
    int nf = fa[now], np = fa[nf], d = (ch[nf][1] == now);
    fa[now] = np;
    if (!isroot(nf)) ch[np][ch[np][1] == nf] = now;
    fa[ch[now][d ^ 1]] = nf, ch[nf][d] = ch[now][d ^ 1];
    fa[nf] = now, ch[now][d ^ 1] = nf;
    upd(nf), upd(now);
  }
  void splay(int now) {
    rev_push(now);
    int nf, np;
    while (!isroot(now)) {
      nf = fa[now], np = fa[nf];
      if (!isroot(nf))
        rot(((ch[np][0] == nf) == (ch[nf][0] == now)) ? nf : now);
      rot(now);
    }
  }
  void access(int now) {
    int tn = now, v = 0;
    while (now) {
      splay(now);
      ch[now][1] = v;
      upd(now);
      v = now, now = fa[now];
    }
    splay(tn);
  }
  void croot(int now) {
    access(now);
    rev[now] ^= 1;
  }
  int getroot(int now) {
    while (ch[now][0]) now = ch[now][0];
    splay(now);
    return now;
  }
  bool iscon(int u, int v) {
    croot(u);
    access(v);
    return getroot(v) == u;
  }
  bool isroot(int now) {
    return (!fa[now] ||
            (!((ch[fa[now]][0] == now) || (ch[fa[now]][1] == now))));
  }
  void push_down(int now) {
    if (rev[now]) {
      rev[ch[now][0]] ^= 1, rev[ch[now][1]] ^= 1;
      swap(ch[now][0], ch[now][1]);
      rev[now] = 0;
    }
    if (tag[now]) {
      if (ch[now][0])
        tag[ch[now][0]] += tag[now], nd[ch[now][0]] += tag[now],
            data[ch[now][0]] +=
            size[ch[now][0]] * static_cast<long long>(tag[now]);
      if (ch[now][1])
        tag[ch[now][1]] += tag[now], nd[ch[now][1]] += tag[now],
            data[ch[now][1]] +=
            size[ch[now][1]] * static_cast<long long>(tag[now]);
      tag[now] = 0;
    }
  }
  void rev_push(int now) {
    if (!isroot(now)) rev_push(fa[now]);
    push_down(now);
  }
  void upd(int now) {
    data[now] = data[ch[now][0]] + data[ch[now][1]] + nd[now];
    size[now] = size[ch[now][0]] + size[ch[now][1]] + 1;
  }
  int fa[MAXN], ch[MAXN][2], tag[MAXN], nd[MAXN], size[MAXN];
  long long data[MAXN];
  bool rev[MAXN];
} lct;
struct eT {
  void setd(int _u, int _v, int _l) { u = _u, v = _v, last = _l; }
  int u, v, last;
} edge[MAXN];
int n;
int ke, la[MAXN];
int fa[MAXN];
int lev[MAXN];
vector<int> ar[MAXN];
long long ans[MAXN];
void init();
void input();
void work();
void dfs(int now, int nl);
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &fa[i]);
}
void work() {
  int rt = -1;
  ke = 0;
  memset(la, -1, sizeof(la));
  for (int i = 1; i <= n; ++i) {
    if (!fa[i])
      rt = i;
    else {
      edge[ke].setd(fa[i], i, la[fa[i]]);
      la[fa[i]] = ke++;
      lct.link(fa[i], i);
    }
  }
  dfs(rt, 1);
  int size, now;
  for (int i = 2; i <= n; ++i) {
    size = ar[i].size();
    for (int j = 0; j < size; ++j) {
      now = ar[i][j];
      lct.upd(rt, fa[now], 1);
    }
    for (int j = 0; j < size; ++j) {
      now = ar[i][j];
      ans[now] = lct.query(rt, now);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%I64d ", ans[i]);
  putchar('\n');
}
void dfs(int now, int nl) {
  lev[now] = nl;
  ar[nl].push_back(now);
  for (int i = la[now]; ~i; i = edge[i].last) {
    dfs(edge[i].v, nl + 1);
  }
}
