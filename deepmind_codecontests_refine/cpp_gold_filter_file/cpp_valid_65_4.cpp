#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[55];
long long dp[55][100005], res[100005] = {0}, s[100005];
inline void solve(int x) {
  int g = m / x;
  pair<int, int> b[55];
  for (int i = 1; i <= n; i++) {
    if (a[i].first % x == 0)
      b[i].first = a[i].first / x;
    else
      b[i].first = a[i].first / x + 1;
    b[i].second = a[i].second / x;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= g; j++) dp[i][j] = 0;
  }
  for (int i = 1; i <= g; i++) s[i] = 0;
  for (int i = b[1].first; i <= b[1].second; i++) dp[1][i] = 1;
  for (int i = 1; i <= n; i++) {
    s[0] = 0;
    for (int k = 1; k <= g; k++) {
      int r = min(b[i].second, k), l = b[i].first;
      if (r < l) continue;
      dp[i][k] = (dp[i][k] + s[k - l] - s[k - r - 1]) % (long long)(998244353);
    }
    for (int k = 1; k <= g; k++) {
      s[k] = (s[k - 1] + dp[i][k]) % (long long)(998244353);
    }
  }
  res[x] = s[g];
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int l, r;
    cin >> l >> r;
    a[i] = {l, r};
  }
  for (int i = 1; i <= m; i++) {
    solve(i);
  }
  for (int i = m; i >= 1; i--) {
    for (int j = 2 * i; j <= m; j += i) {
      res[i] -= res[j];
      res[i] = (res[i] + (long long)(998244353)) % (long long)(998244353);
    }
  }
  cout << res[1];
}
