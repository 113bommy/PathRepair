#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
double dp[maxN];
double x[maxN], b[maxN];
int par[maxN];
void solve(int v) {
  if (par[v] > -1) solve(par[v]);
  cout << v + 1 << ' ';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, l;
  cin >> n >> l;
  for (int i = 0; i < n; i++) cin >> x[i] >> b[i];
  double lo = 0, hi = maxN * maxN;
  for (int z = 0; z < 100; z++) {
    double mid = (lo + hi) / 2;
    for (int i = 0; i < n; i++) {
      dp[i] = sqrt(abs(x[i] - l)) - mid * b[i];
      for (int j = 0; j < i; j++)
        dp[i] = min(dp[i], dp[j] + sqrt(abs(x[i] - x[j] - l)) - mid * b[i]);
    }
    if (dp[n - 1] < 1e-12)
      hi = mid;
    else
      lo = mid;
  }
  memset(par, -1, sizeof par);
  for (int i = 0; i < n; i++) {
    dp[i] = sqrt(abs(x[i] - l)) - hi * b[i];
    for (int j = 0; j < i; j++)
      if (dp[i] > dp[j] + sqrt(abs(x[i] - x[j] - l)) - hi * b[i]) {
        par[i] = j;
        dp[i] = dp[j] + sqrt(abs(x[i] - x[j] - l)) - hi * b[i];
      }
  }
  solve(n - 1);
  cout << endl;
  return 0;
}
