#include <bits/stdc++.h>
using namespace std;
long double pi = 3.1415926535897932384626433832795;
int r[1005], c[1005];
int main() {
  int n, m;
  cin >> n >> m;
  char k[n + 5][m + 5];
  int a = 0, b = 0, x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    int u = 0;
    for (int j = 0; j < m; j++) {
      cin >> k[i][j];
      if (k[i][j] == '*') u++;
    }
    if (a < u) a = u, x = i;
  }
  for (int j = 0; j < m; j++) {
    int u = 0;
    for (int i = 0; i < n; i++)
      if (k[i][j] == '*') u++;
    if (b < u) b = u, y = j;
  }
  if (a > b) {
    for (int i = 0; i < m; i++) k[x][i] = '.';
    int p = 0, h = 0;
    for (int j = 0; j < m; j++) {
      int u = 0;
      for (int i = 0; i < n; i++) {
        if (k[i][j] == '*') u++, p = j;
      }
      if (u) h++;
    }
    if (h <= 1)
      cout << "YES\n" << x + 1 << " " << p + 1 << "\n";
    else
      cout << "NO\n";
  } else {
    for (int i = 0; i < n; i++) k[i][y] = '.';
    int p = 0, h = 0;
    for (int i = 0; i < n; i++) {
      int u = 0;
      for (int j = 0; j < m; j++) {
        if (k[i][j] == '*') u++, p = i;
      }
      if (u) h++;
    }
    if (h <= 1)
      cout << "YES\n" << p + 1 << " " << y + 1 << "\n";
    else
      cout << "NO\n";
  }
  return 0;
}
