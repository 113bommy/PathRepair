#include <bits/stdc++.h>
using namespace std;
double m1 = 0.000001;
double usedw;
double binarysearch(double a[], double b[], long long int n, long long int m,
                    double s, double e) {
  double mid = (s + e) / 2;
  double fuel = mid;
  if (e - s > m1) {
    double w = m + mid;
    for (long long int i = 0; i < n; i++) {
      usedw = (w) / a[i];
      w -= usedw;
      fuel -= usedw;
      usedw = (w) / b[i];
      w -= usedw;
      fuel - usedw;
    }
    if (w > m)
      return binarysearch(a, b, n, m, s, mid);
    else if (w < m) {
      if (e < 1000000000)
        return binarysearch(a, b, n, m, mid, e);
      else
        return -1;
    }
  }
  return mid;
}
signed main() {
  long long int n, m;
  cin >> n >> m;
  double a[n], b[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  cin >> b[n - 1];
  for (long long int i = 0; i < n - 1; i++) cin >> b[i];
  cout << fixed << setprecision(10) << binarysearch(a, b, n, m, 0, 2000000000);
  return 0;
}
