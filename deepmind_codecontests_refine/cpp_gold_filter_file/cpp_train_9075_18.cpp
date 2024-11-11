#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i;
  int four = 0, seven = 0, t = 0;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == '4') {
      if (t == 0) {
        t = 4;
      }
      four++;
    } else if (s[i] == '7') {
      if (t == 0) {
        t = 7;
      }
      seven++;
    }
  }
  if (four > seven) {
    cout << 4;
  } else if (seven == 0 && four == 0) {
    cout << -1;
  } else if (seven > four) {
    cout << 7;
  } else {
    cout << 4;
  }
}
