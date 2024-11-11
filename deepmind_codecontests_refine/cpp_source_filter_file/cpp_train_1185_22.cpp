#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  long double a, b, c, d, ans, diff, first;
  cin >> a >> b >> c >> d;
  first = c / d;
  diff = (1 - c / d) * (1 - a / b);
  ans = first / (1 - diff);
  cout << fixed << setprecision(10) << ans;
}
