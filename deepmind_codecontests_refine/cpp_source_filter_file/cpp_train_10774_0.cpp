#include <bits/stdc++.h>
using namespace std;
vector<int> data;
double f(double x) {
  double mnp = 0, mxp = 0, res = 0, pref = 0;
  for (int i = 0; i < data.size(); i++) {
    pref += data[i] - x;
    res = max(res, max(pref - mnp, mxp - pref));
    mnp = min(mnp, pref);
    mxp = max(mxp, pref);
  }
  return res;
}
int main() {
  int n;
  cin >> n;
  data.resize(n);
  for (int i = 0; i < n; i++) cin >> data[i];
  double l = -1e10, r = 1e10, m1, m2;
  for (int i = 0; i < 100; i++) {
    m1 = (l * 2 + r) / 3;
    m2 = (l + r * 2) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else
      l = m1;
  }
  cout.precision(13);
  cout << f(l);
  return 0;
}
