#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const long long inf64 = ((long long)1 << 62) - 1;
const long double pi = acos(-1);
template <class T>
T sqr(T x) {
  return x * x;
}
template <class T>
T abs(T x) {
  return x < 0 ? -x : x;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  double x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;
  vector<long double> x0(n);
  vector<long double> y0(n);
  vector<long double> vx(n);
  vector<long double> vy(n);
  for (int i = 0; i < n; ++i) {
    cin >> x0[i] >> y0[i] >> vx[i] >> vy[i];
  }
  long double min_t = 0, max_t = 1e100;
  for (int i = 0; i < n; ++i) {
    if (abs(vx[i]) < eps) {
      if (x0[i] < x1 + eps || x0[i] > x2 - eps) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      long double t1 = (x1 - x0[i]) / vx[i];
      long double t2 = (x2 - x0[i]) / vx[i];
      min_t = max(min_t, min(t1, t2));
      max_t = min(max_t, max(t1, t2));
    }
    if (abs(vy[i]) < eps) {
      if (y0[i] < y1 + eps || y0[i] > y2 - eps) {
        cout << -1 << endl;
        return 0;
      }
    } else {
      long double t1 = (y1 - y0[i]) / vy[i];
      long double t2 = (y2 - y0[i]) / vy[i];
      min_t = max(min_t, min(t1, t2));
      max_t = min(max_t, max(t1, t2));
    }
  }
  if (min_t + eps > max_t) {
    cout << -1 << endl;
    return 0;
  }
  cout.precision(20);
  cout << min_t << endl;
  return 0;
}
