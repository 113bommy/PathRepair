#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const double PI = 2 * acos(0.0);
long long a[N], b[N], c[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i] >> b[i];
    }
    if (n > 1) {
      for (int i = 0; i < n; i++) {
        if (i == 0) {
          c[i] = max(0LL, a[i] - b[n - 1]);
        } else {
          c[i] = max(0LL, a[i] - b[i - 1]);
        }
      }
    } else {
      cout << a[0] << '\n';
      continue;
    }
    long long ans = 1e18, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += c[i];
    }
    for (int i = 0; i < n; i++) {
      long long tmp = sum;
      if (c[i]) {
        tmp -= c[i];
      }
      ans = min(ans, a[i] + sum);
    }
    cout << ans << '\n';
  }
  return 0;
}
