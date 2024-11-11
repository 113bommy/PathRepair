#include <bits/stdc++.h>
using namespace std;
bool three_points_collinear(const complex<double> &a, const complex<double> &b,
                            const complex<double> &c) {
  return (a.imag() - b.imag()) * (a.real() - c.real()) ==
         (a.imag() - c.imag()) * (a.real() - b.real());
}
complex<double> arr[2005], center;
bool sorter(complex<double> x, complex<double> y) {
  double a = x.imag() - center.imag();
  double b = y.imag() - center.imag();
  if (x.real() == center.real())
    a = 1e15;
  else
    a /= (x.real() - center.real());
  if (y.real() == center.real())
    b = 1e15;
  else
    b /= (y.real() - center.real());
  return a < b;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, x, y;
  cin >> n;
  if (n < 3) {
    cout << 0;
    return 0;
  }
  long long res = n * 1LL * (n - 1) * (n - 2) / 6;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    arr[i] = complex<double>(x, y);
  }
  for (int i = 0; i < n - 1; i++) {
    center = arr[i];
    vector<complex<double> > v;
    for (int j = i + 1; j < n; j++) v.push_back(arr[j]);
    sort(v.begin(), v.end(), sorter);
    for (int j = 0; j < v.size();) {
      int x = j;
      while (x + 1 < v.size() && three_points_collinear(center, v[j], v[x + 1]))
        x++;
      x++;
      int tmp = x;
      x -= j;
      j = tmp;
      res -= x * 1LL * (x - 1) / 2;
    }
  }
  cout << res;
  return 0;
}
