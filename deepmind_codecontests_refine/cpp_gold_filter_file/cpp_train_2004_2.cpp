#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    vector<vector<int> > result(n, vector<int>(m, 0));
    int shift = 0;
    for (shift = 1; shift < m; shift++) {
      if (shift * n % m == 0) {
        break;
      }
    }
    for (int i = 0, dx = 0; i < n; i++, dx += shift) {
      for (int j = 0; j < a; j++) {
        result[i][(j + dx) % m] = 1;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << result[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
