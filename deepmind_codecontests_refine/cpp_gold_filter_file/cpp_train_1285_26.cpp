#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int MAXN = 100005;
int main() {
  long double k, b, n, t;
  cin >> k >> b >> n >> t;
  long double x, y, z;
  if (k == 1) {
    z = 1 + n * 1.0 * b;
    x = (z - t) / b;
  } else {
    y = ((k - 1) * 1.0 * t + b) * 1.0 / (k - 1 + b);
    x = n - (log(y) / log(k));
  }
  long long ans = (x < 0) ? 0 : (long long)ceil(x);
  cout << ans;
}
