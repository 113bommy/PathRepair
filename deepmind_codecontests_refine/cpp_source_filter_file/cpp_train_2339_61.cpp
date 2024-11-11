#include <bits/stdc++.h>
using namespace std;
char f(char c) {
  if (c == 's')
    return 'p';
  else if (c == 'p')
    return 'r';
  else
    return 's';
}
int main() {
  int w = 0, ans = 4;
  string txt[3];
  cin >> txt[0] >> txt[1] >> txt[2];
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      if (f(txt[i][0]) == txt[j][0]) {
        w++, ans = i;
        break;
      }
    }
  }
  if (w > 1 || ans == 4) return cout << '?' << endl, 0;
  if (ans == 0)
    cout << 'F' << endl;
  else if (ans == 1)
    cout << 'M' << endl;
  else
    cout << 'S' << endl;
  return 0;
}
