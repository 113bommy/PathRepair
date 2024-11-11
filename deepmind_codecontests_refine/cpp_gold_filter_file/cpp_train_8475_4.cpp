#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  char a[n][n];
  int f = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 1; i < n - 1; i++) {
    for (j = 1; j < n - 1; j++) {
      if (a[i][j] == '#' && a[i - 1][j] == '#' && a[i + 1][j] == '#' &&
          a[i][j - 1] == '#' && a[i][j + 1] == '#') {
        a[i][j] = '.';
        a[i - 1][j] = '.';
        a[i + 1][j] = '.';
        a[i][j - 1] = '.';
        a[i][j + 1] = '.';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        f = 1;
        break;
      }
    }
  }
  if (f == 0)
    cout << "YES";
  else
    cout << "NO";
}
