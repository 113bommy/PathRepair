#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int a[4][4] = {0};
  int i, j, k = -1;
  while (++k < (int)(s).size()) {
    if (s[k] == '0') {
      j = -1;
      while (++j < 4) {
        i = -1;
        while (++i < 3)
          if (a[i][j] == 0 && a[i + 1][j] == 0) {
            a[i][j] = 1, a[i + 1][j] = 1;
            break;
          }
        if (i != 4) break;
      }
      cout << i + 1 << " " << j + 1 << endl;
    } else {
      i = -1;
      while (++i < 4) {
        j = -1;
        while (++j < 3)
          if (a[i][j] == 0 && a[i][j + 1] == 0) {
            a[i][j] = 1, a[i][j + 1] = 1;
            break;
          }
        if (j != 4) break;
      }
      cout << i + 1 << " " << j + 1 << endl;
    }
    i = -1;
    int ct;
    while (++i < 4) {
      j = -1;
      ct = 0;
      while (++j < 4)
        if (a[i][j] == 1) ct++;
      if (ct == 4) {
        j = -1;
        while (++j < 4) a[i][j] = 0;
      }
    }
    j = -1;
    while (++j < 4) {
      i = -1;
      ct = 0;
      while (++i < 4)
        if (a[i][j] == 1) ct++;
      if (ct == 4) {
        i = -1;
        while (++i < 4) a[i][j] = 0;
      }
    }
  }
}
