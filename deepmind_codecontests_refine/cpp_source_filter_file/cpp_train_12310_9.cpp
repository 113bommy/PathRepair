#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    int a[n], b[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < k; i++) {
      if (a[i] < b[n - 1 - i])
        a[i] = b[n - 1 - i];
      else
        break;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans;
  }
}
