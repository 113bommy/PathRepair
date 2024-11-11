#include <bits/stdc++.h>
using namespace std;
signed main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    int pos = a[0], m = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] < pos) {
        m = max(m, pos - a[i]);
      }
      pos = max(pos, a[i]);
    }
    cout << ceil(log2(m + 1)) << "\n";
  }
}
