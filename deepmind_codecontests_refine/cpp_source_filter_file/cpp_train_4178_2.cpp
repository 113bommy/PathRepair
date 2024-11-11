#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, mm;
  cin >> n >> mm;
  vector<long long> x(n);
  vector<long long> y;
  for (long long i = 0; i < n; ++i) {
    cin >> x[i];
  }
  long long m = 0;
  for (long long i = 0; i < mm; ++i) {
    long long x1, x2, yy;
    cin >> x1 >> x2 >> yy;
    if (x1 == 1) {
      y.push_back(x2);
      ++m;
    }
  }
  sort(y.begin(), y.end());
  sort(x.begin(), x.end());
  x.push_back(1e9 + 1);
  long long ans = 0;
  if (m == 0) {
    cout << 0;
    return 0;
  }
  if (n == 0) {
    for (long long i = 0; i < m; ++i) {
      if (y[i] == 1e9) {
        ++ans;
      }
    }
    cout << ans;
    return 0;
  }
  for (long long i = 0; i < m; ++i) {
    if (y[i] >= x[0]) {
      ++ans;
    }
  }
  for (long long i = 0; i < n; ++i) {
    long long ind = lower_bound(y.begin(), y.end(), x[i + 1]) - y.begin();
    ans = min(ans, m - ind + (i + 1));
  }
  cout << ans;
  return 0;
}
