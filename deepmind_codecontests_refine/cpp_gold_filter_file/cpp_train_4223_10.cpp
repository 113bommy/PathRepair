#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;
  if (d <= k)
    cout << d * a << endl;
  else {
    long long ans = k * a;
    d -= k;
    long long vc = k * a + t;
    long long vf = b * k;
    if (vf <= vc) {
      ans += d * b;
    } else {
      ans += d / k * vc;
      long long s = d % k;
      if (s * a + t <= b * s)
        ans += s * a + t;
      else
        ans += b * s;
    }
    cout << ans << endl;
  }
  return 0;
}
