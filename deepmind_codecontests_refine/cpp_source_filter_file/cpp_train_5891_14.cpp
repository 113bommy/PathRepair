#include <bits/stdc++.h>
using namespace std;
const long long base = 361;
const long long mod = 998244353;
const long double eps = 1e-5;
const long long maxn = 1e9 + 9;
pair<long double, long double> a[2009];
long double res;
long long n, i;
pair<pair<long double, long double>, long double> getline(
    pair<long double, long double> x, pair<long double, long double> y) {
  long double tmp1 = y.first - x.first;
  long double tmp2 = y.second - x.second;
  return {{tmp1, tmp2}, -(tmp1 * x.first + tmp2 * x.second)};
}
long double dist(pair<pair<long double, long double>, long double> x,
                 pair<long double, long double> y) {
  return (x.first.first * y.first + x.first.second * y.second + x.second) /
         sqrt(x.first.first * x.first.first + x.first.second * x.first.second);
}
long double calc(pair<long double, long double> x,
                 pair<long double, long double> y,
                 pair<long double, long double> z) {
  return abs(dist(getline(x, z), y) / 2.0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  a[0] = a[n];
  a[n + 1] = a[1];
  res = 1e15;
  for (i = 1; i <= n; i++) {
    res = min(res, calc(a[i - 1], a[i], a[i + 1]));
    res = min(res, calc(a[i + 1], a[i], a[i - 1]));
    res = min(res, calc(a[i], a[i - 1], a[i + 1]));
    res = min(res, calc(a[i + 1], a[i - 1], a[i]));
    res = min(res, calc(a[i - 1], a[i + 1], a[i]));
    res = min(res, calc(a[i], a[i + 1], a[i - 1]));
  }
  cout << fixed;
  cout << setprecision(8) << res << '\n';
}
