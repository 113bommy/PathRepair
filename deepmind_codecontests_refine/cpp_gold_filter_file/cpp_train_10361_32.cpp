#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
double vol[N], r, h;
int n, has[N], g[N], dp[N], tot;
int c[N];
vector<double> v;
int getId(double a) {
  return lower_bound(v.begin(), v.end(), a) - v.begin() + 1;
}
struct Tree {
  int l, r;
  double data;
} t[4 * N];
void build(int p, int l, int r) {
  t[p].l = l;
  t[p].r = r;
  if (l == r) {
    t[p].data = 0;
    return;
  }
  int mid = l + r >> 1;
  build(p * 2, l, mid);
  build(p * 2 + 1, mid + 1, r);
  t[p].data = 0;
}
void change(int p, int x, double val) {
  if (t[p].l == t[p].r && t[p].l == x) {
    t[p].data = max(t[p].data, val);
    return;
  }
  int mid = (t[p].l + t[p].r) >> 1;
  if (x <= mid)
    change(p * 2, x, val);
  else
    change(p * 2 + 1, x, val);
  t[p].data = max(t[p * 2].data, t[p * 2 + 1].data);
}
double ask(int p, int l, int r) {
  if (t[p].l >= l && t[p].r <= r) return t[p].data;
  int mid = (t[p].l + t[p].r) >> 1;
  double val = 0;
  if (l <= mid) val = max(val, ask(p * 2, l, r));
  if (r > mid) val = max(val, ask(p * 2 + 1, l, r));
  return val;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &r, &h);
    vol[i] = acos(-1) * r * r * h;
    v.push_back(vol[i]);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  build(1, 1, n);
  double res = 0;
  for (int i = 1; i <= n; i++) {
    int id = getId(vol[i]);
    double now = ask(1, 1, id - 1);
    now = max(vol[i], vol[i] + now);
    res = max(res, now);
    change(1, id, now);
  }
  printf("%.10lf\n", res);
  return 0;
}
