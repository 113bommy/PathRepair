#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int m, n;
  cin >> m >> n;
  if (m == 1 && n == 1)
    cout << 0 << '\n';
  else if (m == 1)
    for (int i = 1; i <= n; i++) cout << i << " ";
  else if (n == 1)
    for (int i = 1; i <= m; i++) cout << i << '\n';
  else {
    int a[m + 1][n + 1];
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = i * (j + n);
      }
    }
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cout << a[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
