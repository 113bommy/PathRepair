#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  int k, n;
  cin >> k;
  while (k--) {
    cin >> n;
    cin >> s >> t;
    if (s == t) {
      cout << "YES\n";
    } else {
      vector<int> v;
      for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
          v.push_back(i);
        }
      }
      if (v.size() == 2) swap(s[v[0]], s[v[1]]);
      if (s != t)
        cout << "NO\n";
      else
        cout << "YES\n";
    }
  }
  return 0;
}
