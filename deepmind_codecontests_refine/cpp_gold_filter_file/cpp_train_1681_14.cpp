#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using ld = double;
const ld EPS = 1e-9;
const ll MOD = 1e6 + 3;
const ld PI = 3.141592653589793;
const int maxn = 5e5 + 100;
template <typename ForwardIter, typename Callback>
void forn(ForwardIter arr, int n, Callback c) {
  int z = 1;
  for (auto x = arr; z <= n; ++z, ++x) {
    c(*x);
  }
}
vector<int> rows[1001];
vector<int> cols[1001];
int a[1001][1011];
signed main() {
  ios_base::sync_with_stdio(false);
  cout.precision(10);
  cout << fixed;
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      rows[i].push_back(a[i][j]);
    }
    sort(rows[i].begin(), rows[i].end());
    rows[i].erase(unique(rows[i].begin(), rows[i].end()), rows[i].end());
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = 1; i <= n; ++i) {
      cols[j].push_back(a[i][j]);
    }
    sort(cols[j].begin(), cols[j].end());
    cols[j].erase(unique(cols[j].begin(), cols[j].end()), cols[j].end());
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int f1 = lower_bound(rows[i].begin(), rows[i].end(), a[i][j]) -
               rows[i].begin(),
          f2 = lower_bound(cols[j].begin(), cols[j].end(), a[i][j]) -
               cols[j].begin();
      int f = max(f1, f2);
      int ans = max(f + rows[i].size() - f1, f + cols[j].size() - f2);
      cout << ans << " ";
    }
    cout << "\n";
  }
}
