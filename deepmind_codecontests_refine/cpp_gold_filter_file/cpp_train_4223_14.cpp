#include <bits/stdc++.h>
using namespace std;
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
int main() {
  long long d, k, a, b, t, x, ans;
  cin >> d >> k >> a >> b >> t;
  if (d % k == 0)
    x = d / k - 1;
  else
    x = d / k;
  ans = a * d + x * t;
  if (t + a * k - b * k < 0) {
    x = d / k;
    if (x > 1) ans = min(ans, (t + a * k - b * k) * x - t + b * d);
  }
  ans = min(ans, b * d);
  if (k <= d) ans = min(ans, a * k + b * (d - k));
  cout << ans << endl;
  return 0;
}
