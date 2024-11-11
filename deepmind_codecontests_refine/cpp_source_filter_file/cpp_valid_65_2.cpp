#include <bits/stdc++.h>
using namespace std;
const int INF_MAX = 1 << 30;
const double INF_MIN = 1e-6;
const int MAX_N = 50 + 5;
const int MAX_M = 100000 + 5;
const long long int MOD = 998244353;
const double PI = acos(-1.0);
const double E = exp(1.0);
long long int n, m;
long long int l[MAX_N];
long long int r[MAX_N];
long long int vis[MAX_M];
long long int prime[MAX_M];
long long int mu[MAX_M];
long long int dp[MAX_N][MAX_M];
long long int dSum[MAX_N][MAX_M];
void prepare() {
  memset(vis, 0, sizeof(vis));
  mu[1] = 1;
  int cnt = 0;
  for (int i = 2; i < MAX_M; i++) {
    if (!vis[i]) {
      prime[cnt++] = i;
      mu[i] = -1;
    }
    for (int j = 0; j < cnt && i * prime[j] < MAX_M; j++) {
      vis[i * prime[j]] = 1;
      if (i % prime[j]) {
        mu[i * prime[j]] = -mu[i];
      } else {
        mu[i * prime[j]] = 0;
        break;
      }
    }
  }
}
void init() {}
void input() {
  scanf("%lld%lld", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &l[i], &r[i]);
  }
}
long long int calDp(int d) {
  for (int j = 0; j <= m / d; j++) {
    dSum[0][j] = j + 1;
  }
  for (int i = 1; i <= n; i++) {
    long long int li = (l[i] % d == 0) ? l[i] / d : l[i] / d + 1, ri = r[i] / d;
    dSum[i][0] = (li == 0);
    for (int j = 1; j <= m / d; j++) {
      if (li > ri) {
        dp[i][j] = 0;
      } else {
        int s = j - ri, e = j - li;
        dp[i][j] = ((e >= 0) ? dSum[i - 1][e] : 0) -
                   ((s - 1 >= 0) ? dSum[i - 1][s - 1] : 0);
        dp[i][j] = (dp[i][j] + MOD) % MOD;
      }
      dSum[i][j] = (dSum[i][j - 1] + dp[i][j]) % MOD;
    }
  }
  return dp[n][m / d];
}
void solve() {
  long long int ans = 0;
  for (int d = 1; d <= m; d++) {
    long long int fd = calDp(d);
    ans = (ans + (mu[d] * fd) % MOD) % MOD;
  }
  printf("%lld\n", ans);
}
int main() {
  ios::sync_with_stdio(false);
  prepare();
  int t;
  t = 1;
  while (t--) {
    init();
    input();
    solve();
  }
  return 0;
}
