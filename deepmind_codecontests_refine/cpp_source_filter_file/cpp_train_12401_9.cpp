#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 5;
vector<int> elm[N];
struct SegTree {
  struct Dat {
    int l, r;
    Dat *lc, *rc;
    long long lmx, rmx, mx, sum;
    int len() { return r - l + 1; }
    void fset(long long kval) { lmx = rmx = mx = sum = kval; }
    void pushup() {
      lmx = max(lc->lmx, lc->sum + rc->lmx);
      lmx = max(rc->rmx, rc->sum + lc->rmx);
      mx = max({lc->mx, rc->mx, lc->rmx + rc->lmx});
      sum = lc->sum + rc->sum;
    }
    void pushdown() {}
  } dat[N << 2];
  int siz = 0;
  void init(int n) {
    function<Dat *(int, int)> build = [&](int l, int r) {
      Dat &nw = dat[siz++];
      nw = {l, r};
      if (l == r) {
      } else {
        int mid = (l + r) >> 1;
        nw.lc = build(l, mid), nw.rc = build(mid + 1, r);
        nw.pushup();
      }
      return &nw;
    };
    build(1, n);
  }
  template <typename Fn>
  void travsal(int l, int r, Fn f) {
    function<void(Dat &)> trav = [&](Dat &p) {
      if (r < p.l || l > p.r) return;
      if (p.l >= l && p.r <= r) {
        return f(p);
      } else {
        p.pushdown();
        int mid = (l + r) >> 1;
        trav(*p.lc);
        trav(*p.rc);
        p.pushup();
      }
    };
    trav(dat[0]);
  }
  void update(int x, long long val) {
    travsal(x, x, [&](Dat &e) { e.fset(val); });
  }
  int query() { return dat[0].mx; }
} seg;
int a[N];
int main() {
  ios::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  seg.init(n);
  int base = 0;
  for (int i = 1; i < n + 1; i++) {
    cin >> a[i];
    if (a[i] == c)
      seg.update(i, -1), base++;
    else
      elm[a[i]].push_back(i);
  }
  int ans = base;
  for (int i = 1; i < N; i++) {
    if (elm[i].empty()) continue;
    for (int pos : elm[i]) seg.update(pos, 1);
    ans = max(ans, base + seg.query());
    for (int pos : elm[i]) seg.update(pos, 0);
  }
  cout << ans << endl;
}
