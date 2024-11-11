#include <bits/stdc++.h>
using namespace std;
int i, j, down, up, getdown, getup, n;
string s;
int main() {
  cin >> n;
  cin >> s;
  for (i = 0; i < s.size(); i++)
    if (s[i] == 'X')
      up++;
    else
      down++;
  if (up == down)
    cout << '0' << '\n' << s;
  else {
    if (up < down) {
      getup = n / 2 - up;
      i = 0;
      j = 0;
      while ((i < s.size()) && (j < getup)) {
        if (s[i] == 'x') {
          s[i] = 'X';
          j++;
        }
        i++;
      }
      cout << getup << '\n' << s;
    } else {
      getdown = n / 2 - down;
      i = 0;
      j = 0;
      while ((i < s.size()) && (j < getdown)) {
        if (s[i] == 'X') {
          s[i] = 'x';
          j++;
        }
        i++;
      }
      cout << getdown << '\n' << s;
    }
  }
  return 0;
}
