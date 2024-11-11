#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  register int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    int m;
    cin >> m;
    for (register int i = 0; i < m; ++i) {
      cin >> a[i];
    }
    int b[50] = {0}, c[50] = {0};
    for (int i = 0; i < s.length(); ++i) {
      ++b[s[i] - 'a'];
    }
    bool vis[110] = {false};
    string t = s.substr(0, m);
    char cc = 'z';
    vector<int> v[30];
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        if (vis[j]) continue;
        if (!a[j]) {
          vis[j] = true;
          v[cc - 'a'].push_back(j);
          ++c[cc - 'a'];
        }
      }
      for (int j = 0; j < m; ++j) {
        if (vis[j]) continue;
        for (int k = 0; k < v[cc - 'a'].size(); ++k) {
          a[j] -= abs(j - v[cc - 'a'][k]);
        }
      }
      cc = cc - 1;
    }
    int cnt = 'z' - 'a' + 1;
    for (int i = 'z' - 'a'; i >= 0; --i) {
      if (!v[i].size()) continue;
      for (int j = cnt - 1; j >= 0; --j) {
        if (c[i] <= b[j]) {
          cnt = j;
          break;
        }
      }
      for (int j = 0; j < v[i].size(); ++j) {
        t[v[i][j]] = cnt + 'a';
      }
    }
    cout << t << '\n';
  }
  return 0;
}
