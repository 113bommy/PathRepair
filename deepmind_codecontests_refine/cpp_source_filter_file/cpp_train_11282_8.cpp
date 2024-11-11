#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int x = 0, y = 0;
  bool check = 0;
  for (int i = 0; i < s.size(); i++) {
    for (int j = x; j < t.size(); j++) {
      if (s[i] == t[j]) {
        x = j + 1;
        y = i + 2;
        check = 1;
        break;
      }
    }
    if (check == 0)
      break;
    else
      check = 0;
  }
  if (y == s.size() + 1) y = y - 1;
  cout << y << " ";
  return 0;
}
