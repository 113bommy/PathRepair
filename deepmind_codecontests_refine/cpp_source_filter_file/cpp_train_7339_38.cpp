#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, c, res1 = 0, res2 = 0;
  char a[10][10];
  vector<pair<int, int> > v1, v2;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'W') {
        v1.push_back(pair<int, int>(i, j));
      }
      if (a[i][j] == 'B') {
        v2.push_back(pair<int, int>(i, j));
      }
    }
  }
  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end(), greater<pair<int, int> >());
  for (i = 0; i < v1.size(); i++) {
    int fg = 0;
    pair<int, int> top = v1[i];
    int tx = top.first;
    int ty = top.second;
    for (j = tx; j >= 0; j--) {
      if (a[j][ty] == 'B') {
        fg = 1;
        break;
      }
    }
    if (fg == 0) {
      res1 = tx + 1;
      break;
    }
  }
  for (i = 0; i < v2.size(); i++) {
    int fg = 0;
    pair<int, int> top = v2[i];
    int tx = top.first;
    int ty = top.second;
    for (j = tx; j < 8; j++) {
      if (a[j][ty] == 'W') {
        fg = 1;
        break;
      }
    }
    if (fg == 0) {
      res2 = 8 - tx - 1;
      break;
    }
  }
  if (res1 > res2)
    cout << 'B';
  else {
    cout << 'A';
  }
  return 0;
}
