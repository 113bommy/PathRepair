#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n, f = 0, pos = 0;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        if (a[i] == b[j]) {
          f = 1;
          pos += a[i];
          break;
        }
    }
    if (f != 0)
      cout << "YES\n"
           << "1 " << pos << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
