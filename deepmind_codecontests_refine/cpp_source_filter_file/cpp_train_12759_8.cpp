#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
  cin >> s;
  n = s.length();
  bool has = false;
  for (int i = 0; i < n; i++) {
    if (s[i] != 'a') {
      has = true;
      break;
    }
  }
  if (!has) {
    for (int i = 0; i < n - 1; i++) {
      cout << 'a';
    }
    cout << 'b' << endl;
    return 0;
  }
  bool st = false;
  for (int i = 0; i < n; i++) {
    if (!st) {
      if (s[i] != 'a') {
        s[i]--;
        st = true;
      }
    } else {
      if (s[i] == 'a') {
        break;
      }
      s[i]--;
    }
  }
  cout << s << endl;
}
