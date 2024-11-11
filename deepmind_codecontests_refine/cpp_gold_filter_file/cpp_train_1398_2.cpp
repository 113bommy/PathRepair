#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > a(8, vector<int>(8, 0));
bool check() {
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      if (a[i][j] == 1) {
        if ((i - 2 >= 0) && (j - 1 >= 0) && (a[i - 2][j - 1] != 0))
          return false;
        if ((i - 1 >= 0) && (j - 2 >= 0) && (a[i - 1][j - 2] != 0))
          return false;
        if ((i + 2 <= 7) && (j - 1 >= 0) && (a[i + 2][j - 1] != 0))
          return false;
        if ((i - 1 >= 0) && (j + 2 <= 7) && (a[i - 1][j + 2] != 0))
          return false;
        if ((i - 2 >= 0) && (j + 1 <= 7) && (a[i - 2][j + 1] != 0))
          return false;
        if ((i + 1 <= 7) && (j - 2 >= 0) && (a[i + 1][j - 2] != 0))
          return false;
        if ((i + 2 <= 7) && (j + 1 <= 7) && (a[i + 2][j + 1] != 0))
          return false;
        if ((i + 1 <= 7) && (j + 2 <= 7) && (a[i + 1][j + 2] != 0))
          return false;
      }
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      if (a[i][j] == 2) {
        for (int i1 = 0; i1 < 8; ++i1)
          if (a[i1][j] == 1) return false;
        for (int j1 = 0; j1 < 8; ++j1)
          if (a[i][j1] == 1) return false;
      }
  return true;
}
int main() {
  string s1, s2;
  cin >> s2 >> s1;
  int x1, y1;
  x1 = (int)(s1[0] - 'a');
  y1 = (int)(s1[1] - '1');
  int x2, y2;
  x2 = (int)(s2[0] - 'a');
  y2 = (int)(s2[1] - '1');
  a[x1][y1] = 1;
  a[x2][y2] = 2;
  int cnt = 0;
  for (int i = 0; i < 8; ++i)
    for (int j = 0; j < 8; ++j)
      if (a[i][j] == 0) {
        a[i][j] = 1;
        if (check()) ++cnt;
        a[i][j] = 0;
      }
  cout << cnt << endl;
  return 0;
}
