#include <bits/stdc++.h>
using namespace std;
const int X = 100000 + 5;
long double foo1(vector<long double> &v) {
  long double s = 0, mx = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    s += v[i];
    mx = max(mx, s);
    if (s < 1e-10) s = 0;
  }
  return mx;
}
long double foo(long double x, vector<long double> v) {
  for (int i = 0; i < (int)v.size(); i++) v[i] = v[i] - x;
  long double s = foo1(v);
  for (int i = 0; i < (int)v.size(); i++) v[i] *= -1;
  s = max(s, foo1(v));
  return s;
}
long double calc(vector<long double> &v) {
  long double lo = -1e5, hi = 1e5;
  for (int it = 1; it < 100; it++) {
    long double ml = lo + (hi - lo) / 3.0, mr = hi - (hi - lo) / 3.0;
    if (foo(ml, v) <= foo(mr, v))
      hi = mr;
    else
      lo = ml;
  }
  return foo(lo, v);
}
void MAIN() {
  int n;
  long double x;
  cin >> n;
  vector<long double> v;
  for (int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
  }
  cout << calc(v);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(12);
  MAIN();
  return 0;
}
