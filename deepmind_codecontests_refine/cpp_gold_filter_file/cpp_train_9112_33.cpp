#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.0000001, eps = 0.000000001;
int n;
double k;
vector<double> v;
int f(double t) {
  double up = 0, down = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] > t) {
      up += v[i] - t;
    } else {
      down += t - v[i];
    }
  }
  return (up * (100 - k) / 100.0) >= down - eps;
}
double bin_search() {
  double mid, l = 0, r = 1001;
  while (l + EPS < r) {
    mid = (l + r) / 2;
    if (f(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}
int main() {
  scanf("%d %lf", &n, &k);
  v.resize(n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &v[i]);
  }
  printf("%.7lf", bin_search());
  return 0;
}
