#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
inline char nc() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline void read(int &x) {
  char c = nc();
  x = 0;
  for (; c > '9' || c < '0'; c = nc())
    ;
  for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = nc())
    ;
}
struct Pt {
  int x, y, mx[2], mn[2];
  long long val, tag;
  Pt *l, *r, *f;
} pool[N], *rt, *p[N], *t = pool, *pos[N];
int n, m, cnt, a[N], opt[N], x[N], y[N], lst[N];
inline Pt *New(int x, int y) {
  t->x = x;
  t->y = y;
  t->val = t->tag = 0;
  return t++;
}
int PP;
inline bool cmp(Pt *a, Pt *b) { return PP ? a->x < b->x : a->y < b->y; }
inline void Up(Pt *x) {
  x->mx[0] = x->mn[0] = x->x;
  x->mx[1] = x->mn[1] = x->y;
  for (int i = 0; i < 2; i++) {
    if (x->l)
      x->mx[i] = max(x->mx[i], x->l->mx[i]),
      x->mn[i] = min(x->mn[i], x->l->mn[i]);
    if (x->r)
      x->mx[i] = max(x->mx[i], x->r->mx[i]),
      x->mn[i] = min(x->mn[i], x->r->mn[i]);
  }
}
Pt *build(int l, int r, int _ = 1) {
  if (l > r) return 0;
  int mid = l + r >> 1;
  PP = _;
  nth_element(p + l, p + mid, p + r + 1, cmp);
  Pt *cur = p[mid];
  cur->l = build(l, mid - 1, _ ^ 1);
  cur->r = build(mid + 1, r, _ ^ 1);
  Up(cur);
  if (cur->l) cur->l->f = cur;
  if (cur->r) cur->r->f = cur;
  return cur;
}
void Modify(Pt *g, int x1, int y1, int x2, int y2, int v) {
  if (!g || x1 > x2 || y1 > y2) return;
  if (g->mx[0] < x1 || g->mn[0] > x2 || g->mx[1] < y1 || g->mn[1] > y2) return;
  if (g->mx[0] <= x2 && g->mn[0] >= x1 && g->mn[1] >= y1 && g->mx[1] <= y2) {
    g->tag += v;
    return;
  }
  if (g->x <= x2 && g->x >= x1 && g->y >= y1 && g->y <= y2) g->val += v;
  Modify(g->l, x1, y1, x2, y2, v);
  Modify(g->r, x1, y1, x2, y2, v);
}
long long Query(Pt *g) {
  long long ret = g->val;
  while (g) {
    ret += g->tag;
    g = g->f;
  }
  return ret;
}
set<int> S[N];
inline void del(int x) {
  set<int>::iterator p = S[a[x]].lower_bound(x), l = p, r = p;
  l--;
  r++;
  Modify(rt, 1, x, *l, n, *l - x);
  if (r != S[a[x]].end()) {
    Modify(rt, 1, *r, x, n, x - *r);
    Modify(rt, 1, *r, *l, n, *r - *l);
  }
  S[a[x]].erase(x);
}
inline void add(int x) {
  set<int>::iterator p = S[a[x]].insert(x).first, l = p, r = p;
  l--;
  r++;
  Modify(rt, 1, x, *l, n, x - *l);
  if (r != S[a[x]].end()) {
    Modify(rt, 1, *r, *l, n, *l - *r);
    Modify(rt, 1, *r, x, n, *r - x);
  }
}
int main() {
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) read(a[i]), S[i].insert(0);
  for (int i = 1; i <= m; i++) {
    read(opt[i]);
    read(x[i]);
    read(y[i]);
    if (opt[i] == 2) {
      p[++cnt] = pos[i] = New(x[i], y[i]);
    }
  }
  rt = build(1, cnt);
  for (int i = 1; i <= n; i++) {
    lst[i] = *S[a[i]].rbegin();
    S[a[i]].insert(i);
    Modify(rt, 1, i, lst[i], n, i - lst[i]);
  }
  for (int i = 1; i <= m; i++) {
    if (opt[i] == 2)
      printf("%lld\n", Query(pos[i]));
    else {
      if (y[i] == a[x[i]]) continue;
      del(x[i]);
      a[x[i]] = y[i];
      add(x[i]);
    }
  }
  return 0;
}
