#include <bits/stdc++.h>
using namespace std;
const int maxN = 10;
int a[maxN][maxN];
bool ok(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
  if (a[x1][y1] == a[x2][y2] && a[x2][y2] == a[x3][y3] && a[x1][y1] == color)
    return true;
  return false;
}
bool win(int color) {
  for (int i = 0; i < 3; ++i) {
    if (ok(i, 0, i, 1, i, 2, color)) return true;
    if (ok(0, i, 1, i, 2, i, color)) return true;
  }
  if (ok(0, 0, 1, 1, 2, 2, color)) return true;
  if (ok(0, 2, 1, 1, 2, 0, color)) return true;
  return false;
}
int main() {
  for (int i = 0; i < 3; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 3; ++j) {
      if (s[j] == '.')
        a[i][j] = 0;
      else if (s[j] == 'X')
        a[i][j] = 1;
      else
        a[i][j] = 2;
    }
  }
  int cntX = 0, cntO = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i][j] == 1)
        ++cntX;
      else if (a[i][j] == 2)
        ++cntO;
    }
  }
  if (cntX < cntO || cntX > cntO + 1) {
    cout << "illegal" << endl;
    return 0;
  }
  int cnt = (cntX + cntO);
  if (cnt % 2 == 0)
    cnt = 2;
  else
    cnt = 1;
  if (win(3 - cnt)) {
    cout << "illegal" << endl;
    return 0;
  }
  if (!win(cnt) && !win(3 - cnt) && (cntX + cntO == 9)) {
    cout << "draw" << endl;
    return 0;
  }
  if (!win(cnt)) {
    if (cnt == 1)
      cout << "second" << endl;
    else
      cout << "first" << endl;
    return 0;
  }
  if (cnt == 1)
    cout << "the first player won" << endl;
  else
    cout << "the second player won" << endl;
  return 0;
}
