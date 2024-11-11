#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using ui = unsigned int;
const ll infll = (ll)(1e18) + 10;
const int inf = int(1e9) + 10;
const int maxn = int(1e6) + 10;
int a[6][8];
char f[6][8];
int mx = 0;
int x = -1, y = -1;
int main() {
  a[0][0] = a[0][1] = a[0][6] = a[0][7] = 3;
  a[1][0] = a[1][1] = a[1][6] = a[1][7] = 3;
  a[2][0] = a[2][1] = a[2][6] = a[2][7] = 2;
  a[3][0] = a[3][1] = a[3][6] = a[3][7] = 2;
  a[4][0] = a[4][1] = a[4][6] = a[4][7] = 1;
  a[5][0] = a[5][1] = a[5][6] = a[5][7] = 1;
  a[0][4] = a[0][5] = 4;
  a[1][4] = a[1][5] = 4;
  a[2][4] = a[2][5] = 3;
  a[3][4] = a[3][5] = 3;
  a[4][4] = a[4][5] = 2;
  a[5][4] = a[5][5] = 2;
  for (int i = 0; i < (int)(6); i++) {
    for (int j = 0; j < (int)(8); j++) {
      cin >> f[i][j];
      if (f[i][j] == '.') {
        if (a[i][j] > mx) {
          mx = a[i][j];
          x = i;
          y = j;
        }
      }
    }
  }
  f[x][y] = 'P';
  for (int i = 0; i < (int)(6); i++) {
    for (int j = 0; j < (int)(8); j++) cout << f[i][j];
    cout << "\n";
  }
  return 0;
}
