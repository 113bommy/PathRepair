#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = '.';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = '.';
    }
  }
  for (int i = 0; i < m; i++) a[0][i] = '#';
  int k = 0;
  int x = 0;
  while (k < n) {
    for (int i = 0; i < m; i++) a[k][i] = '#';
    if (x == 0) {
      if (k < n - 1) a[k + 1][m - 1] = '#';
      x = 1;
    } else {
      if (k < n - 1) a[k + 1][0] = '#';
      x = 0;
    }
    k = k + 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
