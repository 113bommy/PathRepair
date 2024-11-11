#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, k, a[N];
long double sumInfinity[N], sumTokens[N], sumExpectation[N];
long double dp[N][55];
long double get(int l, int r) {
  return sumInfinity[r] - sumInfinity[l - 1] -
         (sumTokens[l - 1]) * (sumExpectation[r] - sumExpectation[l - 1]);
}
void calc(int k, int s, int e, int optL, int optR) {
  if (s > e) return;
  int md = (s + e) >> 1;
  dp[md][k] = 1e18;
  int take = optL;
  for (int i = optL; i < min(md, optR + 1); i++) {
    long double cost = get(i + 1, md) + dp[i][k - 1];
    if (cost < dp[md][k]) {
      dp[md][k] = cost;
      take = i;
    }
  }
  calc(k, md + 1, e, take, optR);
  calc(k, s, md - 1, optL, take);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) dp[i][0] = 1e18;
  for (int i = 1; i <= k; i++) dp[0][i] = 1e18;
  sumTokens[1] = a[1];
  sumInfinity[1] = 1;
  sumExpectation[1] = 1.0 / a[1];
  for (int i = 2; i <= n; i++) {
    sumTokens[i] = sumTokens[i - 1] + a[i];
    sumInfinity[i] = sumInfinity[i - 1] + sumTokens[i] / a[i];
    sumExpectation[i] = sumExpectation[i - 1] + 1.0 / a[i];
  }
  for (int i = 1; i <= k; i++) calc(i, 1, n, 0, n);
  cout << fixed << setprecision(4) << dp[n][k] << '\n';
}
