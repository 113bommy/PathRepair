#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int a[n];
    int count = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    int min = *min_element(a, a + n);
    for (int i = 0; i < n; i++) {
      if (a[i] < k) {
        count += (k - a[i]) / min;
      }
    }
    if (min < k) count -= (k - min) / min;
    cout << count << endl;
  }
}
