#include <bits/stdc++.h>
using namespace std;
int a[200][200];
int b[200][200];
bool ok = true;
void sol(int n, int m) {
  if (m <= 2) {
    ok = false;
    return;
  }
  int i, j;
  if (m == 3 && n == 3) {
    a[0][0] = 0;
    a[0][1] = 2;
    a[0][2] = 4;
    a[1][0] = 3;
    a[1][1] = 5;
    a[1][2] = 7;
    a[2][0] = 8;
    a[2][1] = 6;
    a[2][2] = 1;
    return;
  }
  if (m == 4) {
    a[0][0] = 1;
    a[0][1] = 3;
    a[0][2] = 0;
    a[0][3] = 2;
  } else {
    i = 0;
    a[i][0] = i * m;
    j = 0;
    int dem = i * m;
    while (dem + 2 <= (i * m + m - 1)) {
      j++;
      a[i][j] = dem + 2;
      dem += 2;
    }
    dem = i * m + 1;
    a[i][j + 1] = dem;
    j++;
    while (dem + 2 <= (i * m + m - 1)) {
      j++;
      a[i][j] = dem + 2;
      dem += 2;
    }
  }
  for (i = 1; i < n; i++)
    for (j = 0; j < m; j++) a[i][j] = a[i - 1][j] + m;
  if (m == 3) {
    for (i = 0; i < n - 1; i++) {
      int t = a[i][m - 1];
      a[i][m - 1] = a[i + 1][m - 1];
      a[i + 1][m - 1] = t;
      i++;
    }
  }
}
int main() {
  int n, m;
  int i, j;
  cin >> n >> m;
  if (m == 1 && n == 1) {
    cout << 1 << endl;
    return 0;
  }
  if (m == 1 && n == 3) {
    cout << -1 << endl;
    return 0;
  }
  if (m == 3 && n == 1) {
    cout << -1 << endl;
    return 0;
  }
  if (n <= m) {
    sol(n, m);
    if (ok == false) {
      cout << -1 << endl;
      return 0;
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) cout << a[i][j] + 1 << " ";
      cout << endl;
    }
  } else {
    sol(m, n);
    if (ok == false) {
      cout << -1 << endl;
      return 0;
    }
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) cout << a[j][i] + 1 << " ";
      cout << endl;
    }
  }
  return 0;
}
