#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e, f, ans = 0;
  cin >> a >> b >> c >> d >> e >> f;
  if (e <= f) {
    if (d <= b && d <= c)
      ans = d * f;
    else {
      ans = min(b, c) * f;
      d -= min(b, c);
      ans += min(a, d) * e;
    }
  } else {
    if (d <= a)
      ans = d * e;
    else {
      ans = a * e;
      d -= a;
      ans += min(b, min(c, d)) * f;
    }
  }
  cout << ans;
  return 0;
}
