#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long double a, b, c, d, ans;
  cin >> a >> b >> c >> d;
  ans = a / b / (1 - (b - a) / b * (1 - c / d));
  cout << setprecision(10) << fixed << ans << "\n";
  return 0;
}
