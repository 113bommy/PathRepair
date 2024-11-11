#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int i, n, m = 0, x = -1;
    cin >> n;
    int a[n];
    for (i = 0; i < n; ++i) {
      cin >> a[i];
      m = max(m, a[i]);
    }
    if (a[0] == m && a[1] != m) {
      x = 0;
    } else if (a[n - 1] == m && a[n - 2] != m) {
      x = n - 1;
    } else {
      for (i = 1; i < n - 1; ++i) {
        if (a[i] == m && (a[i - 1] != m || a[i + 1] != m)) {
          x = i;
          break;
        }
      }
    }
    cout << x << endl;
  }
}
