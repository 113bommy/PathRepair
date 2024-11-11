#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, a[10000], s = 0;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (m >= n) {
      for (int i = 0; i < n - 1; i++) {
        s += a[i] + a[i + 1];
      }
      cout << s + a[0] + a[n - 1] << endl;
      for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << endl;
      }
      cout << n << " "
           << "1";
    } else {
      cout << "-1";
    }
    cout << "\n";
    s = 0;
  }
  return 0;
}
