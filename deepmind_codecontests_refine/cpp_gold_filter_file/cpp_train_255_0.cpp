#include <bits/stdc++.h>
using namespace std;
inline void solve();
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}
int dp[1 << 20];
string s[int(25)];
int a[int(25)][int(25)];
int gr[int(25)][int(25)];
int c[int(25)][int(25)];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int mx = 0;
      for (int k = 0; k < n; k++) {
        if (s[i][j] == s[k][j]) {
          c[i][j] += a[k][j];
          mx = max(mx, a[k][j]);
          gr[i][j] |= (1 << k);
        }
      }
      c[i][j] -= mx;
    }
  for (int i = 1; i < (1 << n); i++) dp[i] = int(1e9);
  for (int mask = 1; mask < (1 << n); mask++) {
    int i = -1;
    for (int j = 0; j < n; j++)
      if ((mask >> j) & 1) {
        i = j;
        break;
      }
    for (int j = 0; j < m; j++) {
      dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + a[i][j]);
      dp[mask] = min(dp[mask], dp[mask & (mask ^ gr[i][j])] + c[i][j]);
    }
  }
  cout << dp[(1 << n) - 1];
}
