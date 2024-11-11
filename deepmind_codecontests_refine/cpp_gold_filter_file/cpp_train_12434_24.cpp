#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 7;
int n, m, s, e;
int a[MAXN], b[MAXN];
int dp[310][MAXN];
vector<int> v[MAXN];
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n >> m >> s >> e;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 1; i < m + 1; i++) {
    cin >> b[i];
    v[b[i]].push_back(i);
  }
  for (int i = 0; i < MAXN; i++) v[i].push_back(INF);
  memset(dp, 0x3f, sizeof(dp));
  memset(dp[0], 0, sizeof(dp[0]));
  int ans = 0;
  for (int i = 1; i < s / e + 1; i++)
    for (int j = 1; j < n + 1; j++)
      if (dp[i - 1][j - 1] != INF) {
        dp[i][j] = dp[i][j - 1];
        int k = *lower_bound((v[a[j]]).begin(), (v[a[j]]).end(),
                             dp[i - 1][j - 1] + 1);
        if (k == INF) continue;
        dp[i][j] = min(dp[i][j], k);
        if (dp[i][j] + j + i * e <= s) ans = max(ans, i);
      }
  cout << ans << endl;
  return 0;
}
