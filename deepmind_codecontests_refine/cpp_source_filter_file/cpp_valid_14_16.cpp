#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
ostream &operator<<(ostream &cout, pair<A, B> const &p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream &operator<<(ostream &cout, vector<A> const &v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
const long long INF = 1e18;
long long T, n, k, a[2005], pf[2005][2005], dp[2005][2005], v[2005][2005];
void dfs(long long in, long long rem) {
  if (v[in][rem]) return;
  v[in][rem] = 1;
  dp[in][rem] = -INF;
  if (rem > in) return;
  if (in == 0 && rem == 0) {
    dp[in][rem] = pf[0][n];
    return;
  }
  if (!v[in - 1][rem]) dfs(in - 1, rem);
  dp[in][rem] = max(dp[in][rem], dp[in - 1][rem]);
  if (rem == 0) return;
  if (!v[in - 1][rem - 1]) dfs(in - 1, rem - 1);
  dp[in][rem] =
      max(dp[in][rem], dp[in - 1][rem - 1] + (pf[rem][n] - pf[rem][in - 1]) -
                           (pf[rem - 1][n] - pf[rem - 1][in - 1]));
}
void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < n + 2; i++)
    for (int j = 0; j < n + 2; j++) {
      dp[i][j] = -INF;
      pf[i][j] = 0;
      v[i][j] = 0;
    }
  for (int i = 1; i <= n; i++) a[i] = i - a[i];
  for (int i = 1; i <= n; i++) {
    if (a[i] < 0) continue;
    pf[a[i]][i]++;
  }
  for (int i = 0; i < n + 1; i++)
    for (int j = 1; j <= n; j++) pf[i][j] += pf[i][j - 1];
  for (int j = 0; j < n + 1; j++) {
    dfs(n, j);
    if (dp[n][j] >= k) {
      cout << j << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  T = 1;
  cin >> T;
  for (int t = 1; t <= T; t++) solve();
  cout.flush();
  return 0;
}
