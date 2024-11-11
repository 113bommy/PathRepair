#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-8;
long double D[105];
long double dp[105][105];
long double eps;
int n, k;
long double dist(int x0, int y0, int x1, int y1) {
  return (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
}
long double prob(long double d, long double R) {
  if (d <= R * R + EPS)
    return 1;
  else
    return exp(1 - d / (R * R));
}
bool check(long double R) {
  for (int i = int(0); i < int(n + 1); i++)
    for (int j = int(0); j < int(n + 1); j++) dp[i][j] = 0;
  dp[0][0] = 1;
  for (int i = int(1); i < int(n + 1); i++) {
    long double p = prob(D[i], R);
    for (int j = int(0); j < int(i + 1); j++) {
      dp[i][j] = (k > 0 ? dp[i - 1][j - 1] * p : 0) + dp[i - 1][j] * (1 - p);
    }
  }
  long double cur = 0.0;
  for (int i = int(k); i < int(n + 1); i++) cur += dp[n][i];
  return cur >= 1 - eps;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  cin >> eps;
  eps /= 1000;
  int x0, y0, x1, y1;
  cin >> x0 >> y0;
  for (int i = int(1); i < int(n + 1); i++) {
    cin >> x1 >> y1;
    D[i] = dist(x1, y1, x0, y0);
  }
  long double l = 0, r = 1000;
  while (r - l > EPS) {
    long double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  cout << setprecision(12) << (l + r) / 2 << endl;
  return 0;
}
