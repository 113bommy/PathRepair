#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100, K = 55;
double rev[N], precost[N];
long long sum[N];
int t[N];
double cost(int l, int r) {
  return precost[r] - precost[l] - (rev[r] - rev[l]) * sum[l];
}
double dp[K][N];
inline bool smin(double &a, double b) {
  if (a > b)
    return a = b, true;
  else
    return false;
}
void solve(int k, int ql, int qr, int xl, int xr) {
  if (xr - xl == 1) {
    for (int i = ql; i < qr; i++) {
      dp[k][i] = dp[k - 1][xl] + cost(xl, i);
    }
    return;
  }
  int mid = (ql + qr) / 2, xmid = 0;
  for (int i = xl; i < mid && i < xr; i++)
    if (smin(dp[k][mid], dp[k - 1][i] + cost(i, mid))) xmid = i;
  if (qr - ql > 1) {
    solve(k, ql, mid, xl, xmid + 1);
    solve(k, mid, qr, xmid, xr);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> t[i];
    sum[i + 1] = sum[i] + t[i];
    rev[i + 1] = rev[i] + (1.0 / t[i]);
    precost[i + 1] = precost[i] + double(sum[i + 1]) / t[i];
  }
  for (int i = 0; i <= k; i++) fill(dp[i], dp[i] + n + 1, 1e18);
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) {
    dp[i][0] = 0;
    solve(i, 1, n + 1, 0, n);
  }
  cout << fixed << setprecision(9) << dp[k][n] << endl;
}
