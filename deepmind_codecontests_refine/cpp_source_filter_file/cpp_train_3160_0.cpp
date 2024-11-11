#include <bits/stdc++.h>
using namespace std;
const int M = 110;
const int N = 1010;
int n, m, k;
vector<string> a[N];
map<string, string> mp;
string get_line() {
  string s;
  char buf[M] = {};
  cin.getline(buf, M, '\n');
  return s = buf;
}
vector<string> split() {
  string s = get_line();
  for (int i = 0; i < int(s.size()); ++i)
    if (s[i] == '(' || s[i] == ')' || s[i] == ',') s[i] = ' ';
  istringstream in(s);
  vector<string> out;
  while (in >> s) out.push_back(s);
  return out;
}
int good(int n, vector<string> v) {
  if (v.size() != a[n].size()) return 0;
  if (v[0] != a[n][0]) return 0;
  for (int i = 1; i < int(v.size()); ++i)
    if (a[n][i] != "T" && a[n][i] != mp[v[i]]) return 0;
  return 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  cin.get();
  for (int i = 1; i <= n; ++i) {
    vector<string> v = split();
    for (int j = 1; j < int(v.size()); ++j) {
      a[i].push_back(v[j]);
    }
  }
  cin >> m;
  cin.get();
  for (int i = 1; i <= m; ++i) {
    vector<string> v = split();
    mp[v[1]] = v[0];
  }
  cin >> k;
  cin.get();
  while (k--) {
    vector<string> v = split();
    int ans = 0;
    for (int i = 0; i < n; ++i)
      if (good(i, v)) ans++;
    cout << ans << '\n';
  }
}
