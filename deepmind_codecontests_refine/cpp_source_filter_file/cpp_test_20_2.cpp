#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmax(T& a, const T& b) {
  a = max(a, b);
}
template <class T>
void chmin(T& a, const T& b) {
  a = min(a, b);
}
using ll = long long;
using P = pair<int, int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;
int dp[6][410][410];
int d[410];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    for (int k = 0; k < int(5); ++k)
      for (int i = 0; i < int(n + 1); ++i)
        for (int j = 0; j < int(m + 1); ++j) dp[k][i][j] = 100;
    int ans = 100;
    for (int _ = 0; _ < int(n); ++_) {
      for (int j = 0; j < int(m); ++j) {
        char c;
        cin >> c;
        d[j + 1] = c - '0';
      }
      for (int j = 0; j < int(m); ++j) d[j + 1] += d[j];
      for (int k = int(5) - 1; k >= 0; --k)
        for (int r = 0; r < int(m + 1); ++r)
          for (int l = int(r - 4 + 1) - 1; l >= 0; --l) {
            if (k == 0 || k == 4) {
              int x = r - 1 - (l + 1) - (d[r - 1] - d[l + 1]);
              if (k == 4) {
                chmin(ans, x + dp[k][l][r]);
                dp[k][l][r] += d[r - 1] - d[l + 1] + 1 - (d[l + 1] - d[l]) + 1 -
                               (d[r] - d[r - 1]);
              } else {
                dp[1][l][r] = x;
              }
            } else {
              int x = d[r - 1] - d[l + 1] + 1 - (d[l + 1] - d[l]) + 1 -
                      (d[r] - d[r - 1]);
              if (k < 3) {
                dp[k + 1][l][r] = dp[k][l][r] + x;
              } else {
                chmin(dp[k + 1][l][r], dp[k][l][r] + x);
              }
            }
          }
    }
    cout << ans << '\n';
  }
}
