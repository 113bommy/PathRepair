#include <bits/stdc++.h>
using namespace std;
double solve(double sum, double prod) {
  return (sum + sqrt(abs(sum * sum - 4 * prod))) / 2.0;
}
int main() {
  cout.precision(20);
  cout << fixed;
  int n;
  cin >> n;
  vector<double> mx(n), mn(n);
  for (auto& x : mx) cin >> x;
  for (auto& x : mn) cin >> x;
  vector<double> a(n), b(n);
  double sa = 0.0, diff = 0.0;
  for (int i = n - 1; i >= 0; --i) {
    double tmp = mn[i] + mx[i];
    a[i] = solve(diff + tmp, mn[i] - tmp * sa);
    b[i] = tmp - a[i];
    sa += a[i];
    diff += tmp - 2 * a[i];
  }
  for (const auto& x : a) cout << x << " ";
  cout << "\n";
  for (const auto& x : b) cout << x << " ";
  cout << "\n";
  return 0;
}
