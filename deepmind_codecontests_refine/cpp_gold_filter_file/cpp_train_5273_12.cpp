#include <bits/stdc++.h>
using namespace std;
bool isSame(string &s, string &t) {
  if (s.size() != t.size()) return false;
  vector<char> bad = {'1', 'l', 'i'};
  map<char, set<char>> mp = {{'0', {'o'}}, {'o', {'0'}}};
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      mp[bad[i]].insert(bad[j]);
    }
  }
  int cnt = 0;
  for (int i = 0; i < t.size(); i++) {
    char x = tolower(s[i]), y = tolower(t[i]);
    if (mp[x].count(y) == 1 || x == y) {
      cnt++;
    }
  }
  return cnt == s.size();
}
void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    string t;
    cin >> t;
    if (isSame(s, t)) {
      ok = false;
    }
  }
  cout << (ok ? "Yes" : "No");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
}
