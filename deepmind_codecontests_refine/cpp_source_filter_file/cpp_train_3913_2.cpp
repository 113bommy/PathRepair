#include <bits/stdc++.h>
using namespace std;
void getre() {
  int x = 0;
  printf("%d\n", 1 / x);
}
void gettle() {
  int res = 1;
  while (1) res <<= 1;
  printf("%d\n", res);
}
template <typename T, typename S>
inline bool upmin(T &a, const S &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T, typename S>
inline bool upmax(T &a, const S &b) {
  return a < b ? a = b, 1 : 0;
}
template <typename N, typename PN>
inline N flo(N a, PN b) {
  return a >= 0 ? a / b : -((-a - 1) / b) - 1;
}
template <typename N, typename PN>
inline N cei(N a, PN b) {
  return a > 0 ? (a - 1) / b + 1 : -(-a / b);
}
template <typename N>
N gcd(N a, N b) {
  return b ? gcd(b, a % b) : a;
}
template <typename N>
inline int sgn(N a) {
  return a > 0 ? 1 : (a < 0 ? -1 : 0);
}
inline void gn(long long &x) {
  int sg = 1;
  char c;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  c == '-' ? (sg = -1, x = 0) : (x = c - '0');
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= sg;
}
inline void gn(int &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(unsigned long long &x) {
  long long t;
  gn(t);
  x = t;
}
inline void gn(double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gn(long double &x) {
  double t;
  scanf("%lf", &t);
  x = t;
}
inline void gs(char *s) { scanf("%s", s); }
inline void gc(char &c) {
  while ((c = getchar()) > 126 || c < 33)
    ;
}
inline void pc(char c) { putchar(c); }
inline long long sqr(long long a) { return a * a; }
inline double sqrf(double a) { return a * a; }
const int inf = 0x3f3f3f3f;
const double pi = 3.14159265358979323846264338327950288L;
const double eps = 1e-6;
const int TREE_MAXV = 100000 + 5;
struct edge {
  int v, next;
} e[TREE_MAXV * 2];
int g[TREE_MAXV], etot;
int n;
void ae(int u, int v) {
  e[etot].v = v;
  e[etot].next = g[u];
  g[u] = etot++;
}
int dfn[TREE_MAXV], rig[TREE_MAXV], pre[TREE_MAXV], h[TREE_MAXV];
int seq[TREE_MAXV], up[TREE_MAXV], sz[TREE_MAXV];
void build_hld(int rt) {
  static int qu[TREE_MAXV], son[TREE_MAXV];
  int p = 0, q = 0;
  qu[q++] = rt;
  pre[rt] = 0;
  h[rt] = 0;
  while (p != q) {
    int u = qu[p++];
    sz[u] = 1, son[u] = 0;
    for (int i = g[u]; ~i; i = e[i].next)
      if (e[i].v != pre[u])
        qu[q++] = e[i].v, pre[e[i].v] = u, h[e[i].v] = h[u] + 1;
  }
  sz[0] = 0;
  for (int i = q - 1; i >= 1; i--) {
    sz[pre[qu[i]]] += sz[qu[i]];
    if (sz[qu[i]] > sz[son[pre[qu[i]]]]) son[pre[qu[i]]] = qu[i];
  }
  for (int j = 0; j < q; j++)
    if (!son[qu[j]]) {
      int s = qu[j];
      while (son[pre[s]] == s) s = pre[s];
      int t = s;
      while (t) up[t] = s, t = son[t];
    } else {
      int u = qu[j], v = son[u];
      if (e[g[u]].v != v) {
        for (int i = g[u], j; ~i; j = i, i = e[i].next)
          if (e[i].v == v) {
            e[j].next = e[i].next;
            e[i].next = g[u];
            g[u] = i;
            break;
          }
      }
    }
  static int stk[TREE_MAXV], cur[TREE_MAXV];
  int top = 0, ind = 0;
  stk[++top] = rt;
  cur[top] = g[rt];
  while (top) {
    int u = stk[top];
    if (cur[top] == g[u]) {
      dfn[u] = ++ind;
      seq[ind] = u;
    }
    if (cur[top] == -1) {
      rig[u] = ind;
      top--;
    } else {
      int v = e[cur[top]].v;
      cur[top] = e[cur[top]].next;
      if (v == pre[u]) continue;
      stk[++top] = v;
      cur[top] = g[v];
    }
  }
}
void work(int a, int b) {
  int l1, r1;
  while (up[a] != up[b]) {
    if (h[up[a]] < h[up[b]]) swap(a, b);
    l1 = dfn[up[a]], r1 = dfn[a];
    a = pre[up[a]];
  }
  if (h[a] > h[b]) swap(a, b);
  l1 = dfn[a] + 1, r1 = dfn[b];
  if (a != b) {
  }
}
int lca(int a, int b) {
  while (up[a] != up[b]) {
    if (h[up[a]] < h[up[b]]) swap(a, b);
    a = pre[up[a]];
  }
  if (h[a] > h[b]) swap(a, b);
  return a;
}
void tree_init() {
  static bool ini = 0;
  if (!ini) {
    ini = 1;
    memset(g, -1, sizeof(g));
  } else {
    for (int i = 0; i <= n; i++) g[i] = -1;
  }
  etot = 0;
}
int rt;
void readedge() {
  for (int i = 1; i <= n; i++) {
    int x, y;
    gn(x);
    gn(y);
    if (x == 0)
      rt = y;
    else
      ae(x, y);
  }
}
int lis[111111];
int ansquer[3333333];
int quetot = 0;
struct quer {
  int l, r;
  int x;
  int id;
} que1[3333333], que0[3333333];
int que1tot = 0, que0tot = 0;
int operator<(const quer &a, const quer &b) { return a.x < b.x; }
void addque(int l, int r, int x, int bo) {
  int id = ++quetot;
  quer tmp = (quer){l, r, x, id};
  if (bo)
    que1[++que1tot] = tmp;
  else
    que0[++que0tot] = tmp;
}
int poptot = 0;
int popque() {
  int id = ++poptot;
  return ansquer[id];
}
const int SEG_MAXN = 100000 + 5;
int seg[SEG_MAXN * 4];
inline void segpu(int x) { seg[x] = max(seg[x << 1], seg[x << 1 | 1]); }
void seginit_in(int l, int r, int x) {
  if (l == r) {
    seg[x] = -inf;
  } else {
    int mid = l + r >> 1;
    seginit_in(l, mid, x << 1);
    seginit_in(mid + 1, r, x << 1 | 1);
    segpu(x);
  }
}
int l1, r1, I;
int sans;
bool ans_bo;
int stag;
void segupd_in(int l, int r, int x) {
  if (l == r) {
    seg[x] = max(seg[x], stag);
  } else {
    int mid = l + r >> 1;
    if (I <= mid)
      segupd_in(l, mid, x << 1);
    else
      segupd_in(mid + 1, r, x << 1 | 1);
    segpu(x);
  }
}
void segque_in(int l, int r, int x) {
  if (l1 <= l && r <= r1) {
    if (!ans_bo)
      ans_bo = 1, sans = seg[x];
    else
      sans = max(sans, seg[x]);
  } else {
    int mid = l + r >> 1;
    if (l1 <= mid) segque_in(l, mid, x << 1);
    if (r1 > mid) segque_in(mid + 1, r, x << 1 | 1);
  }
}
int segn;
void segupd(int i, int v) {
  stag = v, I = i;
  segupd_in(1, segn, 1);
}
int segque(int l, int r) {
  if (l > r) return -inf;
  ans_bo = 0, l1 = l, r1 = r;
  segque_in(1, segn, 1);
  return sans;
}
void seginit(int n) {
  segn = n;
  seginit_in(1, segn, 1);
}
int ord[111111];
int cmpsz(int i, int j) { return sz[i] < sz[j]; }
void gaoxunwen() {
  sort(que1 + 1, que1 + que1tot + 1);
  sort(que0 + 1, que0 + que0tot + 1);
  for (int i = (1), _ed = (n + 1); i < _ed; i++) ord[i] = i;
  sort(ord + 1, ord + 1 + n, cmpsz);
  seginit(n);
  int cur = 1;
  for (int i = (1), _ed = (que0tot + 1); i < _ed; i++) {
    int va = que0[i].x;
    while (cur <= n && sz[ord[cur]] <= va) {
      segupd(dfn[ord[cur]], sz[ord[cur]]);
      cur++;
    }
    ansquer[que0[i].id] = segque(que0[i].l, que0[i].r);
  }
  seginit(n);
  cur = n;
  for (int i = (que1tot + 1) - 1, _ed = (1); i >= _ed; i--) {
    int va = que1[i].x;
    while (cur >= 1 && sz[ord[cur]] >= va) {
      segupd(dfn[ord[cur]], -sz[ord[cur]]);
      cur--;
    }
    ansquer[que1[i].id] = -segque(que1[i].l, que1[i].r);
  }
}
struct quj {
  int l, r;
} qq[111];
int cmpqj(const quj &a, const quj &b) { return a.l < b.l; }
void getque(int nrt, int u, int val, int bo) {
  if (nrt != rt) {
    addque(dfn[u], rig[u], val, bo);
  } else {
    int qjtot = 0;
    int del = sz[u];
    qq[++qjtot] = (quj){dfn[u], rig[u]};
    int v = pre[u];
    while (v) {
      qq[++qjtot] = (quj){dfn[up[v]], dfn[v]};
      v = pre[up[v]];
    }
    sort(qq + 1, qq + 1 + qjtot, cmpqj);
    qq[0].r = 0, qq[qjtot + 1].l = n + 1;
    for (int i = (0), _ed = (qjtot + 1); i < _ed; i++) {
      if (qq[i].r + 1 <= qq[i + 1].l - 1)
        addque(qq[i].r + 1, qq[i + 1].l - 1, val, bo);
    }
    v = pre[u];
    while (v) {
      addque(dfn[up[v]], dfn[v], val + del, bo);
      v = pre[up[v]];
    }
  }
}
int gotque(int nrt, int u, int val, int bo) {
  if (nrt != rt) {
    return popque();
  } else {
    int ret;
    if (bo == 0)
      ret = -inf;
    else
      ret = inf;
    int qjtot = 0;
    int del = sz[u];
    qq[++qjtot] = (quj){dfn[u], rig[u]};
    int v = pre[u];
    while (v) {
      qq[++qjtot] = (quj){dfn[up[v]], dfn[v]};
      v = pre[up[v]];
    }
    sort(qq + 1, qq + 1 + qjtot, cmpqj);
    qq[0].r = 0, qq[qjtot + 1].l = n + 1;
    for (int i = (0), _ed = (qjtot + 1); i < _ed; i++) {
      if (qq[i].r + 1 <= qq[i + 1].l - 1) {
        int goo = popque();
        if (bo == 0)
          upmax(ret, goo);
        else
          upmin(ret, goo);
      }
    }
    v = pre[u];
    while (v) {
      int goo = popque() - del;
      if (bo == 0)
        upmax(ret, goo);
      else
        upmin(ret, goo);
      v = pre[up[v]];
    }
    return ret;
  }
}
void prework(int u) {
  int tot = 0;
  for (int i = g[u]; ~i; i = e[i].next) lis[++tot] = sz[e[i].v];
  if (u != rt) {
    lis[++tot] = n - sz[u];
  }
  sort(lis + 1, lis + 1 + tot);
  int masz = lis[tot];
  int nrt = rt;
  for (int i = g[u]; ~i; i = e[i].next)
    if (sz[e[i].v] == masz) {
      nrt = e[i].v;
    }
  if (tot == 0) return;
  if (tot == 1) return;
  if (tot == 2) {
    int a = lis[1], c = lis[2];
    getque(nrt, u, cei(c - a, 2), 1);
    getque(nrt, u, (c - a) / 2, 0);
    return;
  } else {
    int a = lis[1], b = lis[tot - 1], c = lis[tot];
    getque(nrt, u, cei(c - a, 2), 1);
    getque(nrt, u, (c - a) / 2, 0);
    getque(nrt, u, c - b, 1);
    return;
  }
}
int work(int u) {
  int tot = 0;
  for (int i = g[u]; ~i; i = e[i].next) lis[++tot] = sz[e[i].v];
  if (u != rt) {
    lis[++tot] = n - sz[u];
  }
  sort(lis + 1, lis + 1 + tot);
  int masz = lis[tot];
  int nrt = rt;
  for (int i = g[u]; ~i; i = e[i].next)
    if (sz[e[i].v] == masz) {
      nrt = e[i].v;
    }
  if (tot == 0) return 0;
  if (tot == 1) return lis[1];
  if (tot == 2) {
    int a = lis[1], c = lis[2];
    int d1 = gotque(nrt, u, cei(c - a, 2), 1);
    int d2 = gotque(nrt, u, (c - a) / 2, 0);
    return min(lis[2], min(max(c - d1, a + d1), max(c - d2, a + d2)));
  } else {
    int a = lis[1], b = lis[tot - 1], c = lis[tot];
    int d1 = gotque(nrt, u, cei(c - a, 2), 1);
    int d2 = gotque(nrt, u, (c - a) / 2, 0);
    int d3 = gotque(nrt, u, c - b, 1);
    int ans = lis[tot];
    upmin(ans, max(max(a + d1, b), c - d1));
    upmin(ans, max(max(a + d2, b), c - d2));
    upmin(ans, max(max(a + d3, b), c - d3));
    return ans;
  }
}
int main() {
  gn(n);
  tree_init();
  readedge();
  build_hld(rt);
  for (int u = (1), _ed = (n + 1); u < _ed; u++) prework(u);
  gaoxunwen();
  for (int u = (1), _ed = (n + 1); u < _ed; u++) printf("%d ", work(u));
  return 0;
}
