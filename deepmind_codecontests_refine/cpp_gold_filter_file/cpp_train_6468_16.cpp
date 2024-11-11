#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, a[maxn];
long long cost[maxn], dp[maxn][maxn][maxn], F[maxn][maxn];
long long L[maxn];
string s;
void readf() {
  cin >> n >> s;
  s = " " + s;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  cost[0] = 0;
  for (int i = (1); i <= (n); ++i) {
    cost[i] = a[i];
    for (int j = (1); j <= (i); ++j) cost[i] = max(cost[i], cost[i - j] + a[j]);
  }
}
void solve() {
  memset(dp, -0x3f, sizeof(dp));
  memset(F, -0x3f, sizeof(F));
  for (int i = n; i > 0; --i)
    for (int j = i; j <= n; ++j)
      if (s[i] == s[j]) {
        char c = s[i];
        if (i == j) {
          dp[i][j][1] = 0;
          F[i][j] = cost[1];
          continue;
        }
        for (int t = i; t < j; ++t)
          if (s[t] == c)
            for (int k = 1; k <= j - i + 1; ++k)
              if (dp[i][t][k - 1] >= 0) {
                dp[i][j][k] =
                    max(dp[i][j][k],
                        dp[i][t][k - 1] + F[t + 1][j - 1] * (t + 2 <= j));
                F[i][j] = max(F[i][j], dp[i][j][k] + cost[k]);
              }
        for (int t = i; t < j; ++t)
          F[i][j] = max(F[i][j], F[i][t] + F[t + 1][j]);
      }
  memset(L, -0x3f, sizeof(L));
  L[0] = 0;
  for (int i = (1); i <= (n); ++i)
    for (int j = (0); j < (i); ++j) L[i] = max(L[i], L[j] + F[j + 1][i]);
  cout << L[n] << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readf();
  solve();
}
