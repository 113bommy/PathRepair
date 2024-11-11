#include <bits/stdc++.h>
using namespace std;
int n, m;
int a, b, c;
char grid[110][110];
int main(int argc, char** argv) {
  cin >> n >> m >> a >> b >> c;
  if (n * m % 2 == 1) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  } else {
    if (n % 2 == 1) {
      if (a * 2 < m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      } else
        a -= m / 2;
    } else if (m % 2 == 1) {
      if (b * 2 < n) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
      } else
        b -= n / 2;
    }
  }
  if ((a / 2) + (b / 2) + c < (m / 2) * (n / 2)) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  bool set1 = true;
  char curChar = 'a';
  memset(grid, 0, sizeof(grid));
  for (int i = 0; i < n; i += 2)
    if (i + 1 < n) {
      if ((i / 2) % 2)
        set1 = false;
      else
        set1 = true;
      for (int j = 0; j < m; j += 2)
        if (j + 1 < m) {
          if (a > 0) {
            if (set1)
              curChar = 'a';
            else
              curChar = 'c';
            grid[i][j] = grid[i][j + 1] = curChar;
            if (set1)
              curChar = 'b';
            else
              curChar = 'd';
            grid[i + 1][j] = grid[i + 1][j + 1] = curChar;
            a -= 2;
          } else if (b > 0) {
            if (set1)
              curChar = 'a';
            else
              curChar = 'c';
            grid[i][j] = grid[i + 1][j] = curChar;
            if (set1)
              curChar = 'b';
            else
              curChar = 'd';
            grid[i + 1][j + 1] = grid[i][j + 1] = curChar;
            b -= 2;
          } else {
            if (set1)
              curChar = 'a';
            else
              curChar = 'c';
            grid[i][j] = grid[i + 1][j] = curChar;
            grid[i + 1][j + 1] = grid[i][j + 1] = curChar;
            c--;
          }
          set1 = !set1;
        }
    }
  if (n % 2) {
    if (grid[n - 2][0] == 'c' || grid[n - 2][0] == 'd')
      set1 = true;
    else
      set1 = false;
    for (int j = 0; j < m; j += 2) {
      if (set1)
        curChar = 'a';
      else
        curChar = 'c';
      grid[n - 1][j] = grid[n - 1][j + 1] = curChar;
      set1 = !set1;
    }
  } else if (m % 2) {
    if (grid[0][m - 2] == 'c' || grid[0][m - 2] == 'd')
      set1 = true;
    else
      set1 = false;
    for (int i = 0; i < n; i += 2) {
      if (set1)
        curChar = 'a';
      else
        curChar = 'c';
      grid[i][m - 1] = grid[i + 1][m - 1] = curChar;
      set1 = !set1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << grid[i][j];
    cout << endl;
  }
  return 0;
}
