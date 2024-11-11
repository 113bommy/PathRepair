#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, n;
  cin >> n;
  char a[n + 1][n + 1];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.' && a[i - 1][j] == '.' && a[i + 1][j] == '.' &&
          a[i][j - 1] == '.' && a[i][j + 1] == '.') {
        a[i][j] = '#';
        a[i + 1][j] = '#';
        a[i - 1][j] = '#';
        a[i][j - 1] = '#';
        a[i][j + 1] = '#';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
