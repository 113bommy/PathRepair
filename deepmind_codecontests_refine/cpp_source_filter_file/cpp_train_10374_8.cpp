#include <bits/stdc++.h>
using namespace std;
int size, a[1000100][2], i, j, n, x, res, k;
void init(int sz) {
  int i;
  size = 1;
  while (size < sz) size *= 2;
  for (i = 1; i < size * 2; ++i) a[i][0] = 2e9;
}
void upd(int i, int val) {
  i += size;
  a[i][0] = val;
  a[i][1] = i;
  i >>= 1;
  while (i) {
    if (a[2 * i][0] < a[2 * i + 1][0]) {
      a[i][0] = a[2 * i][0];
      a[i][1] = a[2 * i][1];
    } else {
      a[i][0] = a[2 * i + 1][0];
      a[i][1] = a[2 * i + 1][1];
    }
    i >>= 1;
  }
}
int poiskmin(int i, int j) {
  i += size;
  j += size;
  int res = 2e9, ri;
  while (i <= j) {
    if (i & 1) {
      if (res > a[i][0]) {
        res = a[i][0];
        ri = a[i][1];
      }
      ++i;
    }
    if (!(j & 1)) {
      if (res > a[j][0]) {
        res = a[j][0];
        ri = a[j][1];
      }
      j--;
    }
    i >>= 1;
    j >>= 1;
  }
  return ri;
}
int main() {
  cin >> n;
  init(n);
  for (i = 0; i < n; ++i) {
    cin >> x;
    upd(i, x);
  }
  for (i = 0; i < n; ++i) {
    x = poiskmin(i, n - 1);
    if (a[x][0] >= a[i + size][0])
      cout << -1 << ' ';
    else {
      res = x - i - size - 1;
      k = x - size;
      while (k < n - 1) {
        x = poiskmin(k, n - 1);
        if (a[x][0] >= a[i + size][0])
          break;
        else {
          res = x - i - size - 1;
          k = x - size + 1;
        }
      }
      if (a[n - 1 + size][0] < a[i + size][0])
        cout << n - i - 2;
      else
        cout << res << ' ';
    }
  }
  return 0;
}
