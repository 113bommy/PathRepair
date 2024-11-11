#include <bits/stdc++.h>
using namespace std;
char a[110][110];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cin >> (a[i] + 1);
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '1') cnt++;
      }
    }
    cout << cnt * 3 << '\n';
    for (int i = 1; i < n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '1') {
          if (j < m) {
            cout << i << ' ' << j << ' ' << i << ' ' << j + 1 << ' ' << i + 1
                 << ' ' << j << '\n';
            cout << i << ' ' << j << ' ' << i << ' ' << j + 1 << ' ' << i + 1
                 << ' ' << j + 1 << '\n';
            cout << i << ' ' << j << ' ' << i + 1 << ' ' << j << ' ' << i + 1
                 << ' ' << j + 1 << '\n';
          } else {
            cout << i << ' ' << j << ' ' << i << ' ' << j - 1 << ' ' << i + 1
                 << ' ' << j << '\n';
            cout << i << ' ' << j << ' ' << i << ' ' << j - 1 << ' ' << i + 1
                 << ' ' << j - 1 << '\n';
            cout << i << ' ' << j << ' ' << i + 1 << ' ' << j - 1 << ' '
                 << i + 1 << ' ' << j << '\n';
          }
        }
      }
    }
    for (int j = 1; j <= m; j++) {
      if (a[n][j] == '1') {
        if (j < m) {
          cout << n << ' ' << j << ' ' << n << ' ' << j + 1 << ' ' << n - 1
               << ' ' << j << '\n';
          cout << n << ' ' << j << ' ' << n << ' ' << j + 1 << ' ' << n - 1
               << ' ' << j + 1 << '\n';
          cout << n << ' ' << j << ' ' << n - 1 << ' ' << j << ' ' << n - 1
               << ' ' << j + 1 << '\n';
        } else {
          cout << n << ' ' << j << ' ' << n << ' ' << j + 1 << ' ' << n - 1
               << ' ' << j << '\n';
          cout << n << ' ' << j << ' ' << n << ' ' << j + 1 << ' ' << n - 1
               << ' ' << j + 1 << '\n';
          cout << n << ' ' << j << ' ' << n - 1 << ' ' << j << ' ' << n - 1
               << ' ' << j - 1 << '\n';
        }
      }
    }
  }
  return 0;
}
