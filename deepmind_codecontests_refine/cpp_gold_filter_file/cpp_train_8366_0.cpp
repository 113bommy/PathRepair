#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
const double eps = 1e-8;
int n, m, k;
struct node {
  double x, y;
  node(double xx = 0, double yy = 0) : x(xx), y(yy) {}
  bool operator<(node b) const {
    return fabs(x - b.x) < eps ? y < b.y : x < b.x;
  }
  node operator-(node b) {
    node tmp;
    tmp.x = x - b.x;
    tmp.y = y - b.y;
    return tmp;
  }
  double dis(node b) {
    double xx = x - b.x;
    double yy = y - b.y;
    return sqrt(xx * xx + yy * yy);
  }
} p[110];
map<node, int> mp;
double dot_mul(node a, node b) { return a.x * b.x + a.y * b.y; }
node calc(node a, node b, node c) {
  double a1 = 2 * (b.x - a.x), b1 = 2 * (b.y - a.y);
  double c1 = b.x * b.x + b.y * b.y - a.x * a.x - a.y * a.y;
  double a2 = 2 * (c.x - b.x), b2 = 2 * (c.y - b.y);
  double c2 = c.x * c.x + c.y * c.y - b.x * b.x - b.y * b.y;
  double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
  double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
  return node(x, y);
}
double get_ans(node a, node b, node c) {
  double ans = 1e18;
  double t1 = dot_mul(b - a, c - a), t2 = dot_mul(a - b, c - b),
         t3 = dot_mul(a - c, b - c);
  if (t1 < -eps || t2 < -eps || t3 < -eps) return -1;
  node ct;
  bool flag = false;
  if (fabs(t1) < eps) {
    flag = true;
  }
  if (fabs(t2) < eps) swap(a, b), flag = true;
  if (fabs(t3) < eps) swap(a, c), flag = true;
  if (flag) {
    ct = node(b.x + c.x - 2 * a.x, b.y + c.y - 2 * a.y);
    if (mp[ct]) {
      ct = node((a.x + ct.x) / 2, (a.y + ct.y) / 2);
      for (int i = 1; i <= n; i++) {
        ans = min(ans, ct.dis(p[i]));
      }
    } else
      return -1;
  } else {
    ct = calc(a, b, c);
    for (int i = 1; i <= n; i++) {
      ans = min(ans, ct.dis(p[i]));
    }
  }
  if (ans + eps < ct.dis(a))
    return -1;
  else
    return ans;
}
void solve() {
  double ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      for (int k = j + 1; k <= n; k++) {
        ans = max(ans, get_ans(p[i], p[j], p[k]));
      }
    }
  }
  if (ans == -1)
    puts("-1");
  else
    printf("%.6f\n", ans);
}
int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y), mp[p[i]]++;
    solve();
  }
  return 0;
}
