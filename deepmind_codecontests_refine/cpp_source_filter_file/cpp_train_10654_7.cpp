#include <bits/stdc++.h>
using namespace std;
int a[8][8];
string s[4];
string t[7] = {{"aaab"}, {"aaba"}, {"aabb"}, {"abaa"},
               {"abab"}, {"abba"}, {"abbb"}};
int main() {
  for (int i = 0; i < 7; i++) cin >> a[i][7];
  a[2][0] = 1;
  a[4][0] = 1;
  a[5][0] = 1;
  a[1][1] = 1;
  a[3][1] = 1;
  a[5][1] = 1;
  a[1][2] = 1;
  a[2][2] = 1;
  a[3][2] = 1;
  a[4][2] = 1;
  a[0][3] = 1;
  a[3][3] = 1;
  a[4][3] = 1;
  a[0][4] = 1;
  a[2][4] = 1;
  a[3][4] = 1;
  a[5][4] = 1;
  a[0][5] = 1;
  a[1][5] = 1;
  a[4][5] = 1;
  a[5][5] = 1;
  a[0][6] = 1;
  a[1][6] = 1;
  a[2][6] = 1;
  for (int i = 0; i < 6; i++) {
    int x = -1;
    for (int j = 6; j >= i; j--)
      if (a[j][i]) x = j;
    if (x == -1) {
      cout << -1;
      return 0;
    }
    for (int j = 0; j <= 7; j++) swap(a[i][j], a[x][j]);
    x = a[i][i];
    for (int j = 0; j <= 7; j++) {
      if (a[i][j] % x) {
        cout << -1;
        return 0;
      }
      a[i][j] = a[i][j] / x;
    }
    for (int j = i + 1; j < 7; j++) {
      x = -a[j][i];
      for (int k = 0; k <= 7; k++) a[j][k] = a[j][k] + a[i][k] * x;
    }
  }
  for (int i = 5; i >= 0; i--) {
    int x = -1;
    for (int j = 0; j <= i; j++)
      if (a[j][i]) x = j;
    if (x == -1) {
      cout << -1;
      return 0;
    }
    for (int j = 0; j <= 7; j++) swap(a[i][j], a[x][j]);
    x = a[i][i];
    for (int j = 0; j <= 7; j++) {
      if (a[i][j] % x) {
        cout << -1;
        return 0;
      }
      a[i][j] = a[i][j] / x;
    }
    for (int j = i - 1; j >= 0; j--) {
      x = -a[j][i];
      for (int k = 0; k <= 7; k++) a[j][k] = a[j][k] + a[i][k] * x;
    }
  }
  int ans = 1000000000, x = -1;
  for (int i = 0; i < 10000000; i++) {
    bool f = 1;
    int len = 0;
    for (int j = 0; j < 6; j++) {
      if (a[j][7] - a[j][6] * i < 0) f = 0;
      len += a[j][7] - a[j][6] * i;
    }
    if (f && len < ans) {
      ans = len;
      x = i;
    }
  }
  if (x == -1) {
    cout << -1;
    return 0;
  }
  cout << ans << endl;
  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 4; j++)
      for (int k = 0; k < a[i][7] - a[i][6] * x; k++) s[j] += t[i][j];
  for (int j = 0; j < 4; j++)
    for (int k = 0; k < x; k++) s[j] += t[7][j];
  for (int i = 0; i < 4; i++) cout << s[i] << endl;
  return 0;
}
