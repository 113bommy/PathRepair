#include <bits/stdc++.h>
using namespace std;
char cc[] = {'A', 'H', 'I', 'M', 'O', 'o', 'T', 'U',
             'V', 'v', 'W', 'w', 'X', 'x', 'Y', '\0'};
bool jud(char x) {
  int len = strlen(cc);
  for (int i = 0; i < len; i++) {
    if (x == cc[i]) return true;
  }
  return false;
}
bool jud2(char x, char y) {
  if (x > y) swap(x, y);
  if (x == 'b' && y == 'd' || x == 'p' && y == 'q') {
    return true;
  }
  return false;
}
int main() {
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len / 2; i++) {
    if (jud(s[i]) && s[i] == s[len - 1 - i] || jud2(s[i], s[len - 1 - i]))
      ;
    else {
      cout << "NIE";
      return 0;
    }
  }
  cout << "TAK";
  return 0;
}
