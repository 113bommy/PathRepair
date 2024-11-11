#include <bits/stdc++.h>
using namespace std;
bool v[26];
char ans[2][26];
int main() {
  string second;
  cin >> second;
  char c;
  for (int i = 0; i < second.size(); i++) {
    if (v[second[i] - 'A']) c = second[i];
    v[second[i] - 'A'] = true;
  }
  int x = -1, y = -1;
  for (int i = 0; i < second.size(); i++) {
    if (second[i] == c) {
      if (x == -1)
        x = i;
      else
        y = i;
    }
  }
  if (y - x == 1) {
    cout << "Impossible";
    return 0;
  }
  int xx = 0, yy = 0;
  if (y - x == 2) {
    for (int i = 0; i < second.size(); i++) {
      if (y == i) continue;
      ans[xx][yy] = second[i];
      xx++;
      if (xx == 2) xx = 0, yy++;
    }
  } else {
    int need = (y - x - 1) / 2;
    xx = 1, yy = 12 - need;
    int ind = 0;
    for (int i = x; i < second.size(); i++) {
      if (y == i) continue;
      ans[xx][yy] = second[i];
      if (ind == 0)
        yy++;
      else if (ind == 1)
        yy--;
      if (yy == 13) xx = 0, yy = 12, ind = 1;
      if (yy == -1) xx = 1, yy = 0, ind = 0;
    }
    xx = 1, yy = 12 - need - 1;
    ind = 1;
    if (yy == -1) xx = 0, yy = 0, ind = 0;
    for (int i = x - 1; i >= 0; i--) {
      ans[xx][yy] = second[i];
      if (ind == 0)
        yy++;
      else if (ind == 1)
        yy--;
      if (yy == 13) xx = 1, yy = 12, ind = 1;
      if (yy == -1) xx = 0, yy = 0, ind = 0;
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 26; j++) printf("%c", ans[i][j]);
    printf("\n");
  }
  return 0;
}
