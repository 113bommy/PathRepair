#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  char a[n][m];
  int flag = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) {
      for (int j = 0; j < m; ++j) a[i][j] = '#';
    }
    if (i % 2 != 0) {
      if (flag == 0) {
        for (int j = 0; j < m - 1; ++j) a[i][j] = '.';
        a[i][m - 1] = '#';
        flag = 1;
      } else {
        for (int j = 1; j < m; ++j) a[i][j] = '.';
        a[i][0] = '#';
        flag = 0;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) cout << a[i][j];
    cout << endl;
  }
}
