#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 1e5 + 5;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long double n, w, v, u;
  cin >> n >> w >> v >> u;
  long double mn = 1e9, mx = 0;
  for (int i = 0; i < n; i++) {
    long double x, y;
    cin >> x >> y;
    long double dif = x / v - y / u;
    mn = min(mn, dif);
    mx = max(mx, dif);
  }
  long double ans = w / u;
  if (mn < -1e-6) ans += mx;
  cout << fixed << setprecision(9) << ans;
  return 0;
}
