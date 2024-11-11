#include <bits/stdc++.h>
using namespace std;
long long x, y, z, a[125][10], c[10];
long long rec(long long s, long long ss, long long n) {
  long long indx = 0;
  if (s * 2 > ss) {
    indx = 1;
  } else if (s * 4 > ss) {
    indx = 2;
  } else if (s * 8 > ss) {
    indx = 3;
  } else if (s * 16 > ss) {
    indx = 4;
  } else if (s * 32 > ss) {
    indx = 5;
  } else {
    indx = 6;
  }
  if (a[0][n] >= 0) {
    if (a[1][n] >= 0) {
      return (indx * (500 - 2 * a[0][n])) - (indx * (500 - 2 * a[1][n]));
    } else {
      return (indx * (500 - 2 * a[0][n]));
    }
  } else {
    if (a[1][n] >= 0) {
      return -(indx * (500 - 2 * a[1][n]));
    }
  }
  return 0;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  cin >> x;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> a[i][j];
      c[j] += (a[i][j] >= 0 ? 1 : 0);
    }
  }
  for (int i = 1; i <= x * 32; i++) {
    z = 0;
    for (int j = 0; j < 5; j++) {
      if (a[0][j] >= 0) {
        z += max(rec(c[j], i + x, j), rec(c[j] + i, i + x, j));
      } else {
        z += rec(c[j], i + x, j);
      }
    }
    if (z > 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
