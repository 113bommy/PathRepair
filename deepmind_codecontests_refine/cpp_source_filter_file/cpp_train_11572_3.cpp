#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, j, k, sum, q, x, z, p, y, e, n, m, kmax, maxi, t, mini, v, x1,
      x2, y1, y2, g, kol, w;
  cin >> n;
  string l, r;
  cin >> l;
  cin >> r;
  vector<long long> b[27], a[27];
  for (i = 0; i < n; i++) {
    if (l[i] == '?') {
      a[26].push_back(i + 1);
    } else {
      x = l[i] - 97;
      a[x].push_back(i + 1);
    }
  }
  for (i = 0; i < n; i++) {
    if (r[i] == '?') {
      b[26].push_back(i + 1);
    } else {
      x = r[i] - 97;
      b[x].push_back(i + 1);
    }
  }
  kol = 0;
  q = a[26].size();
  w = b[26].size();
  for (i = 0; i < 26; i++) {
    kol = kol + min(a[i].size(), b[i].size());
    if (a[i].size() > b[i].size()) {
      x = a[i].size() - b[i].size();
      kol = kol + min(x, w);
      t = 0;
      w = max(t, w - x);
    } else {
      if (b[i].size() > a[i].size()) {
        x = b[i].size() - a[i].size();
        kol = kol + min(x, q);
        t = 0;
        q = max(t, q - x);
      }
    }
  }
  kol = kol + min(q, w);
  cout << kol << endl;
  q = a[26].size();
  w = b[26].size();
  for (i = 0; i < 26; i++) {
    kol = kol + min(a[i].size(), b[i].size());
    z = min(a[i].size(), b[i].size());
    for (j = 0; j < z; j++) {
      cout << a[i][j] << " " << b[i][j] << endl;
    }
  }
  i = 0;
  z = 0;
  while (z != q and i < 26) {
    if (b[i].size() > a[i].size()) {
      x = b[i].size() - a[i].size();
      p = a[i].size();
      y = min(q - z, x);
      for (j = 0; j < y; j++) {
        cout << a[26][z + j] << " " << b[i][p + j] << endl;
      }
      z = z + y;
    }
    i++;
  }
  x1 = z;
  i = 0;
  z = 0;
  while (z != w and i < 26) {
    if (a[i].size() > b[i].size()) {
      x = a[i].size() - b[i].size();
      p = b[i].size();
      y = min(q - z, x);
      for (j = 0; j < y; j++) {
        cout << a[i][p + j] << " " << b[26][z + j] << endl;
      }
      z = z + y;
    }
    i++;
  }
  x2 = z;
  while (x1 < q and x2 < w) {
    cout << a[26][x1] << " " << b[26][x2] << endl;
    x1++;
    x2++;
  }
  return 0;
}
