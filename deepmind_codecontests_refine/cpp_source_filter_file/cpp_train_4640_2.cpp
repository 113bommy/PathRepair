#include <bits/stdc++.h>
using namespace std;
long long n, k, s, t, i, dg, gg, r, c, d;
long long benzinske[(int)1e6 + 3];
int provjeri(long long p) {
  int t1 = 0, z;
  for (i = 1; i < k + 2; i++) {
    z = benzinske[i] - benzinske[i - 1];
    if (z > p) {
      return 0;
    } else if (p >= z and p < 2 * z) {
      t1 = t1 + 2 * z - (p - z);
    } else {
      t1 = t1 + z;
    }
  }
  if (t1 > t) {
    return 0;
  } else {
    return 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> k;
  cin >> s;
  cin >> t;
  int niz1[n], niz2[n];
  for (i = 0; i < n; i++) {
    cin >> niz1[i];
    cin >> niz2[i];
  }
  benzinske[k + 1] = s;
  for (i = 1; i < k + 1; i++) {
    cin >> benzinske[i];
  }
  sort(benzinske, benzinske + k + 2);
  dg = 0;
  gg = 2 * s;
  while (dg != gg) {
    r = (dg + gg) / 2;
    if (provjeri(r) == 0) {
      dg = r + 1;
    } else {
      gg = r;
    }
  }
  if (provjeri(gg) == 0) {
    cout << -1 << endl;
  } else {
    c = 10000000;
    for (i = 0; i < n; i++) {
      if (niz2[i] >= gg and niz1[i] < c) {
        c = niz1[i];
      }
    }
    if (c == 10000000) {
      cout << -1 << endl;
    } else {
      cout << c << endl;
    }
  }
  return 0;
}
