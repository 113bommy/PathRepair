#include <bits/stdc++.h>
using namespace std;
int T, r, c;
bool m[61][61];
int main() {
  ios::sync_with_stdio(false);
  char cg;
  cin >> T;
  while (T--) {
    memset(m, false, sizeof(m));
    bool flag = false;
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++) {
        cin >> cg;
        if (cg == 'A') {
          m[i][j] = true;
          flag = true;
        }
      }
    if (!flag) {
      cout << "MORTAL" << endl;
      continue;
    }
    flag = true;
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= c; j++)
        if (!m[i][j]) flag = false;
    if (flag) {
      cout << "0" << endl;
      continue;
    }
    flag = true;
    for (int i = 1; i <= r; i++)
      if (!m[i][1]) flag = false;
    if (flag) {
      cout << "1" << endl;
      continue;
    }
    flag = true;
    for (int i = 1; i <= r; i++)
      if (!m[i][c]) flag = false;
    if (flag) {
      cout << "1" << endl;
      continue;
    }
    flag = true;
    for (int i = 1; i <= c; i++)
      if (!m[1][i]) flag = false;
    if (flag) {
      cout << "1" << endl;
      continue;
    }
    flag = true;
    for (int i = 1; i <= c; i++)
      if (!m[1][i]) flag = false;
    if (flag) {
      cout << "1" << endl;
      continue;
    }
    if (m[1][1] || m[1][c] || m[r][1] || m[r][c]) {
      cout << "2" << endl;
      continue;
    }
    for (int i = 1; i <= r; i++) {
      flag = true;
      for (int j = 1; j <= c; j++)
        if (!m[i][j]) flag = false;
      if (flag) break;
    }
    if (flag) {
      cout << "2" << endl;
      continue;
    }
    for (int i = 1; i <= c; i++) {
      flag = true;
      for (int j = 1; j <= r; j++)
        if (!m[j][i]) flag = false;
      if (flag) break;
    }
    if (flag) {
      cout << "2" << endl;
      continue;
    }
    flag = false;
    for (int i = 1; i <= r; i++)
      if (m[i][1] || m[i][c]) {
        flag = true;
        break;
      }
    if (flag) {
      cout << "3" << endl;
      continue;
    }
    flag = false;
    for (int i = 1; i <= c; i++)
      if (m[1][i] || m[r][i]) {
        flag = true;
        break;
      }
    if (flag) {
      cout << "3" << endl;
      continue;
    }
    cout << 4 << endl;
  }
  return 0;
}
