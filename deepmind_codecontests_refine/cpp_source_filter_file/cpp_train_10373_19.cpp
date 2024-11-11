#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, MOD = 1e9 + 7, MN = 110;
int n, m;
string s[MN];
int c[MN][MN], dp[MN], col[MN];
void ok(int &x) {
  if (x >= MOD) x -= MOD;
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> m >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int i = 0; i < m; ++i) col[i] = s[0][i] - '0';
  for (int rp = 1; rp < n; ++rp) {
    map<pair<int, int>, int> mp;
    int sz = 0;
    for (int i = 0; i < m; ++i) {
      pair<int, int> X = {col[i], s[rp][i] - '0'};
      if (!mp.count(X)) mp[X] = sz++;
    }
    for (int i = 0; i < m; ++i) col[i] = mp[make_pair(col[i], s[rp][i] - '0')];
  }
  c[0][0] = 1;
  for (int i = 1; i < MN; ++i)
    for (int j = 0; j <= i; ++j)
      if (j == 0)
        c[i][j] = 1;
      else
        c[i][j] = c[i - 1][j] + c[i - 1][j - 1], ok(c[i][j]);
  dp[0] = dp[1] = 1;
  for (int i = 2; i < MN; ++i)
    for (int j = 0; j < i; j++)
      dp[i] += 1ll * c[i - 1][j] * dp[j] % MOD, ok(dp[i]);
  int ans = 1;
  for (int i = 0; i < m + 5; ++i) {
    int cnt = 0;
    for (int j = 0; j < m; ++j)
      if (col[j] == i) ++cnt;
    ans = 1ll * ans * dp[cnt] % MOD;
  }
  cout << ans << '\n';
  return 0;
}
