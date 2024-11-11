#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n;
  long long int x0, y0, x, y;
  cin >> n;
  cin >> x0 >> y0;
  long long int a[10][2];
  memset(a, 0, sizeof(a));
  char c[10];
  char ch;
  a[1][0] = a[8][0] = a[7][0] = a[7][1] = a[6][1] = a[5][1] = INT_MIN;
  a[1][1] = a[2][1] = a[3][1] = a[3][0] = a[4][0] = a[5][0] = INT_MAX;
  a[2][0] = a[6][0] = x0;
  a[4][1] = a[8][1] = y0;
  while (n--) {
    cin >> ch >> x >> y;
    if ((x0 - y0) == (x - y)) {
      if (x > x0 and y > y0) {
        if (x < a[3][0] and y < a[3][1]) {
          a[3][0] = x, a[3][1] = y;
          c[3] = ch;
        }
      }
      if (x < x0 and y < y0) {
        if (x > a[7][0] and y > a[7][1]) {
          a[7][0] = x, a[7][1] = y;
          c[7] = ch;
        }
      }
    } else if (x0 + y0 == x + y) {
      if (x > x0 and y < y0) {
        if (x < a[5][0] and y > a[5][1]) {
          a[5][0] = x, a[5][1] = y;
          c[5] = ch;
        }
      }
      if (x < x0 and y > y0) {
        if (x > a[1][0] and y < a[1][1]) {
          a[1][0] = x, a[1][1] = y;
          c[1] = ch;
        }
      }
    } else if (x0 == x) {
      if (y > y0) {
        if (y < a[2][1]) {
          a[2][0] = x, a[2][1] = y;
          c[2] = ch;
        }
      }
      if (y < y0) {
        if (y > a[6][1]) {
          a[6][0] = x, a[6][1] = y;
          c[6] = ch;
        }
      }
    } else if (y == y0) {
      if (x > x0) {
        if (x < a[4][0]) {
          a[4][0] = x, a[4][1] = y;
          c[4] = ch;
        }
      }
      if (x < x0) {
        if (x > a[8][0]) {
          a[8][0] = x, a[8][1] = y;
          c[8] = ch;
        }
      }
    }
  }
  if (c[1] == 'B' or c[3] == 'B' or c[5] == 'B' or c[7] == 'B') {
    cout << "YES" << endl;
    return 0;
  }
  if (c[2] == 'R' or c[4] == 'R' or c[6] == 'R' or c[8] == 'R') {
    cout << "YES" << endl;
    return 0;
  }
  if (c[1] == 'Q' or c[3] == 'Q' or c[5] == 'Q' or c[7] == 'Q' or c[2] == 'Q' or
      c[4] == 'Q' or c[6] == 'Q' or c[8] == 'Q') {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
  return 0;
}
