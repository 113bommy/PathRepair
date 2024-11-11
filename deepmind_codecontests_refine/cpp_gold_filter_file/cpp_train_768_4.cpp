#include <bits/stdc++.h>
char ch;
inline void read(int &x) {
  x = 0;
  ch = getchar();
  while (ch <= 32) ch = getchar();
  while (ch > 32) x = x * 10 + ch - 48, ch = getchar();
};
struct splaynode {
  splaynode *s[2], *fa;
  bool rev;
  int x;
  int tag;
  inline void add_rev_tag() {
    rev ^= 1;
    splaynode *t = s[0];
    s[0] = s[1];
    s[1] = t;
  };
  inline void add_tag(int d) {
    x += d;
    tag += d;
  };
  inline void down() {
    if (rev) {
      if (s[0]) s[0]->add_rev_tag();
      if (s[1]) s[1]->add_rev_tag();
      rev = 0;
    };
    if (s[0]) s[0]->add_tag(tag);
    if (s[1]) s[1]->add_tag(tag);
    tag = 0;
  };
};
splaynode lct[100005];
inline int get_parent(splaynode *x, splaynode *&fa) {
  return (fa = x->fa) ? fa->s[0] == x ? 0 : fa->s[1] == x ? 1 : -1 : -1;
};
inline void rotate(splaynode *x) {
  int t1, t2;
  splaynode *fa, *gfa;
  t1 = get_parent(x, fa);
  t2 = get_parent(fa, gfa);
  fa->down();
  x->down();
  if ((fa->s[t1] = x->s[t1 ^ 1])) fa->s[t1]->fa = fa;
  fa->fa = x;
  x->fa = gfa;
  x->s[t1 ^ 1] = fa;
  if (t2 != -1) gfa->s[t2] = x;
};
inline splaynode *splay(splaynode *x) {
  while (1) {
    int t1, t2;
    splaynode *fa, *gfa;
    t1 = get_parent(x, fa);
    if (t1 == -1) break;
    t2 = get_parent(fa, gfa);
    if (t2 == -1) {
      rotate(x);
      break;
    } else if (t1 == t2) {
      rotate(fa);
      rotate(x);
    } else {
      rotate(x);
      rotate(x);
    };
  };
  x->down();
  return x;
};
inline splaynode *access(splaynode *x) {
  splaynode *ret = NULL;
  while (x) {
    splay(x)->s[1] = ret;
    ret = x;
    x = x->fa;
  };
  return ret;
};
inline void setroot(int x) { access(lct + x)->add_rev_tag(); };
int n, m;
int a[100005];
bool _a[100005];
struct edge {
  edge *next;
  int y, w;
};
edge *se[100005], e[100005 * 2], *etot = e;
inline void addedge(int x, int y, int w) {
  *++etot = (edge){se[x], y, w};
  se[x] = etot;
};
inline void dfs_(int x, int last) {
  edge *te = se[x];
  while (te) {
    int ty = te->y;
    if (ty ^ last) {
      lct[ty].fa = lct + x;
      dfs_(ty, x);
    };
    te = te->next;
  };
};
inline void init() { dfs_(1, 0); };
int _last[100005];
int dist[100005];
inline void dfs0(int x, int last) {
  edge *te = se[x];
  while (te) {
    int ty = te->y;
    if (ty ^ last) {
      dist[ty] = dist[x] + te->w;
      _last[ty] = x;
      dfs0(ty, x);
    };
    te = te->next;
  };
};
inline void solve1(int);
inline void solve2(int, int);
inline void solve__();
inline void solve() {
  dist[a[1]] = 0;
  dfs0(a[1], 0);
  int i;
  int ma = 1;
  for (i = 1; i <= m; i++) {
    if (dist[a[i]] > dist[a[ma]]) ma = i;
  };
  int A = a[ma];
  dist[A] = 0;
  dfs0(A, 0);
  int B = A;
  for (i = 1; i <= m; i++) {
    if (dist[a[i]] > dist[B]) B = a[i];
  };
  int d = dist[B];
  int t = B;
  int last = B;
  while (1) {
    t = _last[t];
    if (dist[t] * 2 == d) {
      solve1(t);
      break;
    };
    if (dist[t] * 2 < d) {
      solve2(t, last);
      break;
    };
    last = t;
  };
  solve__();
};
int mdist[100005], mdistlca[100005];
inline void dfs(int x, int last) {
  int m = _a[x] ? 0 : -0x3f3f3f3f, mlca = x;
  edge *te = se[x];
  while (te) {
    int ty = te->y;
    if (ty ^ last) {
      dfs(ty, x);
      int t = te->w + mdist[ty];
      if (t > m) {
        m = t;
        mlca = mdistlca[ty];
      } else if (t == m) {
        mlca = x;
      };
    };
    te = te->next;
  };
  mdist[x] = m;
  mdistlca[x] = mlca;
};
inline void dfs2(int x, int last) {
  if (_a[x]) {
    access(lct + x)->add_tag(1);
  };
  edge *te = se[x];
  while (te) {
    int ty = te->y;
    if (ty ^ last) {
      dfs2(ty, x);
    };
    te = te->next;
  };
};
inline void solve1(int A) {
  dfs(A, 0);
  int m = 0, l1 = 0, l2 = 0, l3 = 0;
  int _l1 = 0, _l2 = 0;
  edge *te = se[A];
  while (te) {
    int ty = te->y;
    int t = mdist[ty] + te->w;
    if (t > m) {
      m = t;
      _l1 = ty;
      l1 = mdistlca[ty];
      l2 = l3 = 0;
    } else if (t == m) {
      if (!l2) {
        _l2 = ty;
        l2 = mdistlca[ty];
      } else {
        l3 = ty;
      };
    };
    te = te->next;
  };
  if (l3) {
    setroot(A);
    dfs2(A, 0);
  } else {
    edge *te = se[A];
    while (te) {
      int ty = te->y;
      if (ty == _l1) {
        setroot(l2);
      } else if (ty == _l2) {
        setroot(l1);
      } else {
        setroot(A);
      };
      dfs2(ty, A);
      te = te->next;
    };
  };
};
inline void solve2(int A, int B) {
  dfs(A, B);
  dfs(B, A);
  setroot(mdistlca[B]);
  dfs2(A, B);
  setroot(mdistlca[A]);
  dfs2(B, A);
};
inline void solve__() {
  int i;
  int ma = 0, cnt = 0;
  for (i = 1; i <= n; i++) {
    if (_a[i]) continue;
    int t = splay(lct + i)->x;
    if (t > ma) {
      ma = t;
      cnt = 1;
    } else if (t == ma) {
      ++cnt;
    };
  };
  printf("%d %d\n", ma, cnt);
};
int main() {
  read(n);
  read(m);
  int i;
  for (i = 1; i <= m; i++) {
    read(a[i]);
    _a[a[i]] = 1;
  };
  for (i = 1; i < n; i++) {
    int x, y, w;
    read(x);
    read(y);
    read(w);
    addedge(x, y, w);
    addedge(y, x, w);
  };
  init();
  solve();
}
