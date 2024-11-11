#include <bits/stdc++.h>
using namespace std;
double PI = 3.1415926535897932384626433832795;
int main() {
  string s;
  cin >> s;
  for (int i = 1; i < s.size() - 4; ++i) {
    if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't')
      s.replace(i, 3, "."), i -= 2;
  }
  for (int i = 1; i < s.size() - 3; ++i) {
    if (s[i] == 'a' && s[i + 1] == 't') {
      s.replace(i, 2, "@");
      break;
    }
  }
  cout << s;
  return 0;
}
