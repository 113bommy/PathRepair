#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, T;
  cin >> n >> T;
  vector<long long> a(n);
  vector<long long> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool l = false, r = false;
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
    if (t[i] >= T) r = true;
    if (t[i] <= T) l = true;
  }
  if (!l || !r) {
    cout << 0 << endl;
  } else {
    long double xt = 0;
    long double x = 0;
    vector<pair<long long, long long>> ta(n);
    for (int i = 0; i < n; ++i) {
      xt += a[i] * t[i];
      x += a[i];
      ta[i].first = t[i];
      ta[i].second = a[i];
    }
    sort(ta.begin(), ta.end());
    if (T > xt / x) {
      for (int i = 0; i < n - 2; ++i) {
        if (x == ta[i].second) break;
        if ((xt - ta[i].first * ta[i].second) / (x - ta[i].second) == T) {
          xt -= ta[i].first * ta[i].second;
          x -= ta[i].second;
          ta[i].second = 0;
          break;
        } else if ((xt - ta[i].first * ta[i].second) / (x - ta[i].second) > T) {
          long double aa = (T * x - xt) / (T - ta[i].first);
          xt -= ta[i].first * aa;
          x -= aa;
          break;
        } else {
          xt -= ta[i].first * ta[i].second;
          x -= ta[i].second;
          ta[i].second = 0;
        }
      }
    } else if (T < xt / x) {
      for (int i = n - 1; i > 0; --i) {
        if (x == ta[i].second) break;
        if ((xt - ta[i].first * ta[i].second) / (x - ta[i].second) == T) {
          xt -= ta[i].first * ta[i].second;
          x -= ta[i].second;
          ta[i].second = 0;
          break;
        } else if ((xt - ta[i].first * ta[i].second) / (x - ta[i].second) < T) {
          long double aa = (T * x - xt) / (T - ta[i].first);
          xt -= ta[i].first * aa;
          x -= aa;
          break;
        } else {
          xt -= ta[i].first * ta[i].second;
          x -= ta[i].second;
          ta[i].second = 0;
        }
      }
    }
    std::cout.precision(20);
    cout << std::fixed << x << endl;
  }
  return 0;
}
