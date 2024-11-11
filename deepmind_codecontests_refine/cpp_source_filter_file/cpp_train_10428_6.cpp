#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
const double esp = 1e-8;
const int mod = 998244353;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int maxm = 1e6 + 5;
int a[maxn], n, k;
int dp[maxn][maxn], tsum[maxn][maxn];
int bound[maxn];
inline int add(int x, int y) {
  return (x + y) >= mod ? (x + y - mod) : (x + y);
}
int solve(int x) {
  bound[0] = 0;
  for (int i = 1; i <= n; i++) {
    bound[i] = bound[i - 1];
    if (a[i] - a[bound[i] + 1] >= x) bound[i]++;
  }
  tsum[1][0] = 0;
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= n; j++) {
      if (i == 1) {
        dp[i][j] = 1;
        tsum[i][j] = (tsum[i][j - 1] + dp[i][j]);
        continue;
      }
      dp[i][j] = tsum[i - 1][bound[j]];
      tsum[i][j] = add(tsum[i][j - 1], dp[i][j]);
    }
  }
  return tsum[k][n];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  int ans = 0;
  int maxt = (a[n] - a[1]) / (k - 1);
  for (int t = 1; t <= maxt; t++) {
    ans = add(ans, solve(t));
  }
  cout << ans << endl;
  return 0;
}
