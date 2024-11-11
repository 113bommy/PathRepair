#include <bits/stdc++.h>
using namespace std;
long long int tt;
long long int n, k;
vector<long long int> a;
bool check(double x) {
  double s = 0, s1 = 0;
  for (long long int i = 0; i < n; i++) {
    if (a[i] > x) {
      double y = (double(a[i] - x));
      y = y - ((double)(y * k) / 100.00);
      s = s + y;
    } else {
      s1 = s1 + (double(x - a[i]));
    }
  }
  if (s >= s1) {
    return true;
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  a.resize(n);
  double l = 1e18, r = (-1) * 1e18;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    l = min(l, double(a[i]));
    r = max(r, double(a[i]));
  }
  double x = (double)(1 / double(1000000));
  while ((r - l) > x) {
    double mid;
    mid = ((double)(l + r) / 2.0);
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  cout << setprecision(6);
  cout << fixed;
  cout << l << endl;
  return 0;
}
