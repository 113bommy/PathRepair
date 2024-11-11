#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[60];
  if (m - k <= 0) {
    cout << 0 << endl;
  } else {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
      sum += a[i];
      if (i < n - 1) {
        sum--;
      }
    }
    if (sum + k - 1 < m) {
      cout << -1 << endl;
      return 0;
    }
    k--;
    m -= k;
    int sum2 = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (i < n - 1) {
        a[i]--;
      }
      if (m >= a[i] && m > 0) {
        sum2++;
        m -= a[i];
      } else if (m > 0 && m < a[i]) {
        sum2++;
        break;
      }
    }
    cout << sum2 << endl;
  }
  return 0;
}
