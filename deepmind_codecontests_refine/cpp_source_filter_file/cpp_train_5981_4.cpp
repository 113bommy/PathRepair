#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
const long long INF = 1000000007;
const double cp = 2 * asin(1.0);
const double eps = 1e-9;
const long long mod = 1000000007LL;
using namespace std;
int main() {
  long long n, s = 0, a[100001], ans = 0;
  cin >> n;
  for (int(i) = 0; (i) < (n); i++) {
    cin >> a[i];
    s += a[i];
  }
  s /= n;
  for (int(i) = 0; (i) < (n); i++) {
    if (a[i] < s) {
      ans += abs(a[i] - s);
      a[i + 1] - abs(a[i] - s);
    } else if (a[i] > s) {
      ans += abs(a[i] - s);
      a[i + 1] + abs(a[i] - s);
    }
  }
  cout << ans;
  return 0;
}
