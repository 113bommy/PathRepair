#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1e5 + 5;
const double INF = 1e11;
const double EPS = 1e-6;
int n, p, a[MAX_N], b[MAX_N];
bool check(double t) {
  double cT = 0;
  for (int i = 1; i <= n; ++i) {
    if (1.0 * b[i] < t * a[i]) {
      cT += (t * a[i] - b[i]) / p;
    }
  }
  return cT <= t;
}
void solve() {
  long long sum = 0;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", a + i, b + i);
    sum += a[i];
  }
  double L = 0, R = INF;
  while (fabs(R - L) > EPS) {
    double mid = (L + R) / 2;
    if (check(mid)) {
      L = mid;
    } else {
      R = mid;
    }
  }
  if (p < sum) {
    printf("%f", L);
  } else {
    printf("-1");
  }
}
int main() {
  solve();
  return 0;
}
