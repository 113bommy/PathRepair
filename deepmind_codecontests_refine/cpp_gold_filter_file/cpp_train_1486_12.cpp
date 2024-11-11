#include <bits/stdc++.h>
using namespace std;
int n, m;
int getmin(char x, char y, char z, char i, string s) {
  int c = 0, d = 0;
  if (s == "ee") {
    if (x == '1')
      c++;
    else
      d++;
    if (y == '1')
      c++;
    else
      d++;
    if (z == '1')
      c++;
    else
      d++;
    return min(c, d);
  }
  if (s == "oo") {
    if (x == '0')
      c++;
    else
      d++;
    if (y == '1')
      c++;
    else
      d++;
    if (z == '0')
      c++;
    else
      d++;
    return min(c, d);
  }
  if (s == "eo") {
    if (x == '0')
      c++;
    else
      d++;
    if (y == '0')
      c++;
    else
      d++;
    if (z == '1')
      c++;
    else
      d++;
    return min(c, d);
  }
  if (s == "oe") {
    if (x == '1')
      c++;
    else
      d++;
    if (y == '0')
      c++;
    else
      d++;
    if (z == '0')
      c++;
    else
      d++;
    return min(c, d);
  }
}
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  char a[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  if (min(m, n) > 3)
    cout << -1 << endl;
  else if (min(n, m) == 1)
    cout << 0 << endl;
  else {
    if (min(n, m) == 2) {
      int c = 0, d = 0;
      for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
          if ((a[0][i] == '0' && a[1][i] == '0') ||
              (a[0][i] == '1' && a[1][i] == '1'))
            c++;
        } else {
          if ((a[0][i] == '0' && a[1][i] == '1') ||
              (a[0][i] == '1' && a[1][i] == '0'))
            c++;
        }
      }
      for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
          if ((a[0][i] == '0' && a[1][i] == '1') ||
              (a[0][i] == '1' && a[1][i] == '0'))
            d++;
        } else {
          if ((a[0][i] == '0' && a[1][i] == '0') ||
              (a[0][i] == '1' && a[1][i] == '1'))
            d++;
        }
      }
      cout << min(c, d) << endl;
    } else {
      int v = 0, x = 0, y = 0, z = 0;
      for (int i = 0; i < m; i++) {
        if (i % 2 == 0)
          v += getmin(a[0][i], a[1][i], a[2][i], i, "ee");
        else
          v += getmin(a[0][i], a[1][i], a[2][i], i, "oo");
      }
      for (int i = 0; i < m; i++) {
        if (i % 2 != 0)
          x += getmin(a[0][i], a[1][i], a[2][i], i, "ee");
        else
          x += getmin(a[0][i], a[1][i], a[2][i], i, "oo");
      }
      for (int i = 0; i < m; i++) {
        if (i % 2 == 0)
          y += getmin(a[0][i], a[1][i], a[2][i], i, "eo");
        else
          y += getmin(a[0][i], a[1][i], a[2][i], i, "oe");
      }
      for (int i = 0; i < m; i++) {
        if (i % 2 != 0)
          z += getmin(a[0][i], a[1][i], a[2][i], i, "eo");
        else
          z += getmin(a[0][i], a[1][i], a[2][i], i, "oe");
      }
      cout << min(v, (min(x, (min(y, z))))) << endl;
    }
  }
}
