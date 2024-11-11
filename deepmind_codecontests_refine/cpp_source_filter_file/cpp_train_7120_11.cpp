#include <bits/stdc++.h>
using namespace std;
char c[110][110];
int n;
bool vr() {
  for (int i = 0; i < n; i++) {
    bool flag = false;
    for (int j = 0; j < n; j++)
      if (c[i][j] == '.') flag = true;
    if (flag == false) return false;
  }
  return true;
}
bool vc() {
  for (int j = 0; j < n; j++) {
    bool flag = false;
    for (int i = 0; i < n; i++)
      if (c[i][j] == '.') flag = true;
    if (flag == false) return false;
  }
  return true;
}
bool candie(int rr, int cc) {
  for (int i = 0; i < n; i++)
    if (c[rr][i] == '.') return true;
  for (int i = 0; i < n; i++)
    if (c[i][cc] == '.') return true;
  return false;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> c[i];
  bool flag = true;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (c[i][j] == 'E' && candie(i, j) == false) flag = false;
  if (!flag) {
    cout << -1 << endl;
    return 0;
  }
  bool rowcan = vr();
  if (rowcan) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (c[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (c[i][j] == '.') {
          cout << i + 1 << " " << j + 1 << endl;
          break;
        }
      }
    }
  }
  return 0;
}
