#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, p, k, prefix, i, sum, j, val, ans = 0;
    cin >> n >> p >> k;
    long long int a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    prefix = 0;
    for (i = 0; i < min(n, k); i++) {
      val = 0;
      sum = p;
      sum -= prefix;
      if (sum >= 0) {
        val += i;
      } else {
        break;
      }
      for (j = i + k; j < n; j += k) {
        if (sum >= a[j]) {
          val += k;
          sum -= a[j];
        } else {
          break;
        }
      }
      ans = max(ans, val);
      prefix += a[i];
    }
    cout << ans << endl;
  }
}
