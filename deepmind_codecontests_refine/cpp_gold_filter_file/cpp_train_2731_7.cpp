#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int main() {
  int t;
  cin >> t;
  for (int e = 0; e < t; e++) {
    string s[15];
    for (int i = 0; i < 9; i++) {
      cin >> s[i];
    }
    s[0][2] = s[0][0];
    s[1][5] = s[1][3];
    s[2][8] = s[2][6];
    s[3][1] = s[3][0];
    s[4][4] = s[4][3];
    s[5][7] = s[5][6];
    s[6][0] = s[6][2];
    s[7][3] = s[7][5];
    s[8][6] = s[8][8];
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << s[i][j];
      }
      cout << endl;
    }
  }
  return 0;
}
