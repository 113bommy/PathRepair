#include <bits/stdc++.h>
using namespace std;
double mid, p, t;
int n, i, s;
double a[100005], b[100005], x[100005];
double lrlr(double l, double r) {
  while (l + 0.000001 <= r) {
    mid = (l + r) / 2;
    t = mid * p;
    for (i = 0; i < n; i++) {
      if (a[i] * mid > b[i]) {
        t -= a[i] * mid - b[i];
      }
    }
    if (t >= 0)
      l = mid;
    else
      r = mid - 0.000001;
  }
  return l;
}
int main() {
  cin >> n >> p;
  for (i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    s += a[i];
  }
  if (s <= p) {
    cout << -1 << endl;
    return 0;
  }
  printf("%.10f\n", lrlr(0, 10000000000));
  return 0;
}
