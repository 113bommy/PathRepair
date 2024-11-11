#include <bits/stdc++.h>
using namespace std;
const long long INF = 11000000;
const int MOD = 1000000007;
int main() {
  long double a, b, c, d;
  cin >> a >> b >> c >> d;
  long double res = 0.0000000;
  long double ret = (1 - (a / b)) * (1 - (c / d));
  for (int i = 0; i <= 5000; i++) {
    long double act = 1.000000000;
    for (int j = 0; j < int(i); j++) {
      act *= ret;
    }
    res += (act * (a / b));
  }
  cout << fixed << setprecision(7) << res << endl;
}
