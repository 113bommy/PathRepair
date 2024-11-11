#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fll;
const int N = 1e5 + 10;
const int M = 10 + 10;
const int mod = 998244353;
const double eps = 1e-10;
const double pi = acos(-1.0);
int n, p, m;
int a[N], cnt[1 << 7];
int s[N][10], r[N];
long long dp[N][1 << 7];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> p >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], r[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < p; j++) cin >> s[i][j];
  }
  for (int i = 0; i < (1 << p); i++) {
    int t = i;
    while (t) {
      if (t & 1) cnt[i]++;
      t >>= 1;
    }
  }
  sort(r + 1, r + 1 + n, cmp);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    int id = r[i];
    for (int j = 0; j < (1 << p); j++) {
      long long &t = dp[i][j];
      if (~dp[i - 1][j]) {
        t = dp[i - 1][j];
        if (i - cnt[j] <= m) t += a[id];
      }
      for (int k = 0; k < p; k++)
        if (j >> k & 1 && ~dp[i - 1][j ^ (1 << k)]) {
          t = max(t, dp[i - 1][j ^ (1 << k)] + s[id][k]);
        }
    }
  }
  cout << dp[n][(1 << p) - 1] << '\n';
  return 0;
}
