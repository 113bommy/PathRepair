#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
double pi = 3.1415926535898;
const long long M = 1e9 + 7;
const int inf = 2e9 + 7;
const double EPS = 1e-9;
string ys = "YES\n";
string no = "NO\n";
string s, t;
int fs[50];
int ft[50];
map<char, int> ans;
int q = 0;
bool ok(int x) {
  int qq = q;
  for (int i = 0; i <= int(25); ++i) {
    if (!ft[i]) continue;
    qq -= max(0, ft[i] * x - fs[i]);
  }
  return qq >= 0;
}
int main() {
  cin >> s >> t;
  if (int(t.size()) >= int(s.size())) {
    for (char &c : s) {
      if (c == '?') c = 'a';
    }
    cout << s << endl;
    return 0;
  }
  for (char &c : s) {
    if (c == '?')
      q++;
    else
      fs[c - 'a']++;
  }
  for (char &c : t) {
    ft[c - 'a']++;
  }
  int lo = 0;
  int hi = int(s.size()) / int(t.size());
  int md = 0;
  while (lo < hi) {
    md = (lo + hi + 1) / 2;
    if (ok(md))
      lo = md;
    else
      hi = md - 1;
  }
  for (int i = 0; i <= int(25); ++i) {
    if (ft[i]) {
      int tmp = max(0, ft[i] * lo - fs[i]);
      if (tmp) ans[i + 'a'] = tmp;
    }
  }
  for (char &c : s) {
    if (c == '?') {
      bool ook = 0;
      for (auto &x : ans) {
        if (x.second > 0) {
          c = x.first;
          x.second--;
          ook = 1;
          break;
        }
      }
      if (!ook) {
        c = 'a';
      }
    }
  }
  cout << s;
  return 0;
}
