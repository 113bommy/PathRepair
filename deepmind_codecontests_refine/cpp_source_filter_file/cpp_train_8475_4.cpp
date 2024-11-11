#include <bits/stdc++.h>
using namespace std;
char a[114][114];
int n;
int main() {
  int i, j, nr;
  fstream f, g;
  f.open("date.in", ios::in);
  g.open("date.out", ios::out);
  f >> n;
  for (i = 1; i <= n; i++) f >> a[i];
  int ok = 0;
  while (ok == 0) {
    ok = 1;
    for (i = 1; i <= n; i++) {
      if (ok == 0) break;
      for (j = 0; j < n; j++)
        if (a[i][j] == '#')
          if (i <= n - 2 && j > 0 && j < n - 1) {
            if (a[i + 1][j] == '#' && a[i + 1][j + 1] == '#' &&
                a[i + 1][j - 1] == '#' && a[i + 2][j] == '#') {
              a[i + 1][j] = a[i + 1][j + 1] = a[i + 1][j - 1] = a[i + 2][j] =
                  a[i][j] = '.';
              ok = 0;
              break;
            } else {
              cout << "NO";
              return 0;
            }
          } else {
            cout << "NO";
            return 0;
          }
    }
  }
  cout << "YES";
}
