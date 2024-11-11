#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, f;
  cin >> f >> s;
  bool h = true;
  if (f.size() != f.size()) {
    cout << "no";
    h = false;
  } else
    for (int i = 0; i < s.size(); i++)
      if (s[i] != f[f.size() - 1 - i]) {
        cout << "NO";
        h = false;
        break;
      }
  if (h == true) cout << "YES";
  return 0;
}
