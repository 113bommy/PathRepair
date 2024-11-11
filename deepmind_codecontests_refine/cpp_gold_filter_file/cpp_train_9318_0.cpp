#include <bits/stdc++.h>
using namespace std;
const int N = 5010, mod = 1e9 + 7;
int n, k, ans, dp[N][N], sm[N][N], p[N], h[N];
string s;
int hash__(int l, int r) { return h[r] - h[l - 1] * p[r - l]; }
bool f(int i1, int i2, int len) {
  int l = 0, r = len + 1;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (hash__(i1, i1 + m - 1) == hash__(i2, i2 + m - 1))
      l = m;
    else
      r = m;
  }
  if (l == len) return 0;
  return s[i1 + l] < s[i2 + l];
}
int main() {
  cin >> n >> s;
  s = '0' + s;
  p[0] = 113;
  for (int i = 1; i < N; ++i) p[i] = p[0] * p[i - 1];
  for (int i = 1; i <= n; ++i) h[i] = h[i - 1] * p[0] + s[i];
  dp[0][0] = sm[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (s[i - j + 1] == '0') continue;
      if (j > i - j)
        k = i - j;
      else
        k = j - 1 + f(i - j - j + 1, i - j + 1, j);
      dp[i][j] = sm[i - j][k];
    }
    for (int j = 1; j <= i; ++j) sm[i][j] = (sm[i][j - 1] + dp[i][j]) % mod;
  }
  ans = sm[n][n];
  cout << ans << '\n';
  return 0;
}
