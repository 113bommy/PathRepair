#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool reversible(const string &s, int idx) {
  int n = s.length();
  int i = idx - 1, j = idx + 1;
  while (i >= 0 && j < n) {
    if (s[i] != s[j]) return false;
    --i;
    ++j;
  }
  return true;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s, t;
    cin >> s >> t;
    string r(t);
    reverse(r.begin(), r.end());
    if (s.find(t) != string::npos || s.find(r) != string::npos) {
      cout << "Yes\n";
      continue;
    }
    int sz = t.length();
    bool ok = false;
    for (int i = 1; i < sz - 1; ++i) {
      if (reversible(t, i)) {
        string f1 = t.substr(0, i + 1);
        string f2 = t.substr(i);
        if (f1.length() >= f2.length()) {
          if (s.find(f1) != string::npos) {
            ok = true;
            break;
          }
        } else {
          reverse(f2.begin(), f2.end());
          if (s.find(f2) != string::npos) {
            ok = true;
            break;
          }
        }
      }
    }
    if (ok)
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
