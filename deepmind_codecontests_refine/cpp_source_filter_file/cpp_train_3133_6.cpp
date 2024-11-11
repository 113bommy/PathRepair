#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  string t;
  cin >> s >> t;
  int big = max(s.size(), t.size());
  for (int i = 0; i < big; i++) {
    if (s[s.size() - i] != t[t.size() - i]) {
      cout << (s.size() - i + 1) + (t.size() - i + 1) << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
