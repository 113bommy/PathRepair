#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  while (k--) {
    int n, i, j;
    string s, t;
    cin >> n >> s >> t;
    vector<pair<int, int> > v;
    for (i = 0; i < n; i++) {
      if (s[i] == t[i]) continue;
      for (j = i + 1; j < n; j++) {
        if (s[i] == s[j]) {
          swap(t[i], s[j]);
          v.push_back({j, i});
          break;
        }
        if (s[i] == t[j]) {
          swap(s[i], t[i]);
          v.push_back({i, i});
          swap(s[i], t[j]);
          v.push_back({i, j});
          break;
        }
      }
      if (j == n) break;
    }
    if (i != n)
      cout << "NO\n";
    else {
      cout << "YES\n" << v.size() << endl;
      for (i = 0; i < v.size(); i++) {
        cout << v[i].first + 1 << ' ' << v[i].second + 1 << endl;
      }
    }
  }
}
