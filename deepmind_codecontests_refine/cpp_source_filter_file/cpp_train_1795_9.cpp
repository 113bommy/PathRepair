#include <bits/stdc++.h>
using namespace std;
void solve() {
  vector<long long> v;
  long long a;
  while (cin >> a) {
    v.push_back(a);
  }
  while (!v.empty()) {
    long long u = v.back();
    v.pop_back();
    long double ar = sqrt(abs(u));
    long double br = pow(u, 3) * 5;
    long double r = ar + br;
    if (u >= 10) {
      cout << "f(" << u << ") = MAGNA NIMIS!";
    } else {
      cout << "f(" << u << ") = " << fixed << setprecision(2) << r;
    }
    cout << "\n";
  }
}
signed main() {
  long long t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
