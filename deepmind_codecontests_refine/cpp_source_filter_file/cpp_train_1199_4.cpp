#include <bits/stdc++.h>
using namespace std;
bool vis[30];
bool ok(string s, string x) {
  if (x.size() > s.size()) swap(s, x);
  for (int i = 0; i + x.size() - 1 < s.size(); i++) {
    if (s.substr(i, x.size()) == x) return 1;
  }
  return 0;
}
string can(string s, string x) {
  if (s.size() == 0) return x;
  if (x.size() == 0) return s;
  for (int i = 0; i < s.size(); i++) {
    bool cant = 0;
    for (int j = 0; j < x.size(); j++) {
      if (i + j >= s.size()) break;
      if (s[j + i] != x[j]) {
        cant = 1;
        break;
      }
    }
    if (!cant) {
      int len = s.size() - 1 - i + 1;
      string xx;
      for (int j = len; j < x.size(); j++) {
        xx += x[j];
      }
      return s + xx;
    }
  }
  return "-1";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> v, tmp, ans;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    v.push_back(s);
  }
  string cur, prv;
  while (v.size()) {
    if (cur == prv) {
      ans.push_back(cur);
      cur = "";
    }
    prv = cur;
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < v.size(); i++) {
      if (ok(cur, v[i])) vis[i] = 1;
      string a = can(cur, v[i]), b = can(v[i], cur);
      if (a != "-1") {
        cur = a;
        vis[i] = 1;
      } else if (b != "-1") {
        cur = b;
        vis[i] = 1;
      }
    }
    tmp.clear();
    for (int i = 0; i < v.size(); i++) {
      if (!vis[i]) tmp.push_back(v[i]);
    }
    v.clear();
    v = tmp;
  }
  string a = cur;
  for (int i = 0; i < ans.size(); i++) a += ans[i];
  cout << a << endl;
  return 0;
}
