#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n;
double m;
double eps = 1e-6;
double a[maxn], b[maxn];
bool check(double x) {
  double tot = m + x;
  for (int i = 1; i <= n; i++) {
    tot -= (tot * 1.0 / a[i]);
    if (tot < m) {
      return 0;
    }
    tot -= (tot * 1.0 / b[i]);
    if (tot < m) {
      return 0;
    }
  }
  if (tot >= m) {
    return 1;
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  scanf("%lf", &m);
  int flag = 0;
  double t = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    if (a[i] == t) {
      flag = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &b[i - 1]);
    if (b[i] == t) {
      flag = 1;
    }
  }
  b[n] = b[0];
  if (flag == 1) {
    cout << "-1" << endl;
    return 0;
  }
  if (!check(1e9 + 100)) {
    cout << -1 << endl;
    return 0;
  }
  double l = 0, r = 1e9;
  while (r - l >= eps) {
    double mid = (l + r) * 1.0 / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%.6f\n", r);
  return 0;
}
