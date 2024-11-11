#include <bits/stdc++.h>
using namespace std;
void op(int t) { cout << "Case #" << t << ": "; }
int main() {
  int n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  int dx[] = {0, -1, 0, 1};
  int dy[] = {-1, 0, 1, 0};
  for (int i = (0); i < (n + 1); i++)
    for (int j = (0); j < (m + 1); j++) a[i][j] = '&';
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++) {
      cin >> a[i][j];
    }
  int x = 0;
  for (int i = (0); i < (n); i++) {
    int y = x;
    for (int j = (0); j < (m); j++) {
      if (a[i][j] == '.' && a[i][j + 1] == '.') {
        a[i][j] = a[i][j + 1] = '0' + y;
        y = (y + 1) % 3;
      }
      if (i > 0) {
        if (a[i][j] == '.' && a[i - 1][j] == '.') {
          a[i][j] = a[i - 1][j] = '0' + y;
          y = (y + 1) % 3;
        }
      }
    }
    x = (x + 3) % 9;
  }
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++)
      if (a[i][j] == '.') {
        for (int k = (0); k < (4); k++) {
          int xx = i + dx[k], yy = j + dy[k];
          if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] != '#')
            a[i][j] = a[xx][yy];
        }
      }
  bool ok = 1;
  for (int i = (0); i < (n); i++)
    for (int j = (0); j < (m); j++)
      if (a[i][j] == '.') ok = 0;
  if (ok) {
    for (int i = (0); i < (n); i++) {
      for (int j = (0); j < (m); j++) cout << a[i][j];
      cout << "\n";
    }
  } else
    cout << "-1\n";
  return 0;
}
