#include <bits/stdc++.h>
using namespace std;
void Daj(vector<vector<int> >& a, int* x, int* y) {
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < a[0].size(); ++j) {
      if (a[i][j] == -1) {
        *x = i;
        *y = j;
        return;
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int c, b, cb;
  cin >> c >> b >> cb;
  vector<vector<int> > a(n, vector<int>(m, -1));
  int cale = cb / m, reszta = cb % m;
  int x = 0, y = 0;
  if (b == 0 && c == 0) {
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) {
        for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 3 : 4;
      } else {
        for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 2 : 5;
      }
    }
  }
  if (c == 0 && b != 0) {
    if (cale % 2 == 0) {
      for (int i = 0; i < cale; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 3 : 4;
        } else {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 2 : 5;
        }
      }
    } else {
      for (int i = 0; i < cale; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 5 : 2;
        } else {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 4 : 3;
        }
      }
    }
    Daj(a, &x, &y);
    for (int i = x; i < n; ++i) {
      for (int j = (i == x ? y : 0); j < m; ++j) {
        if (b > 0) {
          a[i][j] = 1;
          --b;
        }
      }
    }
    x = n - 1, y = m - 1;
    if (reszta % 2 == 0) {
      for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 4 : 3;
    } else {
      for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 3 : 4;
    }
  }
  if (b == 0 && c != 0) {
    if (cale % 2 == 0) {
      for (int i = 0; i < cale; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 5 : 2;
        } else {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 4 : 3;
        }
      }
    } else {
      for (int i = 0; i < cale; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 3 : 4;
        } else {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 2 : 5;
        }
      }
    }
    Daj(a, &x, &y);
    for (int i = x; i < n; ++i) {
      for (int j = (i == x ? y : 0); j < m; ++j) {
        if (c > 0) {
          a[i][j] = 0;
          --c;
        }
      }
    }
    x = n - 1, y = m - 1;
    if (reszta % 2 == 0) {
      for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 2 : 5;
    } else {
      for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 5 : 2;
    }
  }
  if (b != 0 && c != 0) {
    if (cale >= 2) {
      for (int i = 0; i < cale - 1; ++i) {
        if (i % 2 == 0) {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 3 : 4;
        } else {
          for (int j = 0; j < m; ++j) a[i][j] = (j % 2 == 0) ? 2 : 5;
        }
      }
    }
    Daj(a, &x, &y);
    if (cale % 2 == 1) {
      for (int i = x; i < n; ++i) {
        for (int j = (i == x ? y : 0); j < m; ++j) {
          if (b > 0) {
            a[i][j] = 1;
            --b;
          }
        }
      }
      Daj(a, &x, &y);
      if (y != 0) {
        for (int i = x, j = y; j < m; ++j) a[i][j] = (j % 2 == y % 2) ? 3 : 4;
        for (int i = x + 1, j = 0; j < y; ++j)
          a[i][j] = (j % 2 == (y - 1) % 2) ? 3 : 4;
      } else {
        for (int i = x, j = 0; j < m; ++j) a[i][j] = (j % 2 == y % 2) ? 3 : 4;
      }
      Daj(a, &x, &y);
      for (int i = x; i < n; ++i) {
        for (int j = (i == x ? y : 0); j < m; ++j) {
          if (c > 0) {
            a[i][j] = 0;
            --c;
          }
        }
      }
      x = n - 1, y = m - 1;
      if (reszta % 2 == 0) {
        for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 2 : 5;
      } else {
        for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 5 : 2;
      }
    } else {
      for (int i = x; i < n; ++i) {
        for (int j = (i == x ? y : 0); j < m; ++j) {
          if (c > 0) {
            a[i][j] = 0;
            --c;
          }
        }
      }
      Daj(a, &x, &y);
      if (y != 0) {
        for (int i = x, j = y; j < m; ++j) a[i][j] = (j % 2 == y % 2) ? 5 : 2;
        for (int i = x + 1, j = 0; j < y; ++j)
          a[i][j] = (j % 2 == (y - 1) % 2) ? 5 : 2;
      } else {
        for (int i = x, j = 0; j < m; ++j) a[i][j] = (j % 2 == y % 2) ? 5 : 2;
      }
      Daj(a, &x, &y);
      for (int i = x; i < n; ++i) {
        for (int j = (i == x ? y : 0); j < m; ++j) {
          if (b > 0) {
            a[i][j] = 1;
            --b;
          }
        }
      }
      x = n - 1, y = m - 1;
      if (reszta % 2 == 0) {
        for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 4 : 3;
      } else {
        for (y; y >= m - reszta; --y) a[x][y] = (y % 2 == (m - 1) % 2) ? 3 : 4;
      }
    }
  }
  string t(2 * m, ' ');
  vector<string> odp(2 * n, t);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0) {
        odp[2 * i][2 * j] = '#';
        odp[2 * i][2 * j + 1] = '#';
        odp[2 * i + 1][2 * j] = '#';
        odp[2 * i + 1][2 * j + 1] = '#';
      }
      if (a[i][j] == 1) {
        odp[2 * i][2 * j] = '.';
        odp[2 * i][2 * j + 1] = '.';
        odp[2 * i + 1][2 * j] = '.';
        odp[2 * i + 1][2 * j + 1] = '.';
      }
      if (a[i][j] == 2) {
        odp[2 * i][2 * j] = '\\';
        odp[2 * i][2 * j + 1] = '#';
        odp[2 * i + 1][2 * j] = '.';
        odp[2 * i + 1][2 * j + 1] = '\\';
      }
      if (a[i][j] == 3) {
        odp[2 * i][2 * j] = '.';
        odp[2 * i][2 * j + 1] = '/';
        odp[2 * i + 1][2 * j] = '/';
        odp[2 * i + 1][2 * j + 1] = '#';
      }
      if (a[i][j] == 4) {
        odp[2 * i][2 * j] = '\\';
        odp[2 * i][2 * j + 1] = '.';
        odp[2 * i + 1][2 * j] = '#';
        odp[2 * i + 1][2 * j + 1] = '\\';
      }
      if (a[i][j] == 5) {
        odp[2 * i][2 * j] = '#';
        odp[2 * i][2 * j + 1] = '/';
        odp[2 * i + 1][2 * j] = '/';
        odp[2 * i + 1][2 * j + 1] = '.';
      }
    }
  }
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = 0; j < 2 * m; ++j) cout << odp[i][j];
    cout << endl;
  }
  return 0;
}
