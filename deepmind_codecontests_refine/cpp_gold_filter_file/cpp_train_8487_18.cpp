#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
double dp[N][57], cst[N], sum[N], db[N];
double a[N];
int n, k;
void divide(int l, int r, int optl, int optr, int j) {
  if (l > r) return;
  int mid = (l + r) >> 1, opt = optl;
  dp[mid][j] = dp[optl - 1][j - 1] + cst[mid] - cst[optl - 1] -
               (db[mid] - db[optl - 1]) * sum[optl - 1];
  for (int i = optl + 1; i <= min(mid, optr); i++) {
    double res = dp[i - 1][j - 1] + cst[mid] - cst[i - 1] -
                 (db[mid] - db[i - 1]) * sum[i - 1];
    if (res < dp[mid][j]) {
      dp[mid][j] = res;
      opt = i;
    }
  }
  divide(l, mid - 1, optl, opt, j);
  divide(mid + 1, r, opt, optr, j);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &a[i]);
    sum[i] = sum[i - 1] + a[i];
    cst[i] = cst[i - 1] + (sum[i] / a[i]);
    db[i] = db[i - 1] + (1 / a[i]);
    dp[i][1] = cst[i];
  }
  for (int i = 2; i <= k; i++) divide(1, n, 1, n, i);
  cout << dp[n][k];
}
