#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  string p = "";
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < t[i]) {
      cout << -1;
      return 0;
    } else if (s[i] == t[i])
      p += (s[i] + 1);
    else
      p += t[i];
  }
  cout << p;
  return 0;
}
