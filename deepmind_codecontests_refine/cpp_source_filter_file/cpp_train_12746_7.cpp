#include <bits/stdc++.h>
using namespace std;
string s, r = "AHIMOTUVWXY";
int main() {
  cin >> s;
  for (int i = 0; i < s.length() / 2; i++) {
    bool t = 0;
    if (s[i] != s[s.length() - i - 1]) {
      cout << "NO";
      return 0;
    }
    for (int j = 0; j < 11; j++)
      if (s[i] == r[j]) t = 1;
    if (!t) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
