#include <bits/stdc++.h>
using namespace std;
int n;
long double w, v, u;
int main() {
  cin >> n >> w >> v >> u;
  long double ans = 0;
  long double mxx = 0;
  bool lol = 0;
  for (int i = 0; i < n; ++i) {
    long double x, y;
    cin >> x >> y;
    x -= (v / u) * y;
    mxx = max(mxx, x);
    if (x < 0) lol = 1;
  }
  if (lol)
    cout << setprecision(20) << mxx / v + w / u << "\n";
  else
    cout << setprecision(20) << w / u << "\n";
}
