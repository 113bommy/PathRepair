#include <bits/stdc++.h>
using namespace std;
char s[55][55];
int main() {
  int n, i, j;
  cin >> n;
  int flag = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cin >> s[i][j];
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] == '.' && s[i + 1][j + 1] == '.' && s[i + 1][j] == '.' &&
          s[i + 1][j - 1] == '.' && s[i + 2][j] == '.') {
        s[i][j] = '#';
        s[i + 1][j + 1] = '#';
        s[i + 1][j] = '#';
        s[i + 1][j - 1] = '#';
        s[i + 2][j] = '#';
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        flag = 1;
      }
    }
  }
  if (flag)
    cout << "NO";
  else
    cout << "YES";
  return 0;
}
