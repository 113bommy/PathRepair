#include <bits/stdc++.h>
using namespace std;
int main() {
  int d = 0;
  string s, e;
  cin >> s;
  cin >> e;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == e[e.size() - 1 - i]) {
      d++;
    }
  }
  if (d == s.size())
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
