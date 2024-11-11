#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  char a[19] = {'A', 'b', 'd', 'H', 'I', 'M', 'O', 'o', 'p', 'q',
                'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};
  char b[19] = {'A', 'd', 'b', 'H', 'I', 'M', 'O', 'o', 'q', 'p',
                'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y'};
  map<char, char> mirror;
  for (int i = 0; i < 19; i++) {
    mirror[a[i]] = b[i];
  }
  bool p = true;
  for (int i = 0; i <= s.length() / 2; i++) {
    if (s[s.length() - 1 - i] != mirror[s[i]]) p = false;
  }
  cout << ((p == true) ? "TAK\n" : "NIE\n");
  return 0;
}
