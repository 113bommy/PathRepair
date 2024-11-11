#include <bits/stdc++.h>
using namespace std;
bool sma(long double a, long double n) {
  if (a * (n - a) < n)
    return true;
  else
    return false;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    long double l = 0, r = n / 2;
    while (r - l > 1e-10) {
      long double mid = (l + r) / 2;
      if (sma(mid, n))
        l = mid;
      else
        r = mid;
    }
    if (abs(r * (n - r) - n) <= 1e-6)
      cout << "Y " << fixed << setprecision(8) << n - r << " " << r << endl;
    else
      cout << "N" << endl;
  }
  return 0;
}
