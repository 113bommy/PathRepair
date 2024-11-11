#include <bits/stdc++.h>
using namespace std;
inline void readi(int &x);
const int maxn = 100005, N = 300000;
int n, m;
int l[maxn], r[maxn], v[maxn];
struct R {
  int pos, l, r, d;
  R() {}
  R(const int &p, const int &a, const int &b, const int &c) {
    pos = p, l = a, r = b, d = c;
  }
  bool operator<(const R &o) const { return pos < o.pos; }
} p[maxn];
struct node {
  int dta;
  int mx, mi;
  node *lc, *rc;
  void update() {
    if (lc->mx > rc->mx)
      mi = lc->mi, mx = lc->mx;
    else
      mi = rc->mi, mx = rc->mx;
  }
  void downdate() {
    if (dta) {
      lc->dta += dta, lc->mx += dta;
      rc->dta += dta, rc->mx += dta;
      dta = 0;
    }
  }
  void insert(int l, int r, const int &a, const int &b, const int &c) {
    if (l >= a && r <= b)
      dta += c, mx += c;
    else {
      int mid = l + r >> 1;
      downdate();
      if (a <= mid) lc->insert(l, mid, a, b, c);
      if (b > mid) rc->insert(mid + 1, r, a, b, c);
      update();
    }
  }
} ndl[maxn * 6], *root;
int ns = 1;
node *build(int l, int r) {
  node *c = ndl + ns++;
  if (l == r)
    return c->mi = l, c;
  else {
    int mid = l + r >> 1;
    c->lc = build(l, mid);
    c->rc = build(mid + 1, r);
    c->update();
  }
  return c;
}
void init() {
  readi(n);
  for (int i = 1; i <= n; i++) {
    readi(l[i]), readi(v[i]), readi(r[i]);
    p[++m] = R(l[i], v[i], r[i], 1);
    p[++m] = R(v[i] + 1, v[i], r[i], -1);
  }
  root = build(1, N);
  sort(p + 1, p + m + 1);
}
void work() {
  int L = 0, R = 0, best = 0;
  for (int i = 1, j; i <= m; i = j) {
    for (j = i; j <= m && p[j].pos == p[i].pos; j++)
      root->insert(1, N, p[j].l, p[j].r, p[j].d);
    if (root->mx > best) {
      best = root->mx;
      L = p[i].pos;
      R = root->mi;
    }
  }
  printf("%d\n", best);
  for (int i = 1; i <= n; i++)
    if (l[i] <= L && v[i] >= L && v[i] <= R && r[i] >= R) printf("%d\n", i);
}
int main() {
  init();
  work();
  return 0;
}
inline void readi(int &x) {
  char c;
  for (c = getchar(); c > '9' || c < '0'; c = getchar())
    ;
  x = c ^ '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
    x = x * 10 + (c ^ '0');
}
