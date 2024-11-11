#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string s[N];
string togo(string a) {
  if (a[0] == '?') a[0] = '1';
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == '?') a[i] = '0';
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  s[0] = togo(s[0]);
  for (int i = 1; i < n; ++i) {
    if (s[i].size() < s[i - 1].size()) {
      cout << "NO" << endl;
      exit(0);
    }
    if (s[i].size() > s[i - 1].size()) {
      s[i] = togo(s[i]);
      continue;
    }
    string res = "no";
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == '?') {
        if (s[i - 1][j] < '9') {
          s[i][j] = s[i - 1][j] + 1;
          res = togo(s[i]);
        }
        s[i][j] = s[i - 1][j];
      } else {
        if (s[i][j] > s[i - 1][j]) {
          res = togo(s[i]);
          break;
        }
        if (s[i][j] < s[i - 1][j]) {
          break;
        }
      }
    }
    if (res == "no") {
      cout << "NO" << endl;
      exit(0);
    } else
      s[i] = res;
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) cout << s[i] << endl;
  return 0;
}
