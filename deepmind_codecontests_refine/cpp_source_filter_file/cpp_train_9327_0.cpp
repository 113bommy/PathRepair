#include <bits/stdc++.h>
using namespace std;
long long n, m, seed, vmax, op, x, y, l, r;
bool vis[1005];
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct node {
  long long l, r;
  mutable long long v;
  node(long long ll, long long rr = -1, long long vv = 0)
      : l(ll), r(rr), v(vv) {}
  bool operator<(const node &u) const { return l < u.l; }
};
set<node> se;
set<node>::iterator sp(long long op) {
  set<node>::iterator it = se.lower_bound(node(op));
  if (it != se.end() && it->l == op) return it;
  it--;
  long long ll = it->l, rr = it->r, vv = it->v;
  se.erase(it);
  se.insert(node(ll, op - 1, vv));
  return se.insert(node(op, rr, vv)).first;
}
long long sum;
void ass(long long ll, long long rr, long long vv) {
  set<node>::iterator ir = sp(rr + 1), il = sp(ll), ic = il;
  se.erase(ic, ir);
  se.insert(node(ll, rr, vv));
}
void upd(long long ll, long long rr) {
  set<node>::iterator ir = sp(rr + 1), il = sp(ll);
  for (set<node>::iterator nw = il; nw != ir; ++nw) {
    nw->v = 1 - nw->v;
  }
}
long long qry(long long ll = 1, long long rr = 1e18) {
  set<node>::iterator ir = sp(rr + 1), il = sp(ll);
  for (set<node>::iterator nw = il; nw != ir; ++nw) {
    if (nw->v == 0) return nw->l;
  }
  long long x = 1e18 + 1;
  return x;
}
signed main() {
  n = read();
  long long x = 1e18;
  se.insert((node){1, x, 0});
  for (long long i = 1, iend = n; i <= iend; ++i) {
    long long op, l, r;
    op = read(), l = read(), r = read();
    if (op == 1) {
      ass(l, r, 1);
    } else if (op == 2) {
      ass(l, r, 0);
    } else {
      upd(l, r);
    }
    printf("%lld\n", qry());
  }
  return 0;
}
