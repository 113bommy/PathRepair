#include <bits/stdc++.h>
using namespace std;
int main() {
  int o = 0, z = 0;
  string s;
  cin >> s;
  for (int i = 1; s[i] != '\0'; i++) {
    if (s[i] == '1') {
      z = 0;
      o++;
    } else {
      o = 0;
      z++;
    }
    if (o >= 7 || z >= 7) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
