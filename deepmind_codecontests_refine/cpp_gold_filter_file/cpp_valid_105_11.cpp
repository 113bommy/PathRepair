#include <bits/stdc++.h>
using namespace std;
const int N = 3003, mod = 1e9 + 7;
int n, a[N], dp[N][N], f[N][N];
vector<int> s[N];
void Main() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) s[i].clear();
  for (int i = (1); i <= (n); ++i) cin >> a[i], s[a[i]].push_back(i);
  for (int i = (1); i <= (n); ++i)
    for (int j = (i); j <= (n); ++j) dp[i][j] = f[i][j] = 1e9;
  for (int i = (1); i <= (n); ++i)
    for (int j = i; j <= n && a[j] == a[i]; j += 1) dp[i][j] = f[i][j] = 0;
  for (int len = (2); len <= (n); ++len)
    for (int l = (1); l <= (n - len + 1); ++l) {
      int r = l + len - 1;
      dp[l][r] = dp[l][r - 1] + (a[r] != a[r - 1]);
      for (const int &t : s[a[r]])
        if (l <= t && t < r) f[l][r] = min(f[l][r], f[l][t] + f[t + 1][r]);
      dp[l][r] = min(dp[l][r], f[l][r]);
      f[l][r] = min(f[l][r], dp[l][r - 1] + (a[r] != a[r - 1]));
    }
  int ns = dp[1][n];
  for (int i = (1); i <= (n); ++i) ns = min(ns, f[1][i] + dp[i + 1][n] + 1);
  cout << ns << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) Main();
  return 0;
}
