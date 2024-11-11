#include <bits/stdc++.h>
using namespace std;
const long long linf = (long long)1e18;
const int pw = 997;
const int N = 100009;
const int inf = (int)1e9;
const int mod = (int)1e9 + 7;
const double eps = 1e-10;
const double pi = 3.1415926535897932384626433832795;
struct disk {
  int a, b, h;
  disk() {}
  disk(int _a, int _b, int _h) {
    a = _a;
    b = _b;
    h = _h;
  }
  friend const bool operator<(const disk &a, const disk &b) {
    if (a.b == b.b) {
      if (a.a == b.a) {
        return a.h > b.h;
      }
      return a.a < b.a;
    }
    return a.b > b.b;
  }
} a[N];
int cnt = 1;
struct node {
  long long mx;
  int l, r;
  node() { l = r = mx = 0; }
  node(long long _mx, int _l, int _r) {
    mx = _mx;
    l = _l;
    r = _r;
  }
} t[4 * N * 30];
void update(int p, long long x, int v = 1, int tl = 1, int tr = inf) {
  if (tl == tr) {
    t[v].mx = max(t[v].mx, x);
    return;
  }
  int tm = (tl + tr) >> 1;
  if (p <= tm) {
    if (t[v].l == 0) {
      t[v].l = ++cnt;
    }
    update(p, x, t[v].l, tl, tm);
  } else {
    if (t[v].r == 0) {
      t[v].r = ++cnt;
    }
    update(p, x, t[v].r, tm + 1, tr);
  }
  t[v].mx = max(t[t[v].l].mx, t[t[v].r].mx);
}
long long get(int r, int v = 1, int tl = 1, int tr = inf) {
  if (r < tl) {
    return 0;
  }
  if (tr <= r) {
    return t[v].mx;
  }
  int tm = (tl + tr) >> 1;
  return max(get(r, t[v].l, tl, tm), get(r, t[v].r, tm + 1, tr));
}
inline void prepare() {}
inline void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d%d", &a[i].a, &a[i].b, &a[i].h);
  }
  sort(a, a + n);
  update(a[0].a, a[0].h);
  for (int i = 1; i < n; i++) {
    update(a[i].a, get(a[i].b - 1) + a[i].h);
  }
  printf("%I64d", t[1].mx);
}
int main() {
  int tests = 1;
  prepare();
  while (tests--) {
    solve();
  }
}
