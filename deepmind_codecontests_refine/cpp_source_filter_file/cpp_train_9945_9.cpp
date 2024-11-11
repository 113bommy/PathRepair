#include <bits/stdc++.h>
using namespace std;
bool cmp(char a[2][2], char b[2][2]) {
  if (a[0][0] == b[0][0] && a[0][1] == b[0][1] && a[1][0] == b[1][0] &&
      a[1][1] == b[1][1])
    return true;
  else
    return false;
}
int main() {
  char a[2][2], b[2][2], ans[2][2];
  int k, i, j, x, y;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      cin >> a[i][j];
      ans[i][j] = a[i][j];
      if (a[i][j] == 'X') {
        x = i;
        y = j;
      }
    }
  }
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      cin >> b[i][j];
    }
  }
  char t;
  do {
    if (x == 0 && y == 0) {
      t = ans[0][0];
      ans[0][0] = ans[0][1];
      ans[0][0] = t;
      x = 0;
      y = 1;
      if (cmp(b, ans)) {
        cout << "YES";
        return 0;
      }
      continue;
    } else if (x == 0 && y == 1) {
      t = ans[0][1];
      ans[0][1] = ans[1][1];
      ans[1][1] = t;
      x = 1;
      y = 1;
      if (cmp(b, ans)) {
        cout << "YES";
        return 0;
      }
      continue;
    } else if (x == 1 && y == 1) {
      t = ans[1][1];
      ans[1][1] = ans[1][0];
      ans[1][0] = t;
      x = 1;
      y = 0;
      if (cmp(b, ans)) {
        cout << "YES";
        return 0;
      }
      continue;
    } else if (x == 1 && y == 0) {
      t = ans[1][0];
      ans[1][0] = ans[0][0];
      ans[0][0] = t;
      x = 0;
      y = 0;
      if (cmp(b, ans)) {
        cout << "YES";
        return 0;
      }
      continue;
    }
  } while (!cmp(a, ans));
  cout << "NO";
  return 0;
}
