#include <bits/stdc++.h>
#pragma GCC optimize("O2,unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], cnt[MAXN];
long long dp[21][MAXN], cost;
void add(int x) {
  cost += cnt[x];
  cnt[x]++;
}
void rem(int x) {
  cnt[x]--;
  cost -= cnt[x];
}
void divide(int k, int tl, int tr, int optl, int optr) {
  if (tr < tl) return;
  int mid = (tl + tr) >> 1, opt = -1;
  for (int i = tl; i <= mid; i++) add(A[i]);
  for (int i = optl; i <= min(optr, mid); i++) {
    rem(A[i]);
    if (dp[k - 1][i] + cost < dp[k][mid]) {
      dp[k][mid] = dp[k - 1][i] + cost;
      opt = i;
    }
  }
  for (int i = min(optr, mid); i >= opt; i--) add(A[i]);
  divide(k, mid + 1, tr, opt, optr);
  for (int i = tl; i <= mid; i++) rem(A[i]);
  for (int i = optl; i < opt; i++) add(A[i]);
  divide(k, tl, mid - 1, optl, opt);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i];
  memset(dp, 63, sizeof(dp));
  dp[0][0] = 0;
  cnt[0] = 1;
  for (int i = 1; i <= k; i++) divide(i, 1, n, 0, n);
  cout << dp[k][n] << '\n';
  return 0;
}
