#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[n][2];
  int sx[n][m];
  int b[m][2];
  int i, j, first, w = 0, h = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      cin >> first;
      if (first == 0)
        w++;
      else
        h++;
      sx[i][j] = first;
    }
    a[i][0] = w;
    a[i][1] = h;
    w = 0;
    h = 0;
  }
  w = 0;
  h = 0;
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      first = sx[j][i];
      if (first == 0)
        w++;
      else
        h++;
    }
    b[i][0] = w;
    b[i][1] = h;
    w = 0;
    h = 0;
  }
  long long s = 0, p, q, c = 0, ms = 1;
  for (i = 0; i < n; i++) {
    ms = 1;
    p = a[i][0];
    q = a[i][1];
    c = (ms << p);
    c--;
    s += c;
    ms = 1;
    c = 0;
    c = (ms << q);
    c--;
    s += c;
  }
  for (i = 0; i < m; i++) {
    c = 0;
    p = b[i][0];
    q = b[i][1];
    ms = 1;
    if (p != 0) {
      c = (ms << p);
      c = c - m - 1;
    }
    s += c;
    ms = 1;
    c = 0;
    if (q != 0) {
      c = (ms << q);
      c = c - m - 1;
    }
    s += c;
  }
  cout << s;
  return 0;
}
