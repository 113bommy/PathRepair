#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e9 + 7, N1 = 1e6 + 4;
signed main() {
  long long int n, k;
  cin >> n >> k;
  char a[4][n];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = '.';
    }
  }
  if (k % 2 == 0) {
    if (k < n - 2) {
      for (int i = 1; i < n / 2 && k > 0; i++) {
        a[1][i] = '#';
        a[1][n - 1 - i] = '#';
        k -= 2;
      }
    } else {
      for (int i = 1; i < n / 2; i++) {
        a[1][i] = '#';
        a[1][n - 1 - i] = '#';
        k -= 2;
      }
      for (int i = 1; i < n / 2 && k > 0; i++) {
        a[2][i] = '#';
        a[2][n - 1 - i] = '#';
        k -= 2;
      }
      if (k != 0) {
        a[1][n / 2] = '#';
        a[2][n / 2] = '#';
        k -= 2;
      }
    }
    if (k <= 0) {
      cout << "YES" << endl;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
    } else
      cout << "NO" << endl;
  } else {
    if (k < n - 2) {
      for (int i = 1; i < n / 2 && k > 1; i++) {
        a[1][i] = '#';
        k--;
        if (k > 1) {
          a[1][n - 1 - i] = '#';
          k--;
        } else
          break;
      }
      if (k != 0) {
        a[1][n / 2] = '#';
        k--;
      }
    } else {
      for (int i = 1; i < n / 2; i++) {
        a[1][i] = '#';
        k--;
        if (k > 1) {
          a[1][n - 1 - i] = '#';
          k--;
        } else
          break;
      }
      a[1][n / 2] = '#';
      k--;
      for (int i = 1; i < n / 2 && k > 0; i++) {
        a[2][i] = '#';
        k--;
        if (k > 0) {
          a[2][n - 1 - i] = '#';
          k--;
        } else
          break;
      }
    }
    if (k <= 0) {
      cout << "YES" << endl;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
          cout << a[i][j];
        }
        cout << endl;
      }
    } else
      cout << "NO" << endl;
  }
  return 0;
}
