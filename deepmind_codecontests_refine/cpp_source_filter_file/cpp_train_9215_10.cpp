#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0, y = 0, cnt = 0, n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    x = 0;
    y = 0;
    for (int j = i; j < n; j++) {
      if (s[j] == 'U')
        y++;
      else if (s[i] == 'D')
        y--;
      else if (s[i] == 'R')
        x++;
      else if (s[i] == 'L')
        x--;
      if (x == 0 && y == 0) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
