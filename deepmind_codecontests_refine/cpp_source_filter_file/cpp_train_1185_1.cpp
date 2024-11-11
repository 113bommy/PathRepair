#include <bits/stdc++.h>
using namespace std;
void sol() {
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  double e = (a * d) / (d * b - a * d + a * c);
  cout << fixed << setprecision(12) << e << "\n";
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    sol();
  }
  return 0;
}
