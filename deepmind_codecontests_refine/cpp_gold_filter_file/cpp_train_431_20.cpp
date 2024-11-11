#include <bits/stdc++.h>
using namespace std;
int T, n, m, u, v;
set<int> s, bad;
vector<int> ans;
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> T;
  for (long long int t = 1; t <= T; ++t) {
    cin >> n >> m;
    for (long long int i = 1; i <= m; ++i) {
      cin >> u >> v;
      if (s.find(u) == s.end() && s.find(v) == s.end()) {
        s.insert(u);
        s.insert(v);
        ans.push_back(i);
      }
    }
    if (s.size() >= 2 * n) {
      cout << "Matching\n";
      for (long long int i = 1; i <= n; ++i) {
        cout << ans[i - 1] << " ";
      }
    } else {
      cout << "IndSet\n";
      int cnt = 0;
      for (long long int i = 1; i <= n * 3; ++i) {
        if (s.find(i) == s.end()) {
          cout << i << " ";
          ++cnt;
          if (cnt == n) break;
        }
      }
    }
    cout << '\n';
    s.clear();
    ans.clear();
  }
}
