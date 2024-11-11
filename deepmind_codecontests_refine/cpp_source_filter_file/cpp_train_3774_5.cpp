#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int n, m;
vector<string> s;
void create_sample(vector<string> &chk, string s1, string s2) {
  vector<int> ind;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) ind.push_back(i);
  }
  if (ind.size() > 2) return;
  if (ind.size() == 1) {
    for (int i = 0; i < 26; i++) {
      s1[ind.back()] = 'a' + i;
      chk.push_back(s1);
    }
    return;
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      s1[ind.front()] = 'a' + i;
      s1[ind.back()] = 'a' + j;
      chk.push_back(s1);
    }
  }
  return;
}
bool check(string &s1, string &s2) {
  int cnt = 0;
  for (int i = 0; i < s1.size(); i++) {
    if (s1[i] != s2[i]) cnt++;
  }
  return cnt <= 1;
}
void solve() {
  cin >> n >> m;
  s.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  if (n == 1) {
    cout << s[0] << '\n';
    return;
  }
  vector<string> chk;
  string s1 = "-1", s2 = "-1";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] != s[j]) s1 = s[i], s2 = s[j];
    }
  }
  if (s1 == "-1") {
    cout << s1 << '\n';
    return;
  }
  create_sample(chk, s1, s2);
  if (chk.empty()) {
    cout << "-1\n";
    return;
  }
  for (auto x : chk) {
    bool can = 1;
    for (auto y : s) {
      can &= check(x, y);
    }
    if (can) {
      cout << x << '\n';
      return;
    }
  }
  cout << "-1\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
