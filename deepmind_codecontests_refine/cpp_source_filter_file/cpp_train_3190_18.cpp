#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[15][15];
  int x, y, flag = 0;
  for (int i = 0; i < 9; i++) {
    gets(s[i]);
    if (i == 2 || i == 5) getchar();
  }
  cin >> x >> y;
  x--;
  y--;
  x %= 3;
  y %= 3;
  x *= 3;
  y *= 3;
  int cnt = 0;
  for (int i = x; i <= x + 2; i++) {
    for (int j = y; j <= y + 2; j++) {
      if (s[i][j] == '.') cnt++;
    }
  }
  if (!cnt) {
    flag = 1;
  } else {
    for (int i = x; i <= x + 2; i++) {
      for (int j = y; j <= y + 2; j++) {
        if (s[i][j] == '.') s[i][j] = '!';
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 11; j++) {
      if (flag && s[i][j] == '.')
        cout << '!';
      else
        cout << s[i][j];
      if (j == 10) cout << "\n";
    }
    if (i == 2 || i == 5) cout << "\n";
  }
}
