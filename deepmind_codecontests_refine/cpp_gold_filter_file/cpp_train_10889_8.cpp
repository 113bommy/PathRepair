#include <bits/stdc++.h>
using namespace std;
inline void smax(int &x, int y) { x = max(x, y); }
inline void smin(int &x, int y) { x = min(x, y); }
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%I64d", &x);
  return x;
}
inline void out(int x) { printf("%d ", x); }
inline void lout(long long x) { printf("%I64d ", x); }
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;
const int N = 1e3 + 10;
const int maxn = 1e4 + 10;
const int MAXN = 1e5 + 10;
const int MN = 1e6 + 10;
int a[110][110], mn[2][110], n, m, mx[110];
vector<pair<string, int> > vec;
void solve() {
  fill_n(mn[0], 2 * 110, INF);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) smin(mn[0][i], a[i][j]);
  for (int j = 1; j <= m; j++)
    for (int i = 1; i <= n; i++) smin(mn[1][j], a[i][j]);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j];
  solve();
  if (n < m) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < mn[0][i]; j++) vec.push_back({"row", i});
      for (int j = 1; j <= m; j++) a[i][j] -= mn[0][i];
    }
    solve();
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < mn[1][i]; j++) vec.push_back({"col", i});
      for (int j = 1; j <= n; j++) a[j][i] -= mn[1][i];
    }
  } else {
    for (int i = 1; i <= m; i++) {
      for (int j = 0; j < mn[1][i]; j++) vec.push_back({"col", i});
      for (int j = 1; j <= n; j++) a[j][i] -= mn[1][i];
    }
    solve();
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < mn[0][i]; j++) vec.push_back({"row", i});
      for (int j = 1; j <= m; j++) a[i][j] -= mn[0][i];
    }
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j] != 0) return cout << -1, 0;
  cout << vec.size() << "\n";
  for (auto x : vec) cout << x.first << ' ' << x.second << "\n";
}
