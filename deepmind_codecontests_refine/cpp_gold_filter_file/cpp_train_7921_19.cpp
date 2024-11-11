#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long table[5][5];
long long onedt[6] = {0, 1, 2, 3, 2, 1};
signed main() {
  cin >> n >> m;
  if (n < m) {
    swap(n, m);
  }
  table[1][1] = 0;
  table[1][2] = 0;
  table[1][3] = 0;
  table[1][4] = 2;
  table[2][2] = 0;
  table[2][3] = 4;
  table[2][4] = 8;
  table[3][3] = 8;
  table[3][4] = 12;
  table[4][4] = 16;
  if (m < 5) {
    if (n < 5) {
      cout << table[m][n] << '\n';
    } else {
      if (m == 1) {
        cout << n - onedt[n % 6] << '\n';
      } else if (m == 2) {
        if (n >= 20 || (n != 6 && n != 7)) {
          cout << 2 * n << '\n';
        } else {
          cout << 2 * n - 2 * (n & 1) << '\n';
        }
      } else if (m == 4) {
        cout << 4 * n - 2 * (n & 1) << '\n';
      } else {
        if (!(n & 1)) {
          cout << n * m << '\n';
        } else {
          cout << n * m - 1 << '\n';
        }
      }
    }
  } else {
    cout << m * n - (m & n & 1) << '\n';
  }
}
