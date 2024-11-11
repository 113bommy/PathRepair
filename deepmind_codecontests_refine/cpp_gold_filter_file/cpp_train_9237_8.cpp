#include <bits/stdc++.h>
using namespace std;
double dis(long long x1, long long x2, long long y2) {
  return (sqrt((x2 - x1) * (x2 - x1) + y2 * y2));
}
int main() {
  long long n;
  double vb, vs;
  cin >> n >> vb >> vs;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long x, y;
  cin >> x >> y;
  double min = 1000000;
  long long m = 0;
  double xm;
  for (long long i = n; i > 0; i--) {
    xm = a[i] / vb + dis(a[i], x, y) / vs;
    if (min > xm) {
      min = xm;
      m = i;
    }
  }
  cout << m + 1 << endl;
  return 0;
}
