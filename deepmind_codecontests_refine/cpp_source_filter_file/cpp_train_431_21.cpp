#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
class {
 public:
  void solve() {
    int t;
    cin >> t;
    while (t--) {
      int n, m;
      cin >> n >> m;
      vector<int> f(3 * n + 3);
      vector<int> ans;
      for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        if (f[v] == 0 && f[u] == 0) {
          ans.push_back(i);
          f[v] = f[u] = 0;
        }
      }
      if (ans.size() >= n) {
        cout << "Matching\n";
        for (int i = 0; i < n; ++i) cout << ans[i] << " ";
        cout << "\n";
      } else {
        cout << "IndSet\n";
        int count = n;
        for (int i = 1; i <= 3 * n; i++) {
          if (!f[i] && count) {
            cout << i << " ";
            count--;
          }
        }
        cout << "\n";
      }
    }
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
