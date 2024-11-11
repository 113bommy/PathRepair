#include <bits/stdc++.h>
using namespace std;
const double eps(1e-8);
set<string> st[55];
int n;
string s[55];
string solve(int n) {
  if (n == 1) return "YES";
  if (n == 2) {
    if (s[2][0] == s[1][0] || s[2][1] == s[1][1]) return "YES";
    return "NO";
  }
  st[n].insert(s[n - 2] + s[n - 1] + s[n]);
  if (n > 3) {
    for (int i = (n); i >= (4); --i) {
      for (set<string>::iterator it = st[i].begin(); it != st[i].end(); it++) {
        string x = *it;
        if (x[2] == x[4] || x[3] == x[5]) {
          string now = "";
          now = now + s[i - 3][0] + s[i - 3][1] + x[0] + x[1] + x[2] + x[3];
          now[4] = x[4];
          now[5] = x[5];
          st[i - 1].insert(now);
        }
        if (x[4] == s[i - 3][0] || x[5] == s[i - 3][1]) {
          string now = "";
          now = now + s[i - 3][0] + s[i - 3][1] + x[0] + x[1] + x[2] + x[3];
          now[0] = x[4];
          now[1] = x[5];
          st[i - 1].insert(now);
        }
      }
    }
  }
  for (set<string>::iterator it = st[3].begin(); it != st[3].end(); it++) {
    string x = *it;
    if ((x[2] == x[4] || x[3] == x[5]) && (x[0] == x[4] || x[1] == x[5])) {
      return "YES";
    }
  }
  return "NO";
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) cin >> s[i];
  cout << solve(n) << endl;
}
