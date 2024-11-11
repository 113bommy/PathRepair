#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int n;
double x[N], y[N];
const double eps = 1e-3;
bool test(double h) {
  double left = -1e9, right = 1e9;
  for (int i = 0; i < n; i++) {
    double cx = x[i];
    double cy = y[i] > h ? h - (y[i] - h) : y[i];
    if (cy < 0) return 0;
    double moveLen = sqrt(h * h - (h - cy) * (h - cy));
    double r = cx + moveLen;
    double l = cx - moveLen;
    left = max(left, l);
    right = min(right, r);
  }
  return left < right;
}
int main() {
  cin >> n;
  bool existUp = 0, existDown = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    if (y[i] > 0) existUp = 1;
    if (y[i] < 0) existDown = 1;
  }
  if (existDown && existUp) {
    cout << -1 << endl;
    return 0;
  }
  if (existDown) {
    for (int i = 0; i < n; i++) y[i] *= -1;
  }
  double s = 0, t = 1e15;
  bool gotAns = 0;
  for (int i = 0; i < 32; i++) {
    double mid = (s + t) / 2;
    if (test(mid))
      t = mid;
    else
      s = mid, gotAns = 1;
  }
  if (abs(1e15 - s) < eps)
    cout << -2 << endl;
  else
    printf("%.10f\n", s);
  return 0;
}
