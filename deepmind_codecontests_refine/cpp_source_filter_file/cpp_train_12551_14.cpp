#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long BIG = 1446803456761533460;
const int Big = 336860180;
stringstream sss;
const long long int maxn = 110;
const long long int maxk = 23;
long long int n, K;
long long int dp[maxn][maxk][maxk], tdp[maxk][maxk];
vector<long long int> g[maxn];
void dfs(long long int x, long long int par) {
  dp[x][0][K] = 1;
  dp[x][K][0] = 1;
  for (auto y : g[x]) {
    if (y == par) continue;
    dfs(y, x);
    memcpy(tdp, dp[x], sizeof tdp);
    memset(dp[x], 0, sizeof dp[x]);
    for (long long int i1 = (0); i1 < (K + 1); ++i1) {
      for (long long int j1 = (0); j1 < (K + 1); ++j1) {
        for (long long int i2 = (0); i2 < (K + 1); ++i2) {
          for (long long int j2 = (0); j2 < (K + 1); ++j2) {
            long long int i3 = min(K, min(i1, i2 + 1));
            long long int f1 = j1 == K || j1 + i2 + 1 <= K;
            long long int f2 = j2 == K || j2 + i1 + 1 <= K;
            long long int j3 = -1;
            if (f1 && f2)
              j3 = K;
            else if (f2)
              j3 = j1;
            else if (f1 && j2 + 1 < K)
              j3 = j1;
            else if (j2 + 1 < K)
              j3 = max(j1, j2 + 1);
            if (j3 != -1)
              dp[x][i3][j3] =
                  (dp[x][i3][j3] + (tdp[i1][j1] * dp[y][i2][j2])) % MOD;
          }
        }
      }
    }
  }
}
void MAIN() {
  cin >> n >> K;
  for (long long int i = (0); i < (n - 1); ++i) {
    long long int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].emplace_back(b), g[b].emplace_back(a);
  }
  dfs(0, 0);
  long long int ans = 0;
  for (long long int i = (0); i < (K + 1); ++i) {
    ans = (ans + (dp[0][i][K])) % MOD;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  sss << R"(
7 2
1 2
2 3
1 4
4 5
1 6
6 7
    )";
  MAIN();
  return 0;
}
