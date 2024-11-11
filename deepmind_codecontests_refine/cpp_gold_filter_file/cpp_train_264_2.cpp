#include <bits/stdc++.h>
using namespace std;
int main() {
  int flag = 0;
  char s[6][6];
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) cin >> s[i][j];
  for (int i = 0; i < 4; i++) {
    if (flag) break;
    for (int j = 0; j < 4; j++) {
      if (s[i][j] == 'x' && s[i][j + 1] == 'x' &&
          (s[i][j + 2] == '.' || s[i][j - 1] == '.')) {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i][j + 1] == '.' && s[i][j + 2] == 'x') {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j] == 'x' &&
                 (s[i + 2][j] == '.' || s[i - 1][j] == '.')) {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j] == '.' && s[i + 2][j] == 'x') {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j + 1] == 'x' &&
                 (s[i + 2][j + 2] == '.' || s[i - 1][j - 1] == '.')) {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j + 1] == '.' &&
                 s[i + 2][j + 2] == 'x') {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j - 1] == 'x' &&
                 (s[i + 2][j - 2] == '.' || s[i - 1][j + 1] == '.')) {
        cout << "YES";
        flag = 1;
        break;
      } else if (s[i][j] == 'x' && s[i + 1][j - 1] == '.' &&
                 s[i + 2][j - 2] == 'x') {
        cout << "YES";
        flag = 1;
        break;
      }
    }
  }
  if (!flag) cout << "NO";
  return 0;
}
