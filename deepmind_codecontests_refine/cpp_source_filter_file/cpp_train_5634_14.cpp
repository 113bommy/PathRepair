#include <bits/stdc++.h>
using namespace std;
int a[1003][1003];
int main() {
  int n, m;
  cin >> n >> m;
  int c = 0;
  int x, y;
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ch;
      if (ch == '.')
        a[i][j] = 0;
      else
        a[i][j] = 1;
    }
  }
  int dx[] = {0, 0, 1, -1, -1, 1, -1, 1};
  int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
  int f = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      c = 0;
      for (int k = 0; k < 8; k++) {
        x = i + dx[k];
        y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && a[i][j] != 0) c++;
      }
      if (c == 8) {
        for (int k = 0; k < 8; k++) {
          x = i + dx[k];
          y = j + dy[k];
          a[x][y] = 2;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 1) {
        f = 1;
        break;
      }
    }
  }
  if (f == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
