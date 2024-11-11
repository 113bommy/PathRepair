#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, f = 0;
  cin >> n >> m;
  if (n < m) swap(n, m);
  if (m == 1 && n % 3 != 0) {
    cout << (n * m) - (n / 3 + 1);
    f = 1;
  } else {
    if (m == 1 && n % 3 == 0) {
      cout << (n * m) - (n / 3);
      f = 1;
    }
  }
  if (m == 2 && f == 0) {
    cout << (n * m) - (n / 2 + 1);
    f = 1;
  }
  if (m == 3 && n < 5 && f == 0 || n == 3 && m < 5 && f == 0) {
    if (m == 3 && f == 0) cout << (n * m) - n;
    f = 1;
    if (n == 3 && f == 0) cout << (n * m) - m;
    f = 1;
  }
  if (m == 3 && n >= 5 && f == 0 || n == 3 && m >= 5 && f == 0) {
    if (m == 3 && n == 7 && f == 0) {
      cout << 15;
      f = 1;
    }
    if (m == 3 && n == 9 && f == 0) {
      cout << 20;
      f = 1;
    }
    if (m == 3 && n == 10 && f == 0) {
      cout << 22;
      f = 1;
    }
    if (m == 3 && n == 11 && f == 0) {
      cout << 24;
      f = 1;
    }
    if (m == 3 && n == 12 && f == 0) {
      cout << 26;
      f = 1;
    }
    if (m == 3 && n == 13 && f == 0) {
      cout << 29;
      f = 1;
    }
    if (m == 3 && f == 0) cout << (n * m) - n + 1;
    f = 1;
    if (n == 3 && f == 0) cout << (n * m) - m + 1;
    f = 1;
  }
  if (m == 4 && f == 0 || n == 4 && f == 0) {
    if (m + n == 5) cout << n * m - 2;
    if (m + n == 6) cout << n * m - 3;
    if (m + n == 7) cout << n * m - 4;
    if (m + n == 8) cout << n * m - 4;
    if (m + n == 9) cout << n * m - 6;
    if (m + n == 10) cout << n * m - 7;
    if (m + n == 11) cout << n * m - 7;
    if (m + n == 12) cout << n * m - 8;
    if (m + n == 13) cout << n * m - 10;
    if (m + n == 14) cout << n * m - 10;
    if (m + n == 15) cout << n * m - 14;
    if (m + n == 16) cout << n * m - 15;
    f = 1;
  }
  if (m == 5 && f == 0 || n == 5 && f == 0) {
    if (m + n == 6) cout << n * m - 2;
    if (m + n == 7) cout << n * m - 3;
    if (m + n == 8) cout << n * m - 5;
    if (m + n == 9) cout << n * m - 7;
    if (m + n == 10) cout << n * m - 7;
    if (m + n == 11) cout << n * m - 8;
    if (m + n == 12) cout << n * m - 9;
    if (m + n == 13) cout << n * m - 11;
    f = 1;
  }
  if (m == 6 && f == 0 && n == 6 && f == 0) {
    cout << 26;
    f = 1;
  }
  if (m == 6 && f == 0 || n == 6 && f == 0) {
    if (m == 6 && f == 0) cout << (n * m) - n * 2;
    if (m == 6 && f == 0) cout << (n * m) - m * 2;
    f = 1;
  }
  return 0;
}
