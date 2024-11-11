#include <bits/stdc++.h>
using namespace std;
pair<long double, long double> F(long double x, long double y) {
  long double d = sqrt(abs((x + y) * (x + y) - 4 * x));
  return {(x + y - d) / 2, (x + y + d) / 2};
}
int main() {
  int n;
  cin >> n;
  vector<long double> a(n);
  vector<long double> b(n);
  vector<long double> max_(n, 0);
  vector<long double> min_(n, 0);
  for (int i = 0; i < n; ++i) {
    long double x;
    cin >> x;
    if (i != 0) max_[i] = max_[i - 1];
    max_[i] += x;
  }
  for (int i = 0; i < n; ++i) {
    long double x;
    cin >> x;
    if (i != 0) min_[i] = min_[i - 1];
    min_[i] += x;
  }
  for (int i = 0; i < n; ++i) {
    pair<long double, long double> cur_res = F(max_[i], min_[i]);
    a[i] = cur_res.first;
    b[i] = cur_res.second;
  }
  cout << fixed;
  cout.precision(10);
  for (int i = 0; i < n; ++i) {
    long double ans = a[i];
    if (i != 0) ans -= a[i - 1];
    cout << ans << " ";
  }
  cout << endl;
  for (int i = 0; i < n; ++i) {
    long double ans = b[i];
    if (i != 0) ans -= b[i - 1];
    cout << ans << " ";
  }
}
