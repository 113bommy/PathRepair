#include <bits/stdc++.h>
using namespace std;
char a[70][70];
int t, n, m;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    int f = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == 'A') f++;
    if (f == 0) {
      cout << "MORTAL\n";
      continue;
    } else if (f == n * m) {
      cout << 0 << endl;
      continue;
    }
    f = 0;
    for (int i = 0; i < n; i++)
      if (a[i][0] == 'A') f++;
    if (f == n) {
      cout << "1\n";
      continue;
    }
    f = 0;
    for (int i = 0; i < n; i++)
      if (a[i][m - 1] == 'A') f++;
    if (f == n) {
      cout << "1\n";
      continue;
    }
    f = 0;
    for (int i = 0; i < m; i++)
      if (a[0][i] == 'A') f++;
    if (f == m) {
      cout << "1\n";
      continue;
    }
    f = 0;
    for (int i = 0; i < m; i++)
      if (a[n - 1][i] == 'A') f++;
    if (f == m) {
      cout << "1\n";
      continue;
    }
    if (a[0][0] == 'A' || a[0][m - 1] == 'A' || a[n - 1][0] == 'A' ||
        a[n - 1][m - 1] == 'A') {
      cout << 2 << endl;
      continue;
    }
    int gg = 0;
    for (int i = 0; i < n; i++) {
      f = 0;
      for (int j = 0; j < m; j++)
        if (a[i][j] == 'A') f++;
      if (f == m) {
        gg = 1;
        break;
      }
    }
    if (gg) {
      cout << 2 << endl;
      continue;
    }
    for (int i = 0; i < m; i++) {
      f = 0;
      for (int j = 0; j < n; j++)
        if (a[i][j] == 'A') f++;
      if (f == n) {
        gg = 1;
        break;
      }
    }
    if (gg) {
      cout << 2 << endl;
      continue;
    }
    for (int i = 0; i < n; i++)
      if (a[i][0] == 'A' || a[i][m - 1] == 'A') {
        gg = 1;
        break;
      }
    if (gg) {
      cout << 3 << endl;
      continue;
    }
    for (int i = 0; i < m; i++)
      if (a[0][i] == 'A' || a[n - 1][i] == 'A') {
        gg = 1;
        break;
      }
    if (gg) {
      cout << 3 << endl;
      continue;
    } else
      cout << 4 << endl;
  }
  return 0;
}
