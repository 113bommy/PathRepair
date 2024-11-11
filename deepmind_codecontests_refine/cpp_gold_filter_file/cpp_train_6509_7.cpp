#include <bits/stdc++.h>
using namespace std;
int n, k;
long double dp[51][200001], pref[200001], ar[200001], sum[200001], suf[200001];
void dvach(int l, int r, int L, int R, int x) {
  if (l > r) return;
  int mid = (r + l) / 2, ind;
  for (int i = L; i <= min(R, mid); i++) {
    long double now = dp[x - 1][i - 1] + suf[i] - suf[mid + 1] -
                      (pref[n] - pref[mid]) * (sum[mid] - sum[i - 1]);
    if (dp[x][mid] > now) dp[x][mid] = now, ind = i;
  }
  dvach(l, mid - 1, L, ind, x);
  dvach(mid + 1, r, ind, R, x);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> ar[i];
    pref[i] = ar[i];
    pref[i] = pref[i - 1] + (1 / pref[i]);
    sum[i] += ar[i] + sum[i - 1];
  }
  long double pp = 0;
  for (int i = n; i >= 1; i--)
    pp += 1 + (ar[i] * (pref[n] - pref[i])), suf[i] = pp;
  for (int i = 1; i <= k; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 1e18;
  long double s = 0;
  pp = 0;
  for (int i = 1; i <= n; i++) {
    s += ar[i];
    pp += (s / ar[i]);
    dp[1][i] = pp;
  }
  for (int i = 2; i <= k; i++) dvach(i, n, i, n, i);
  cout << fixed << setprecision(12) << dp[k][n] << endl;
  return 0;
}
