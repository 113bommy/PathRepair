#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  char a[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      int k = 0;
      if (a[i][j] == '.') {
        if (i >= 0 && j - 1 >= 0 && a[i + 1][j - 1] != '#' &&
            a[i + 1][j] != '#' && a[i + 1][j + 1] != '#' &&
            a[i + 2][j] != '#' && i + 2 < n && j + 1 < n) {
          a[i][j] = '#';
          a[i + 1][j - 1] = '#';
          a[i + 1][j] = '#';
          a[i + 1][j + 1] = '#';
          a[i + 2][j] = '#';
        } else {
          cout << "NO";
          return 0;
        }
      }
    }
  }
  cout << "YES";
}
