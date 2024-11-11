#include <bits/stdc++.h>
using namespace std;
void go(int n, int m, bool c) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (c && i == n - 1 && j >= m - 2) {
        cout << 'R';
        continue;
      }
      if ((i + j) & 1) {
        cout << 'W';
      } else {
        cout << 'R';
      }
    }
    cout << endl;
  }
}
int main() {
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    if ((n * m) & 1) {
      go(n, m, false);
    } else {
      go(n, m, true);
    }
  }
}
