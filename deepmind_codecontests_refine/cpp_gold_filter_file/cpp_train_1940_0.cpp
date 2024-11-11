#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10, mod = 1e9 + 7;
int a[maxn][maxn], dp[2][maxn][maxn];
bool v[2][maxn][maxn];
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }
int go(int e, int l, int r) {
  if (v[e][l][r]) return dp[e][l][r];
  v[e][l][r] = true;
  if (e == 0) {
    if (l == r) return dp[e][l][r] = 1;
    for (int k = l + 1; k <= r; ++k)
      if (a[l][k]) {
        dp[e][l][r] = add(dp[e][l][r], mul(go(1, l, k), go(0, k, r)));
      }
  } else {
    if (l == r) return dp[e][l][r] = 0;
    if (l + 1 == r) return dp[e][l][r] = 1;
    for (int k = l + 1; k < r; ++k)
      if (a[l][k]) {
        dp[e][l][r] = add(dp[e][l][r], mul(go(1, l, k), go(1, k, r)));
      }
    dp[e][l][r] = add(dp[e][l][r], go(0, l + 1, r));
  }
  return dp[e][l][r];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) cin >> a[i][j];
  }
  cout << go(0, 1, n) << endl;
  return 0;
}
