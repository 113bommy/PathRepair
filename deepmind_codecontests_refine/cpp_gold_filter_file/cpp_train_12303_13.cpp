#include <bits/stdc++.h>
using namespace std;
pair<int, int> check(const vector<vector<int> > &a, int i1, int j1, int i2,
                     int j2) {
  pair<int, int> r(0, 0);
  int n = a.size(),
      s[4][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}, {0, 1, 0, -1}, {1, 0, -1, 0}};
  for (int k = 0; k < 4; k++) {
    int x1 = i1 + s[k][0], y1 = j1 + s[k][1], x2 = i2 + s[k][2],
        y2 = j2 + s[k][3];
    if (x1 >= n || x2 < 0 || y1 >= n || y2 < 0) continue;
    if (a[i1][j1] == a[i2][j2] && a[x1][y1] == a[x2][y2]) r.first = 1;
    if ((i1 + j1) % 2) {
      if ((a[i1][j1] ^ 1) == a[i2][j2] && a[x1][y1] == (a[x2][y2] ^ 1))
        r.second = 1;
    } else {
      if (a[i1][j1] == (a[i2][j2] ^ 1) && (a[x1][y1] ^ 1) == a[x2][y2])
        r.second = 1;
    }
  }
  return r;
}
int main(int argc, char *argv[]) {
  int n, r;
  cin >> n;
  vector<vector<int> > a(n, vector<int>(n, -1));
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  for (int i = 0; i < n; i += 2)
    for (int j = 0; j < n; j += 2)
      for (int ii = i; ii < n && ii <= i + 2; ii++)
        for (int jj = j; jj < n && jj <= j + 2; jj++) {
          if (ii - i + jj - j != 2) continue;
          if (a[ii][jj] >= 0) continue;
          cout << "? " << (i + 1) << ' ' << (j + 1) << ' ' << (ii + 1) << ' '
               << (jj + 1) << endl
               << flush;
          cin >> r;
          a[ii][jj] = a[i][j] ^ r ^ 1;
        }
  a[0][1] = 0;
  cout << "? 1 2 3 2" << endl << flush;
  cin >> r;
  a[2][1] = a[0][1] ^ r ^ 1;
  cout << "? 2 1 3 2" << endl << flush;
  cin >> r;
  a[1][0] = a[2][1] ^ r ^ 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int ii = i; ii < n && ii <= i + 2; ii++)
        for (int jj = j; jj < n && jj <= j + 2; jj++) {
          if (ii - i + jj - j != 2 || a[ii][jj] >= 0) continue;
          cout << "? " << (i + 1) << ' ' << (j + 1) << ' ' << (ii + 1) << ' '
               << (jj + 1) << endl
               << flush;
          cin >> r;
          a[ii][jj] = a[i][j] ^ r ^ 1;
        }
  bool done = false;
  for (int i = 0; i < n && !done; i++)
    for (int j = 0; j < n && !done; j++)
      for (int ii = i; ii < n && !done; ii++)
        for (int jj = j; jj < n && !done; jj++) {
          int d = abs(i - ii) + abs(j - jj);
          if (d != 3) continue;
          pair<int, int> c = check(a, i, j, ii, jj);
          if (c.first != c.second) {
            cout << "? " << (i + 1) << ' ' << (j + 1) << ' ' << (ii + 1) << ' '
                 << (jj + 1) << endl
                 << flush;
            cin >> r;
            if (r ^ c.first != 0) {
              for (int x = 0; x < n; x++)
                for (int y = 0; y < n; y++)
                  if ((x + y) % 2) a[x][y] ^= 1;
            }
            done = true;
          }
        }
  cout << '!' << endl << flush;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << a[i][j];
    cout << endl << flush;
  }
  return 0;
}
