#include <bits/stdc++.h>
using namespace std;
string s[111];
int dx[4] = {0, 1, 1, 1};
int dy[4] = {1, 0, 1, -1};
bool check() {
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      for (int d = 0; d < 3; d++) {
        bool f = 1;
        int x = i, y = j;
        for (int cnt = 0; cnt < 3; cnt++) {
          if (s[x][y] != 'x') {
            f = 0;
          }
          x += dx[d];
          y += dy[d];
        }
        if (f) {
          return 1;
        }
      }
    }
  return 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  for (int i = 0; i < 4; i++) {
    cin >> s[i];
    s[i] += "      ";
  }
  for (int i = 4; i < 11; i++) {
    s[i] = "          ";
  }
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) {
      if (s[i][j] == '.') {
        s[i][j] = 'x';
        if (check()) {
          cout << "YES\n";
          return 0;
        }
        s[i][j] = '.';
      }
    }
  cout << "NO\n";
  return 0;
}
