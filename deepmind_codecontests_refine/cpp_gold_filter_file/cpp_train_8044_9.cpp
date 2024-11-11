#include <bits/stdc++.h>
using namespace std;
char tab[11][11], res[11][11];
int answer, n, m;
bool valid(int x, int y) {
  return x >= 0 && x < n && y >= 0 && y < m && tab[x][y] == '.';
}
int p1x[] = {0, 0, 1, 2};
int p1y[] = {1, 2, 1, 1};
int p2x[] = {1, 2, 1, 1};
int p2y[] = {0, 0, -1, -2};
int p3x[] = {1, 2, 2, 2};
int p3y[] = {0, 0, 1, -1};
int p4x[] = {1, 1, 1, 2};
int p4y[] = {0, 1, 2, 0};
void solve(int x, int y, int cant) {
  if ((m * (n - x - 1) + m - y) / 6 + cant <= answer) return;
  if (x == n) {
    if (cant > answer) {
      answer = cant;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) res[i][j] = tab[i][j];
    }
  } else if (y == m)
    solve(x + 1, 0, cant);
  else if (tab[x][y] != '.') {
    solve(x, y + 1, cant);
  } else {
    solve(x, y + 1, cant);
    bool ok = 1;
    for (int k = 0; k < 4; ++k)
      if (!valid(x + p1x[k], y + p1y[k])) {
        ok = 0;
        break;
      }
    if (ok) {
      tab[x][y] = cant + 'A';
      for (int k = 0; k < 4; ++k) tab[x + p1x[k]][y + p1y[k]] = cant + 'A';
      solve(x, y + 1, cant + 1);
      for (int k = 0; k < 4; ++k) tab[x + p1x[k]][y + p1y[k]] = '.';
      tab[x][y] = '.';
    }
    ok = 1;
    for (int k = 0; k < 4; ++k)
      if (!valid(x + p2x[k], y + p2y[k])) {
        ok = 0;
        break;
      }
    if (ok) {
      tab[x][y] = cant + 'A';
      for (int k = 0; k < 4; ++k) tab[x + p2x[k]][y + p2y[k]] = cant + 'A';
      solve(x, y + 1, cant + 1);
      for (int k = 0; k < 4; ++k) tab[x + p2x[k]][y + p2y[k]] = '.';
      tab[x][y] = '.';
    }
    ok = 1;
    for (int k = 0; k < 4; ++k)
      if (!valid(x + p3x[k], y + p3y[k])) {
        ok = 0;
        break;
      }
    if (ok) {
      tab[x][y] = cant + 'A';
      for (int k = 0; k < 4; ++k) tab[x + p3x[k]][y + p3y[k]] = cant + 'A';
      solve(x, y + 1, cant + 1);
      for (int k = 0; k < 4; ++k) tab[x + p3x[k]][y + p3y[k]] = '.';
      tab[x][y] = '.';
    }
    ok = 1;
    for (int k = 0; k < 4; ++k)
      if (!valid(x + p4x[k], y + p4y[k])) {
        ok = 0;
        break;
      }
    if (ok) {
      tab[x][y] = cant + 'A';
      for (int k = 0; k < 4; ++k) tab[x + p4x[k]][y + p4y[k]] = cant + 'A';
      solve(x, y + 1, cant + 1);
      for (int k = 0; k < 4; ++k) tab[x + p4x[k]][y + p4y[k]] = '.';
      tab[x][y] = '.';
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) tab[i][j] = res[i][j] = '.';
  solve(0, 0, 0);
  cout << answer << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) printf("%c", res[i][j]);
    printf("\n");
  }
  return 0;
}
