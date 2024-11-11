#include <bits/stdc++.h>
using namespace std;
char s[10][105];
int main() {
  int n, k;
  cin >> n >> k;
  if (k % 2 == 0) {
    cout << "YES" << endl;
    for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) s[i][j] = '.';
    }
    for (int j = 2; j <= 2 + k / 2 - 1; j++) {
      for (int i = 2; i <= 3; i++) {
        s[i][j] = '#';
      }
    }
    for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) cout << s[i][j];
      cout << endl;
    }
  } else {
    for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) s[i][j] = '.';
    }
    s[2][n / 2 + 1] = '#';
    k--;
    int l = n / 2, r = n / 2 + 2;
    while (k) {
      if (l == 1 || r == n) break;
      s[2][l] = '#';
      s[2][r] = '#';
      l--;
      r++;
      k = k - 2;
    }
    l = n / 2, r = n / 2 + 2;
    while (k) {
      if (l == 1 || r == n) break;
      s[3][l] = '#';
      s[3][r] = '#';
      l--;
      r++;
      k = k - 2;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 4; i++) {
      for (int j = 1; j <= n; j++) cout << s[i][j];
      cout << endl;
    }
  }
  return 0;
}
