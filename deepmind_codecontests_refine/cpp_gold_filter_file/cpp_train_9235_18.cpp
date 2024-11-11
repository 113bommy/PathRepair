#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;
const int inf = 1e100;
double x[128];
double sqr(double x) { return x * x; }
int accept() {
  int n;
  double vs, vb, xu, yu;
  cin >> n >> vb >> vs;
  for (int i = 0; i < n; i++) cin >> x[i];
  cin >> xu >> yu;
  double ans = inf;
  double da = inf;
  int res = 0;
  for (int i = 1; i < n; i++) {
    double d = sqrt(sqr(xu - x[i]) + sqr(yu));
    double t = x[i] / vb + d / vs;
    if (t - eps < ans)
      if (t + eps < ans || d + eps < da) {
        ans = t;
        da = d;
        res = i + 1;
      }
  }
  cout << res << "\n";
  return 0;
}
int main() {
  int t = 1;
  while (t--) {
    accept();
  }
  return 0;
}
