#include <bits/stdc++.h>
using namespace std;
int main() {
  int x = 0, y = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'a') {
      x++;
    } else {
      y++;
    }
  }
  if (x > y) {
    cout << x + y << endl;
  } else {
    cout << x + x - 1;
  }
  return 0;
}
