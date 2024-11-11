#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
vector<double> c;
double mcs(vector<int> &a, double x) {
  int i;
  for (i = 0; i < c.size(); ++i) c[i] = a[i] - x;
  double sum = 0, res = 0;
  for (i = 0; i < c.size(); ++i) {
    sum += c[i];
    res = max(res, sum);
    if (sum < 0) sum = 0;
  }
  return res;
}
int main() {
  int n, i;
  cin >> n;
  c = vector<double>(n);
  vector<int> a(n), b(n);
  for (i = 0; i < n; ++i) {
    cin >> a[i];
    b[i] = -a[i];
  }
  double l = *min_element(a.begin(), a.end()),
         r = *max_element(a.begin(), a.end());
  while (fabs(l - r) > .00000001) {
    double m = (l + r) / 2;
    double pos = mcs(a, m);
    double neg = mcs(b, -m);
    if (pos > neg) {
      l = m;
    } else {
      r = m;
    }
  }
  double m = (l + r) / 2;
  printf("%.7lf", max(mcs(a, m), mcs(b, -m)));
  return 0;
}
