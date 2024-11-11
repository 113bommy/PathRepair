#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000007;
const long long int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const long long int maxn = 42;
long long int n, t, T[maxn];
string Ts;
long long int first[maxn];
long long int nxt[maxn][2];
long long int dp[maxn][maxn];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> Ts;
  t = Ts.size();
  for (long long int i = 0; i < t; ++i) T[i] = Ts[i] - '0';
  for (long long int i = 0; i < t; ++i) {
    first[i + 1] = nxt[first[i]][T[i]];
    nxt[i][T[i]] = i + 1;
    nxt[i][T[i] ^ 1] = nxt[first[i]][T[i] ^ 1];
  }
  long long int ans = 1 << n;
  for (long long int k = 0; k < t; ++k) {
    memset(dp, 0, sizeof dp);
    dp[0][k] = 1;
    for (long long int i = 0; i < n; ++i) {
      for (long long int j = 0; j < t; ++j) {
        dp[i + 1][nxt[j][0]] += dp[i][j];
        dp[i + 1][nxt[j][1]] += dp[i][j];
      }
    }
    ans -= dp[n][k];
  }
  cout << ans << '\n';
}
