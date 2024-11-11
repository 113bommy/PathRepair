#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  double a, b, c, d;
  cin >> a >> b >> c >> d;
  if (b / a == c / b && d / c) {
    double ans = d / c * d;
    if (ceil(ans) == ans)
      cout << ans;
    else
      cout << 42;
  } else if (b - a == c - b && d - c == c - b) {
    double ans = d + d - c;
    cout << ans;
  } else
    cout << 42;
}
