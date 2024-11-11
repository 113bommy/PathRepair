#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, i, len, beg;
  string s[70007], p;
  map<string, int> m;
  set<string> was;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> s[i];
  for (i = 1; i <= n; i++) {
    m[s[i]]++;
    for (len = 1; len <= 8; len++) {
      for (beg = 0; beg <= 9 - len; beg++) {
        p = s[i].substr(beg, len);
        if (was.count(p) == 0) {
          m[p]++;
          was.insert(p);
        }
      }
      was.clear();
    }
  }
  for (i = 1; i <= n; i++) {
    for (len = 1; len <= 8; len++) {
      for (beg = 0; beg <= 9 - len; beg++) {
        p = s[i].substr(beg, len);
        if (m[p] == 1) {
          cout << p << '\n';
          goto m1;
        }
      }
    }
  m1:;
  }
}
