#include <bits/stdc++.h>
using namespace std;
void GO() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
const int INF = int(1e9 + 7);
const int mod = 998244353;
const int MAX_N = (int)1e6 + 200000;
void solve() {
  int n, m;
  cin >> n >> m;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int a;
      cin >> a;
      mp[a] = j;
    }
  }
  vector<vector<int> > ans(m);
  for (int i = 0; i < m; ++i) {
    int ind = 0;
    vector<int> mas(n);
    for (int j = 0; j < n; ++j) {
      cin >> mas[j];
      ind = mp[mas[j]];
    }
    ans[ind] = mas;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << ans[j][i] << ' ';
    }
    cout << '\n';
  }
}
signed main() {
  GO();
  int Q = 1;
  cin >> Q;
  while (Q--) solve();
  return 0;
}
