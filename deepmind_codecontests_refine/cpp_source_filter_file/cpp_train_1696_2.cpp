#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
const double eps = 1e-8;
const double PI = acos(-1.0);
int n, sz;
long long k;
struct pnt {
  int x, y;
  pnt(int _x = 0, int _y = 0) { x = _x, y = _y; }
  pnt operator+(const pnt &z) { return pnt(x + z.x, y + z.y); }
  pnt operator-(const pnt &z) { return pnt(x - z.x, y - z.y); }
  double norm() { return sqrt(x * x + y * y); }
} a[N];
double b[N], l[N], r[N];
double fix(double x) {
  while (x < 0) x += 2 * PI;
  while (x > 2 * PI) x -= 2 * PI;
  return x;
}
struct bit {
  int c[N], n;
  void init(int _n) {
    n = _n;
    memset(c, 0, (n + 1) << 2);
  }
  void ins(int x, int v) {
    for (; x <= n; x += x & -x) c[x] += v;
  }
  int ask(int x) {
    int ans = 0;
    for (; x; x -= x & -x) ans += c[x];
    return ans;
  }
} t[2];
struct dat {
  int l, r, v;
};
vector<dat> G[N][2];
vector<int> h[N];
void ins(int o, int x, int l, int r, int v) {
  if (x > sz || x < 1 || l > r) return;
  G[x][o].push_back((dat){l, r, v});
}
long long chk(double R) {
  long long ans = 0;
  int m = 0;
  sz = 0;
  for (int i = 1; i <= n; i++) {
    double al = atan2(a[i].y, a[i].x);
    double d = a[i].norm();
    if (d < R) {
      ans += n - 1;
      continue;
    }
    double be = acos(R / d);
    l[++m] = fix(al - be), r[m] = fix(al + be);
    b[++sz] = l[m], b[++sz] = r[m];
  }
  sort(b + 1, b + sz + 1);
  sz = unique(b + 1, b + sz + 1) - b - 1;
  ans += 1ll * m * (n - m);
  for (int i = 1; i <= m; i++) {
    int lp = lower_bound(b + 1, b + sz + 1, l[i]) - b;
    int rp = lower_bound(b + 1, b + sz + 1, r[i]) - b;
    h[lp].push_back(rp);
    l[i] = lp, r[i] = rp;
    if (lp > rp) {
      ins(0, lp + 1, lp + 1, sz, 2);
      ins(1, lp + 1, 1, rp - 1, 2);
      ins(0, 1, 1, rp - 1, 2);
      ins(0, rp, 1, rp - 1, -2);
      ins(0, rp + 1, rp + 1, lp - 1, 1);
      ins(0, lp, rp + 1, lp - 1, -1);
    } else {
      ins(0, lp + 1, lp + 1, rp - 1, 2);
      ins(0, rp, lp + 1, rp - 1, -2);
      ins(0, 1, 1, lp - 1, 1);
      ins(0, lp, 1, lp - 1, -1);
      ins(0, rp + 1, rp + 1, sz, 1);
      ins(1, rp + 1, 1, lp - 1, 1);
    }
  }
  t[0].init(sz);
  t[1].init(sz);
  for (int i = 1; i <= sz; i++) {
    for (dat z : G[i][0]) t[0].ins(z.l, z.v), t[0].ins(z.r + 1, -z.v);
    for (dat z : G[i][1]) t[1].ins(z.l, z.v), t[1].ins(z.r + 1, -z.v);
    for (int z : h[i])
      if (i <= z)
        ans += t[0].ask(z);
      else
        ans += t[1].ask(z);
    h[i].clear();
    G[i][0].clear();
    G[i][1].clear();
  }
  return ans / 2;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].x, &a[i].y);
  double l = 0, r = 1e4;
  while (r - l > eps) {
    double mid = (l + r) * 0.5;
    if (chk(mid) < k)
      l = mid;
    else
      r = mid;
  }
  printf("%.8lf", l);
  return 0;
}
