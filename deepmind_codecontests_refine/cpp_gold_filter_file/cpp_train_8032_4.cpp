#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  ;
  long long h, w, i, j, p = 0;
  cin >> h >> w;
  char s[h][w];
  for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
      cin >> s[i][j];
      if (s[i][j] == '*') {
        p++;
      }
    }
  }
  for (i = 1; i < h - 1; i++) {
    for (j = 1; j < w - 1; j++) {
      if (s[i][j] == '*' && s[i - 1][j] == '*' && s[i + 1][j] == '*' &&
          s[i][j + 1] == '*' && s[i][j - 1] == '*' && j + 1 < w && i + 1 < h) {
        long long x = i - 1, y = j, z = 1;
        while (x >= 0) {
          if (s[x][y] == '*') {
            z++;
          } else {
            break;
          }
          x--;
        }
        x = i + 1;
        y = j;
        while (x < h) {
          if (s[x][y] == '*') {
            z++;
          } else {
            break;
          }
          x++;
        }
        x = i;
        y = j - 1;
        while (y >= 0) {
          if (s[x][y] == '*') {
            z++;
          } else {
            break;
          }
          y--;
        }
        x = i;
        y = j + 1;
        while (y <= w) {
          if (s[x][y] == '*') {
            z++;
          } else {
            break;
          }
          y++;
        }
        if (p == z) {
          cout << "YES";
        } else {
          cout << "NO";
        }
        return 0;
      }
    }
  }
  cout << "NO";
}
