#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  int l = s.size();
  int up = 0, down = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == 'X') {
      up++;
    } else {
      down++;
    }
  }
  if (up == down) {
    cout << "0" << endl;
    cout << s << endl;
  } else if (up > down) {
    int h = up - down - 1;
    cout << h << endl;
    for (int i = 0; i < l; i++) {
      if (h > 0) {
        if (s[i] == 'X') {
          cout << "x";
          h--;
          continue;
        }
      }
      cout << s[i];
    }
    cout << endl;
  } else {
    int h = down - up - 1;
    cout << h << endl;
    for (int i = 0; i < l; i++) {
      if (h > 0) {
        if (s[i] == 'x') {
          cout << "X";
          h--;
          continue;
        }
      }
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
