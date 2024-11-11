#include <bits/stdc++.h>
using namespace std;
int n, m;
char cell[152][152];
int cnt_xod[152][152];
int cnt_W[152][152];
int main() {
  cin >> n >> m;
  int nuclear = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> cell[i][j];
      if (cell[i][j] == 'W') ++nuclear;
      cnt_W[i][j] = 0;
      cnt_xod[i][j] = 1000000000;
    }
  }
  if (nuclear == 0) {
    cout << 0;
    return 0;
  }
  cnt_W[1][1] = 0;
  cnt_xod[1][1] = 0;
  int a = 1;
  int b = m + 1;
  int c = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = a; j != b; j += c) {
      if (i < n) {
        cnt_xod[i + 1][j] = cnt_xod[i][j] + 1;
        cnt_W[i + 1][j] = cnt_W[i][j] + (cell[i + 1][j] == 'W');
      }
      if (c > 0 && j == m) continue;
      if (c < 0 && j == 1) continue;
      if ((cnt_W[i][j + c] < cnt_W[i][j] + (cell[i][j + c] == 'W')) ||
          ((cnt_W[i][j + c] == cnt_W[i][j] + (cell[i][j + c] == 'W')) &&
           cnt_xod[i][j + c] > cnt_xod[i][j] + 1)) {
        cnt_W[i][j + c] = cnt_W[i][j] + (cell[i][j + c] == 'W');
        cnt_xod[i][j + c] = cnt_xod[i][j] + 1;
      }
    }
    if (c > 0) {
      c = -1;
      a = m;
      b = 0;
    } else {
      c = 1;
      a = 1;
      b = m + 1;
    }
  }
  int rez_xod = 1000000000;
  int rez_W = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if ((cnt_W[i][j] > rez_W) ||
          (cnt_W[i][j] == rez_W && cnt_xod[i][j] < rez_xod)) {
        rez_W = cnt_W[i][j];
        rez_xod = cnt_xod[i][j];
      }
    }
  }
  cout << rez_xod;
  return 0;
}
