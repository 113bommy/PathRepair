#include <bits/stdc++.h>
using namespace std;
long long d, k, a, b, t;
int main() {
  cin >> d >> k >> a >> b >> t;
  long long ans = 0;
  if (d <= k) {
    cout << a * d;
    exit(0);
  }
  d -= k;
  ans += a * k;
  if (k * b > a * k + t) {
    if (d % k == 0) {
      cout << d / k * (a * k + t);
      exit(0);
    }
    long long tms = d / k;
    d -= tms * k;
    ans += tms * (t + a * k);
    if (a * d + t < b * d) {
      ans += a * d + t;
    } else {
      ans += b * d;
    }
    cout << ans;
  } else {
    cout << ans + d * b;
  }
  return 0;
}
