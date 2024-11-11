#include <bits/stdc++.h>
using namespace std;
long long r, c;
char p[505][505];
int main() {
  cin >> r >> c;
  for (long i = long(1); i <= long(r); i++)
    for (long j = long(1); j <= long(c); j++) cin >> p[i][j];
  for (long i = long(1); i <= long(r); i++)
    for (long j = long(1); j <= long(c); j++) {
      if (p[i][j] == 'S') {
        if (p[i - 1][j] == 'W' || p[i][j + 1] == 'W' || p[i + 1][j] == 'W' ||
            p[i][j - 1] == 'W') {
          cout << "No";
          return 0;
        }
        if (p[i - 1][j] != 'S') p[i - 1][j] = 'D';
        if (p[i + 1][j] != 'S') p[i + 1][j] = 'D';
        if (p[i][j + 1] != 'S') p[i][j + 1] = 'D';
        if (p[i][j - 1] != 'S') p[i][j - 1] = 'D';
      }
    }
  cout << "Yes"
       << "\n";
  for (long i = long(1); i <= long(r); i++) {
    for (long j = long(1); j <= long(c); j++) cout << p[i][j];
    cout << "\n";
  }
  return 0;
}
