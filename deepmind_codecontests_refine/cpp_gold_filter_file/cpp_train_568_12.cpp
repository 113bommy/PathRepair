#include <bits/stdc++.h>
using namespace std;
long long t, n, m, u, v, q, r, ql, qr, k, l, s, x, y, w, h, c, z, d;
const int N = 22;
const long long mod = 1e9 + 7;
const long long INF = 1LL << 62LL;
const bool JUDGE = false;
int dp[1 << N];
string str[N];
int hset[N][N];
int cset[N][N];
int a[N][N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (JUDGE) {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
  }
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> str[i];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) cin >> a[i][j];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cset[i][j] = 0;
      int maxc = 0;
      for (int k = 0; k < n; ++k) {
        if (str[i][j] == str[k][j]) {
          hset[i][j] |= (1 << k);
          cset[i][j] += a[k][j];
          maxc = max(maxc, a[k][j]);
        }
      }
      cset[i][j] -= maxc;
    }
  for (int i = 0; i < (1 << n); ++i) dp[i] = 100000000;
  dp[0] = 0;
  for (int i = 1; i < (1 << n); ++i) {
    int k = 0;
    while ((1 << k) != (i & -i)) k++;
    for (int j = 0; j < m; ++j) {
      dp[i] = min(dp[i], dp[(i ^ (1 << k))] + a[k][j]);
      dp[i] = min(dp[i], dp[(i ^ hset[k][j]) & i] + cset[k][j]);
    }
  }
  cout << dp[(1 << n) - 1] << '\n';
  return 0;
}
