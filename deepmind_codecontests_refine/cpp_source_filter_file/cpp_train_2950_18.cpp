#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int n, m;
double h;
const double eps = 1e-9;
struct Node {
  int m, id;
  double v;
  bool operator<(const Node &other) const {
    if (m != other.m) return m < other.m;
    return v < other.v;
  }
} node[MAXN];
int ans[MAXN];
int high[MAXN];
bool ok(double x) {
  int cnt(0), j(m);
  for (int i = n; i >= 1; --i) {
    if (j * h / node[i].v < x + eps) --j;
  }
  return j < 1;
}
int main() {
  while (scanf("%d%d%lf", &n, &m, &h) != EOF) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &node[i].m);
      node[i].id = i;
    }
    for (int i = 1; i <= n; ++i) scanf("%lf", &node[i].v);
    sort(node + 1, node + 1 + n);
    double l(0), r(1e10);
    int test(60);
    while (test--) {
      double mid = (l + r) / 2.0;
      if (ok(mid)) {
        r = mid;
        for (int i = n, j = m; j >= 1; --i) {
          if (h * j / node[i].v < mid + eps) ans[j--] = node[i].id;
        }
      } else
        l = mid;
    }
    for (int i = 1; i <= m; ++i) {
      if (i == m)
        printf("%d\n", ans[i]);
      else
        printf("%d ", ans[i]);
    }
  }
  return 0;
}
