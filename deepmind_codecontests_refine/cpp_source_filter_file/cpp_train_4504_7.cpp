#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, f = 1;
    cin >> n >> m;
    long long a[n][m];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        if (a[i][j] > 0) {
          if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
            if ((i == 0 && j == 0 || i == n - 1 && j == n - 1 ||
                 i == 0 && j == n - 1 || i == n - 1 && j == 0) &&
                a[i][j] > 2)
              f = 0;
            else if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
              if (a[i][j] > 3) f = 0;
            }
          } else {
            if (a[i][j] > 4) f = 0;
          }
        }
      }
    }
    if (f == 0)
      cout << "NO"
           << "\n";
    else {
      cout << "YES"
           << "\n";
      a[0][0] = 2;
      a[0][m - 1] = 2;
      a[n - 1][m - 1] = 2;
      a[n - 1][0] = 2;
      for (long long i = 1; i < m - 1; i++) {
        a[0][i] = 3;
        a[n - 1][i] = 3;
      }
      for (long long i = 1; i < n - 1; i++) {
        a[i][0] = 3;
        a[i][m - 1] = 3;
      }
      for (long long i = 1; i < n - 1; i++) {
        for (long long j = 1; j < m - 1; j++) a[i][j] = 4;
      }
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
