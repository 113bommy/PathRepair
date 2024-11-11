#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, u, i, j, k;
  cin >> n;
  bool f = false;
  char arr[n][n];
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cin >> arr[i][j];
  }
  for (i = 0; i < n - 2; i++) {
    for (j = 1; j < n - 1; j++) {
      if (arr[i][j] == '.') {
        if (arr[i + 1][j] == '.' && arr[i + 1][j + 1] == '.' &&
            arr[i + 1][j - 1] == '.' && arr[i + 2][j] == '.') {
          arr[i][j] = '#';
          arr[i + 1][j + 1] = '#';
          arr[i + 1][j - 1] = '#';
          arr[i + 1][j] = '#';
          arr[i + 2][j] = '#';
        } else {
          f = true;
          break;
        }
      }
    }
    if (f) break;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (arr[i][j] == '.') {
        f = true;
        break;
      }
    }
    if (f) break;
  }
  if (f)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
