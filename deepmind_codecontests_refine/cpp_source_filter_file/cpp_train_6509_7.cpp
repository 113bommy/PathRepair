#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5 + 42, kmax = 53;
const double eps = 1.0 / 1e9;
int n, k;
double dp[nmax][kmax];
int t[nmax];
long long sum[nmax];
double inv[nmax], s[nmax];
double cost(int l, int r) {
  return s[r] - s[l - 1] - sum[l - 1] * (inv[r] - inv[l - 1]);
}
int brute(int ind, int i, int lq, int rq) {
  rq = min(i, rq);
  double now;
  int ret = i;
  for (int j = lq; j <= rq; j++) {
    now = dp[ind - 1][j - 1] + cost(j, i);
    if (dp[ind][i] - now > eps) {
      ret = j;
      dp[ind][i] = now;
    }
  }
  return ret;
}
void solve(int ind, int l, int r, int lq, int rq) {
  rq = min(rq, r);
  if (l > r) return;
  if (lq == rq) {
    for (int i = l; i <= r; i++) dp[ind][i] = dp[ind - 1][lq - 1] + cost(lq, i);
    return;
  }
  int av = (l + r) / 2;
  int p = brute(ind, av, lq, rq);
  solve(ind, l, av - 1, lq, p);
  solve(ind, av + 1, r, p, rq);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> t[i];
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + t[i];
    inv[i] = inv[i - 1] + 1.0 / t[i];
    s[i] = s[i - 1] + sum[i] * 1.0 / t[i];
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= k; j++) dp[j][i] = 1e18;
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) solve(i, 1, n, 1, n);
  printf("%.18f\n", dp[k][n]);
  return 0;
}
