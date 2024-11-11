#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long a, b, c, d;
  double f, r;
  cin >> a >> b >> c >> d;
  f = (double)a / b;
  r = f * (1 - (double)c / d);
  cout << fixed << setprecision(8) << f / (1 - r);
}
