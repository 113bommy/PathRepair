#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, i, j, ans = 0, k = 1;
    cin >> n >> m;
    int a[n], b[m];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (i = 0; i < m; i++) {
      cin >> b[i];
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i] == b[j]) {
          ans = a[i];
          break;
        }
      }
      if (ans > 0) {
        break;
      }
    }
    if (ans == 0) {
      cout << "NO" << endl;
    } else {
      cout << "YES"
           << "\n"
           << k << " " << ans << endl;
    }
  }
}
