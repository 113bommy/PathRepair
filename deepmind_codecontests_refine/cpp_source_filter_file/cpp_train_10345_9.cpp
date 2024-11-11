#include <bits/stdc++.h>
using namespace std;
void printM(vector<vector<char> > &M, int x, int y) {
  int n = M.size();
  int m = M[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m - 1; j++) {
      if (i == x && j == y)
        cout << "@";
      else
        cout << M[i][j];
    }
    cout << endl;
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char> > M(n, vector<char>(m + 2, '#'));
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> M[i][j];
    }
  }
  unsigned long cont = 0;
  int x = 0;
  int y = 1;
  int dir = 1;
  int shortcut = 0;
  bool trapped = false;
  while (x < n - 1 && !trapped) {
    if (M[x + 1][y] == '.') {
      x++;
      shortcut = 0;
    } else if (M[x][y + dir] == '.') {
      y += dir;
      shortcut++;
    } else if (M[x][y + dir] == '+') {
      M[x][y + dir] = '.';
      dir = -dir;
      y += shortcut * dir;
      cont += shortcut;
      shortcut++;
    } else if (M[x][y + dir] == '#') {
      dir = -dir;
      y += shortcut * dir;
      if (M[x][y + dir] == '#' && M[x + 1][y] != '.') trapped = true;
      cont += shortcut;
    }
    cont++;
  }
  if (trapped)
    cout << "Never" << endl;
  else
    cout << cont << endl;
}
