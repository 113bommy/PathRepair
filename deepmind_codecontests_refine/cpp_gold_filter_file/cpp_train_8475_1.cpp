#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  ;
  int n, ans = 0;
  cin >> n;
  char a[n + 2][n + 2];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cin >> a[i][j];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '#') {
        if (a[i + 1][j] == '#' && a[i + 1][j - 1] == '#' &&
            a[i + 1][j + 1] == '#' && a[i + 2][j] == '#') {
          a[i + 1][j] = '.', a[i + 1][j - 1] = '.', a[i + 1][j + 1] = '.',
                a[i + 2][j] = '.';
        } else
          return cout << "NO", 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
