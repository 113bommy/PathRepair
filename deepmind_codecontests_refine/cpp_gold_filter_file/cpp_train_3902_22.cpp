#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  for (int i = 0; i < n;) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = '#';
    }
    i = i + 2;
  }
  int count = 1;
  for (int i = 1; i < n;) {
    if (count % 2 != 0) {
      a[i][m - 1] = '#';
      count++;
    } else {
      a[i][0] = '#';
      count++;
    }
    i = i + 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != '#') a[i][j] = '.';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; ++j) {
      cout << a[i][j];
    }
    cout << endl;
  }
  return 0;
}
