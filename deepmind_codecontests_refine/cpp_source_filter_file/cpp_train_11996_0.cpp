#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int tt, n, m, i, j;
  tt = 1;
  while (tt--) {
    cin >> n >> m;
    if (n * (n - 1) * (n - 2) < 6 * m) {
      cout << -1 << endl;
    } else {
      int tot = 0;
      for (i = 3; i <= n; i++) {
        tot += (i - 1) / 2;
        if (tot >= m) break;
      }
      if (tot < m) {
        cout << -1 << endl;
        return 0;
      }
      int diff = tot - m;
      int last = i + diff;
      for (j = 1; j < i && j < n; j++) {
        cout << j << ' ';
      }
      cout << last << ' ';
      for (j = i + 1; j <= n; j++) {
        cout << 1000000000 - 5002 * (n - j) << ' ';
      }
      cout << endl;
    }
  }
  return 0;
}
