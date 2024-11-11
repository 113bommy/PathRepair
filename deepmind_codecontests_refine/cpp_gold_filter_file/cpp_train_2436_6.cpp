#include <bits/stdc++.h>
using namespace std;
long long a, b;
int x, y;
string s;
int c;
int main() {
  cin >> a >> b;
  if (a == 0 && b == 0) {
    cout << "Yes";
    return 0;
  }
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U')
      y++;
    else if (s[i] == 'D')
      y--;
    else if (s[i] == 'R')
      x++;
    else
      x--;
    if (x == a && y == b) {
      cout << "Yes";
      return 0;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'U')
      b--;
    else if (s[i] == 'D')
      b++;
    else if (s[i] == 'R')
      a--;
    else
      a++;
    if (x != 0) {
      c = a / x;
    }
    if (y != 0) {
      c = b / y;
    }
    if (c >= 0 && (x * c) == a && (y * c) == b) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";
  return 0;
}
