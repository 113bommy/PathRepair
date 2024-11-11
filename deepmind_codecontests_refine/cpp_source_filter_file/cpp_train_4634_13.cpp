#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int j = 0;
  string t = "hello";
  bool b = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[j]) j++;
    if (j == t.size() - 1) {
      b = true;
      break;
    }
  }
  if (b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
