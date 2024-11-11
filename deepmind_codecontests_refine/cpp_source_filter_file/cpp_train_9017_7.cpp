#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int x = 200, y = 200;
  int a[205][205]{0};
  for (int i = 0; i < s.size(); i++) {
    a[x][y] = 1;
    if (s[i] == 'U') y++;
    if (s[i] == 'D') y--;
    if (s[i] == 'L') x--;
    if (s[i] == 'R') x++;
    if (a[x][y] ||
        (a[x - 1][y] + a[x + 1][y] + a[x][y - 1] + a[x][y + 1]) > 1) {
      cout << "BUG";
      return 0;
    }
  }
  cout << "OK";
  return 0;
}
