#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using dd = double;
using ldd = long double;
using si = short int;
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ldd> mi(n + 1), ma(n + 1);
  for (int i = 1; i <= n; ++i) cin >> ma[i];
  for (int i = 1; i <= n; ++i) cin >> mi[i];
  vector<ldd> x(n + 1), y(n + 1);
  ldd s1, s2;
  s1 = s2 = 0;
  for (int i = n; i > 0; --i) {
    ldd b = mi[i];
    ldd a = ma[i];
    0;
    ;
    0;
    ;
    0;
    ;
    0;
    ;
    0;
    ;
    0;
    ;
    ldd d = (s2 - s1 - b - a) * (s2 - s1 - b - a) - 4 * (b - b * s2 - a * s2);
    0;
    ;
    if (d < 1e-10) d = 0;
    d = sqrtl(d);
    ldd a1 = -(s2 - s1 - b - a) + d;
    a1 /= 2;
    y[i] = a1;
    a1 = (b - a1 * s1) / (s2 + a1);
    x[i] = a1;
    s1 += x[i];
    s2 += y[i];
  }
  cout << setprecision(4) << fixed;
  for (int i = 1; i <= n; ++i) cout << x[i] << " ";
  cout << '\n';
  for (int i = 1; i <= n; ++i) cout << y[i] << " ";
  return 0;
}
