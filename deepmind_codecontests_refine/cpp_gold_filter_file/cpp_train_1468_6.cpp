#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int len = s.length();
  string a = "aeiou";
  for (int i = 0; i < len; i++) {
    if (a.find(s[i]) == -1 && (s[i] != 'n')) {
      if (a.find(s[i + 1]) == -1) {
        cout << "NO";
        return 0;
      }
    }
  }
  cout << "YES";
  return 0;
}
