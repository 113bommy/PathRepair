#include <bits/stdc++.h>
using namespace std;
int main() {
  long long d, k, a, b, t;
  cin >> d >> k >> a >> b >> t;
  if (k >= d) {
    cout << k * a;
    return 0;
  }
  long long ans = k * a;
  d -= k;
  if (k * b <= k * a + t) {
    ans += d * b;
    cout << ans;
    return 0;
  }
  long long x = d / k;
  ans += x * (k * a + t);
  d -= x * k;
  ans += min(d * b, d * a + t);
  cout << ans;
  return 0;
}
