#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s;
  cin >> t;
  bool f = false;
  int i;
  for (i = 0; i < n && s[i] == t[i]; i++)
    ;
  if (i == n && m == n) {
    cout << "YES";
    return 0;
  }
  if (s[i] == '*') {
    string ss = s.substr(i + 1);
    string tt = t.substr(i);
    int k = tt.size() - ss.size();
    for (int i = 0; i < ss.size(); i++) {
      if (k + i < 0) {
        cout << "NO";
        return 0;
      }
      if (ss[i] != tt[i + k]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  } else {
    cout << "NO";
    return 0;
  }
  return 0;
}
