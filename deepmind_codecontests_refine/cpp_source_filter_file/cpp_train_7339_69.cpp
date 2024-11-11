#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  char mat[8][8];
  int i, j, k;
  string s;
  for (i = 0; i < 8; i++) {
    cin >> s;
    for (j = 0; j < 8; j++) {
      mat[i][j] = s.at(j);
    }
  }
  bool flag = 0;
  int w = INT_MAX, b = INT_MAX;
  for (i = 1; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (mat[i][j] == 'W') {
        flag = 1;
        for (k = 0; k < i; k++) {
          if (mat[k][j] != '.') {
            flag = 0;
            break;
          }
        }
        if (flag) w = min(w, i);
      }
    }
  }
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 7; j++) {
      if (mat[i][j] == 'B') {
        flag = 1;
        for (k = i + 1; k < 8; k++) {
          if (mat[k][j] != '.') {
            flag = 0;
            break;
          }
        }
        if (flag) b = min(b, 7 - i);
      }
    }
  }
  if (w <= b)
    cout << "A" << endl;
  else
    cout << "B" << endl;
  return 0;
}
