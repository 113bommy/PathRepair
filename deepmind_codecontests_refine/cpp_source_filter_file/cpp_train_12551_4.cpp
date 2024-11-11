#include <bits/stdc++.h>
using namespace std;
template <typename A, typename B>
inline void chmin(A &a, B b) {
  if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A &a, B b) {
  if (a < b) a = b;
}
const long long mod = 1000000007;
inline void add(long long &a, long long b) {
  a += b;
  if (a >= mod) a -= mod;
}
long long N, K;
vector<long long> G[111];
long long dp[111][21][21];
long long tmp[21][21];
void dfs(long long v, long long p) {
  dp[v][0][0] = 1;
  dp[v][K][1] = 1;
  for (auto u : G[v]) {
    if (u == p) continue;
    dfs(u, v);
    memset(tmp, 0, sizeof(tmp));
    for (long long i = 0; i <= K; i++) {
      for (long long j = 0; j <= K; j++) {
        for (long long k = 0; k <= K; k++) {
          for (long long l = 0; l <= K; l++) {
            long long t = 0;
            if (i + l > K) chmax(t, l + 1);
            if (j + k > K) chmax(t, k);
            if (t > K) continue;
            long long s = min(i, k + 1);
            add(tmp[s][t], dp[v][i][j] * dp[u][k][l] % mod);
          }
        }
      }
    }
    for (long long i = 0; i < (K + 1); i++)
      for (long long j = 0; j < (K + 1); j++) dp[v][i][j] = tmp[i][j];
  }
}
signed main() {
  cin >> N >> K;
  for (long long i = 0; i < (N - 1); i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0, -1);
  long long ans = 0;
  for (long long i = 0; i < (K + 1); i++) add(ans, dp[0][i][0]);
  cout << ans << endl;
  return 0;
}
