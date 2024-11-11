#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int a[n + 2][3];
  for (int i = 0; i < n + 1; i++)
    for (int j = 0; j < 3; j++) a[i][j] = 0;
  for (int k = 0; k < s.length(); k++) {
    if (s[k] == '.')
      continue;
    else if (s[k] == 'A') {
      a[k][1] = 1;
      a[k + 1][1] = 1;
      a[k + 2][1] = 1;
    } else if (s[k] == 'B') {
      a[k][0] = 1;
      a[k + 1][0] = 1;
      a[k + 2][0] = 1;
    } else {
      a[k][2] = 1;
      a[k + 1][2] = 1;
      a[k + 2][2] = 1;
    }
  }
  for (int l = 1; l <= n; l++) {
    if (a[l][0] == 1 && a[l][1] == 1 && a[l][2] == 1) {
      cout << l - 1 << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
