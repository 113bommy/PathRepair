#include <bits/stdc++.h>
using namespace std;
template <typename X>
ostream& operator<<(ostream& x, const vector<X>& v) {
  for (long long i = 0; i < v.size(); ++i) x << v[i] << " ";
  return x;
}
template <typename X>
ostream& operator<<(ostream& x, const set<X>& v) {
  for (auto it : v) x << it << " ";
  return x;
}
template <typename X, typename Y>
ostream& operator<<(ostream& x, const pair<X, Y>& v) {
  x << v.first << " " << v.second;
  return x;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << "=>" << it.second << endl;
  return os;
}
double h, c, t;
double f(long long x) {
  double res = (((h + c) * x + h) / (2.0 * x + 1)) - t;
  return fabs(res);
}
long long ternary() {
  long long l = 0, r = 2e9;
  while (l <= r - 5) {
    long long m1 = l + (r - l) / 3;
    long long m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  for (long long i = l; i <= r; i++) {
    if (f(i) <= f(i + 1)) {
      return i;
    }
  }
  return l;
}
void solve() {
  cout << setprecision(20);
  cin >> h >> c >> t;
  double diff = fabs((h + c) / 2.0 - t);
  long long res = ternary();
  double diff2 = f(res);
  double diff3 = abs(h - t);
  42;
  double mn = min({diff, diff2, diff3});
  for (long long j = 0; j <= 30; j++) {
    42;
  }
  if (mn == diff3) {
    cout << 1 << endl;
    return;
  }
  if (mn == diff) {
    cout << 2 << endl;
  } else if (mn == diff2) {
    cout << 2 * res + 1 << endl;
  } else {
    cout << 1 << endl;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
