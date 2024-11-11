#include <bits/stdc++.h>
using namespace std;
vector<double> tk(1010), td(1010);
int n;
double m;
bool check(double wei) {
  double curw = wei;
  for (int i = 0; i < n; i++) {
    curw -= curw * 1.00 / tk[i] * 1.00;
    curw -= curw * 1.00 / td[i] * 1.00;
    if (curw < m) return false;
  }
  if (curw < 0) return false;
  return true;
}
int main() {
  scanf("%d\n%lf\n", &n, &m);
  for (int i = 0; i < n; i++) cin >> tk[i];
  int lde;
  for (int i = -1; i < n; i++) {
    if (i == -1) {
      cin >> lde;
    } else if (i != n - 1) {
      cin >> td[i];
    } else {
      td[i] = lde;
    }
  }
  double lo = 0, hi = 1e9;
  double ans = -1;
  bool ok = false;
  for (int i = 0; i < 80; i++) {
    double mid = (lo + hi) / 2.0;
    bool chk = check(mid + m);
    if (chk) {
      hi = mid;
      ans = mid;
      ok = true;
    } else {
      lo = mid;
    }
  }
  if (ok)
    printf("%.12lf", ans);
  else
    puts("-1");
}
