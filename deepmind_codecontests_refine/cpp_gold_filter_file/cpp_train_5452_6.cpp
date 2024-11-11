#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
struct comp {
  bool operator()(double a, double b) {
    if (fabs(a - b) < eps || a < b) return true;
    return false;
  }
};
double angle(double x, double y) {
  double ret;
  if (fabs(x) <= eps)
    ret = (y > 0 ? PI / 2.0 : 3.0 / 2.0 * PI);
  else if (fabs(y) <= eps)
    ret = (x > 0 ? 0 : PI);
  else {
    ret = atan(y / x);
    if (x > 0) {
      if (ret < 0) ret += 2 * PI;
    } else {
      if (y > 0)
        ret += PI;
      else
        ret += PI;
    }
  }
  return ret * 180 / PI;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  double x, y;
  set<double, comp> st;
  cin >> n;
  for (int i = 0; i < (int)(n); i++) {
    cin >> x >> y;
    st.insert(angle(x, y));
  }
  vector<double> v;
  for (__typeof(st.begin()) it = st.begin(); it != st.end(); ++it)
    v.push_back((*it));
  double ans = oo;
  for (int i = 1; i < (int)(((int)v.size())); i++) {
    ans = min(ans, 360.0 - (v[i] - v[i - 1]));
  }
  ans = min(ans, v[((int)v.size()) - 1] - v[0]);
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}
