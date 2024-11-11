#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int n = s.size(), c = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      c++;
    }
  }
  if ((n - c) % 2) {
    cout << ":(";
    return 0;
  }
  string t = s.substr(0, c + (n - c) / 2);
  string w = t;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] != 'a') {
      w += t[i];
    }
  }
  if (w == s) {
    cout << t;
  } else {
    cout << ":(";
  }
  return 0;
}
