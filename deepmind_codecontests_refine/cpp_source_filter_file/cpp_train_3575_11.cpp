#include <bits/stdc++.h>
using namespace std;
int mod;
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
int q;
int n, g, r;
int a[maxn];
long long dp[maxn];
long long pos[maxn];
struct node {
  int minn;
  int lo, hi;
  node *l, *r;
  node(int _lo = 0, int _hi = 0, int _minn = inf, node *_l = 0, node *_r = 0) {
    lo = _lo;
    hi = _hi;
    minn = _minn;
    l = _l;
    r = _r;
  }
};
node *t;
node *get_l(node *x) {
  if (x->l != 0) return x->l;
  int lo = x->lo;
  int hi = x->hi;
  int mid = (lo + hi) / 2;
  return x->l = new node(lo, mid);
}
node *get_r(node *x) {
  if (x->r != 0) return x->r;
  int lo = x->lo;
  int hi = x->hi;
  int mid = (lo + hi) / 2;
  return x->r = new node(mid, hi);
}
void update(node *x, int y, int val) {
  int lo = x->lo;
  int hi = x->hi;
  if (hi - lo == 1) {
    x->minn = val;
    return;
  }
  int mid = (lo + hi) / 2;
  if (y < mid)
    update(get_l(x), y, val);
  else
    update(get_r(x), y, val);
  x->minn = min(get_l(x)->minn, get_r(x)->minn);
}
int query(node *x, int qlo, int qhi) {
  int lo = x->lo;
  int hi = x->hi;
  if (lo >= qhi || hi <= qlo) return inf;
  if (lo >= qlo && hi <= qhi) return x->minn;
  int lmin = inf;
  int rmin = inf;
  if (x->l != 0) lmin = query(x->l, qlo, qhi);
  if (x->r != 0) rmin = query(x->r, qlo, qhi);
  return min(lmin, rmin);
}
int fhit(int x) {
  int hit;
  int qlo, qhi;
  if (x >= g) {
    qlo = 0;
    qhi = mod - x - 1;
    hit = query(t, qlo, qhi + 1);
    qlo = mod - x + g - 1;
    qhi = mod - 1;
    hit = min(hit, query(t, qlo, qhi + 1));
  } else {
    qlo = g - x;
    qhi = mod - x - 1;
    hit = query(t, qlo, qhi + 1);
  }
  return hit;
}
int main() {
  scanf("%d%d%d", &n, &g, &r);
  n++;
  mod = g + r;
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    pos[i] = pos[i - 1] + x;
    a[i] = pos[i] % mod;
  }
  t = new node(0, mod + 1);
  for (int i = n - 1; i > 0; i--) {
    int hit = fhit(sub(0, a[i]));
    if (hit == inf)
      dp[i] = pos[n] - pos[i];
    else {
      int wait = mod - sub(a[hit], a[i]);
      dp[i] = dp[hit] + pos[hit] - pos[i] + wait;
    }
    update(t, a[i], i);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int x;
    scanf("%d", &x);
    int md = sub(0, x % mod);
    int hit = fhit(sub(0, md));
    if (hit == inf)
      printf("%lld\n", pos[n] + x);
    else {
      int wait = mod - sub(a[hit], md);
      printf("%lld\n", dp[hit] + pos[hit] + wait + x);
    }
  }
  return 0;
}
