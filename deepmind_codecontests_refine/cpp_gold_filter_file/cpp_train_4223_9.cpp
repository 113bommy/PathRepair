#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
long long d, k, a, b, t;
int main() {
  cin >> d >> k >> a >> b >> t;
  if (d <= k) {
    cout << d * a;
  } else if (t + k * a > k * b) {
    cout << k * a + (d - k) * b;
  } else {
    long long cnt = d / k;
    long long ans =
        k * a * cnt + (cnt - 1) * t + min(t + (d % k) * a, (d % k) * b);
    cout << ans;
  }
  return 0;
}
