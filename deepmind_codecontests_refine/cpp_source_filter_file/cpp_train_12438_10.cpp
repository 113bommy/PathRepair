#include <bits/stdc++.h>
using namespace std;
const long long nax = 2e5 + 7;
long long n;
vector<double> a;
bool check(double d, vector<double> &v) {
  v.push_back(a[0] + d);
  for (long long i = 1; i < n; ++i) {
    while (i < n && v.back() + d >= a[i]) i++;
    if (i < n) v.push_back(a[i] + d);
  }
  while (v.size() < 3) v.push_back(v.back() + 1e-6);
  if (v.size() <= 3) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  for (long long i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  a.resize(distance(a.begin(), unique(a.begin(), a.end())));
  n = a.size();
  double lo = 0, hi = 1e4, ans = 0;
  vector<double> res, temp;
  while (hi - lo >= 1e-6) {
    double mi = (hi + lo) / 2;
    temp.clear();
    if (check(mi, temp)) {
      hi = mi - 1e-6;
      res = temp;
      ans = mi;
    } else
      lo = mi + 1e-6;
  }
  cout << fixed << setprecision(6);
  cout << ans << "\n";
  for (auto it : res) cout << it << " ";
}
