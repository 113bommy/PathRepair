#include <bits/stdc++.h>
using namespace std;
int main() {
  bool possible = true;
  for (int i = 0; i < 8; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < s.length() - 1; j++) {
      if (s[j] == s[j + 1]) {
        possible = false;
        break;
      }
    }
  }
  if (possible)
    cout << "YES";
  else
    cout << "NO";
}
