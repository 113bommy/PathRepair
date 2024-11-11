#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      c++;
    } else {
      if (c >= 6) {
        cout << "YES\n";
        exit(0);
      }
      c = 0;
    }
  }
  if (c >= 7)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
