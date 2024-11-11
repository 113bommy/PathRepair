#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  double p = a / b, q = c / d;
  double ans = 0;
  for (long long int i = 0; i < 100; i++) {
    ans += pow((1 - p) * (1 - q), i) * p;
  }
  cout << setprecision(10) << fixed << ans;
  return 0;
}
