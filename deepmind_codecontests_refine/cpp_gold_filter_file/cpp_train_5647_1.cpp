#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    char arr[n][m];
    for (int i = 0; i < n; ++i) {
      int f;
      if (i & 1)
        f = 1;
      else
        f = 2;
      for (int j = 0; j < m; ++j) {
        if (f == 2) {
          arr[i][j] = 'B';
          f = 1;
        } else if (f == 1) {
          arr[i][j] = 'W';
          f = 2;
        }
      }
    }
    long long int z = n * m;
    if (z % 2 == 0) {
      if (n & 1 && m > 1)
        arr[n - 1][1] = 'B';
      else
        arr[n - 1][0] = 'B';
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) cout << arr[i][j];
      cout << endl;
    }
  }
  return 0;
}
