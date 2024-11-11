#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;
const int N = 102;
int n, m, c[N][N], a[2 * N], ans[2 * N];
ll dp[2 * N][N], K;
ll calWays(int p, int bal) {
  if (p == 0) return (bal == 0);
  ll& res = dp[p][bal];
  if (res != -1) return res;
  res = 0;
  if (bal > 0 && (ans[p] == -1 || ans[p] == 0)) res += calWays(p - 1, bal - 1);
  if (bal < (n + m - 1) / 2 && (ans[p] == -1 || ans[p] == 1))
    res += calWays(p - 1, bal + 1);
  return min(K + 1, res);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> K;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) cin >> c[i][j];
  for (int i = (1); i <= (n + m - 1); ++i) a[i] = 1e9, ans[i] = -1;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (m); ++j) a[i + j - 1] = min(a[i + j - 1], c[i][j]);
  for (int t = (1); t <= (n + m - 1); ++t) {
    int mn = 1e9, mni = 0;
    for (int i = (1); i <= (n + m - 1); ++i)
      if (ans[i] == -1 && mn > a[i]) mn = a[i], mni = i;
    ans[mni] = 0;
    for (int i = (0); i <= (n + m - 1); ++i)
      for (int bal = (0); bal <= ((n + m) / 2); ++bal) dp[i][bal] = -1;
    ll ways = calWays(n + m - 1, 0);
    if (ways < K) {
      K -= ways;
      ans[mni] = 1;
    }
  }
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) cout << (ans[i + j - 1] ? ')' : '(');
    if (i < n) cout << '\n';
  }
  return 0;
}
