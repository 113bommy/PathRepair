#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 5, INF = (int)1e9;
const long double EPS = 1e-9;
int a[10][10];
string s[10];
int main() {
  a[0][0] = a[0][1] = a[0][6] = a[0][7] = 3;
  a[0][3] = a[0][4] = 4;
  a[1][0] = a[1][1] = a[1][6] = a[1][7] = 3;
  a[1][3] = a[1][4] = 4;
  a[2][0] = a[2][1] = a[2][6] = a[2][7] = 2;
  a[2][3] = a[2][4] = 3;
  a[3][0] = a[3][1] = a[3][6] = a[3][7] = 2;
  a[3][3] = a[3][4] = 3;
  a[4][0] = a[4][1] = a[4][6] = a[4][7] = 1;
  a[4][3] = a[4][4] = 2;
  a[5][0] = a[5][1] = a[5][6] = a[5][7] = 1;
  a[5][3] = a[5][4] = 2;
  int ans = 0, indi, indj;
  for (int i = 0; i < 6; i++) {
    cin >> s[i];
    for (int j = 0; j < 8; j++)
      if (s[i][j] == '.' && a[i][j] > ans) {
        ans = a[i][j];
        indi = i;
        indj = j;
      }
  }
  for (int i = 0; i < 6; i++) {
    if (indi == i) s[i][indj] = 'p';
    cout << s[i] << endl;
  }
  return 0;
}
