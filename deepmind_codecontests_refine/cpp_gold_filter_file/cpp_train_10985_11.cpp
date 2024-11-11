#include <bits/stdc++.h>
using namespace std;
long double mySqrt(long double x) {
  long double l = 0;
  long double r = max((long double)1, x);
  for (int i = 0; i < 58; ++i) {
    long double m = (l + r) * (long double)0.5;
    if (m * m > x) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long double> a(n);
  vector<long double> b(n);
  vector<long double> p1(n);
  vector<long double> p2(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  long double sum, c1, c2, c3, bb, c, d, x1, x2;
  long double sp1 = 0;
  long double sp2 = 0;
  for (int i = 0; i < n; ++i) {
    sum = a[i] + b[i];
    c1 = sp2;
    c2 = sp1;
    c3 = a[i];
    bb = c2 - c1 - sum;
    c = c3 - sum * c2;
    d = bb * bb - 4 * c;
    d = mySqrt(d);
    x1 = (-bb + d) * 0.5;
    p1[i] = x1;
    sp1 += p1[i];
    p2[i] = sum - p1[i];
    sp2 += p2[i];
  }
  cout << fixed << setprecision(7);
  for (int i = 0; i < n; ++i) {
    cout << fabs(p1[i]) << " ";
  }
  cout << "\n";
  for (int i = 0; i < n; ++i) {
    cout << fabs(p2[i]) << " ";
  }
  cout << "\n";
  return 0;
}
