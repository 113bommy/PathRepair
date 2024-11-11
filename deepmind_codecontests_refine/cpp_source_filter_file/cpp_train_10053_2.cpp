#include <bits/stdc++.h>
using namespace std;
const int N = 2001;
const int SQRT = 10;
double dp[2][N][N];
int main() {
  ios_base::sync_with_stdio(0);
  cout << setprecision(6) << fixed;
  int n, a, b;
  cin >> n >> a >> b;
  vector<pair<double, double>> p(n);
  for (int i = (0); i <= (n - 1); ++i) {
    cin >> p[i].first;
  }
  for (int i = (0); i <= (n - 1); ++i) {
    cin >> p[i].second;
  }
  random_shuffle(p.begin(), p.end());
  for (int i = (1); i <= (n); ++i) {
    int t = i % 2;
    int expx = (a * i) / n, expy = (b * i) / n;
    double probx = p[i - 1].first, proby = p[i - 1].second;
    for (int x = (max(0, expx - SQRT)); x <= (min(n, expx + SQRT)); ++x)
      for (int y = (max(0, expy - SQRT)); y <= (min(n, expy + SQRT)); ++y) {
        dp[t][x][y] = 0.0;
        for (int lx = (0); lx <= (min(x, 1)); ++lx)
          for (int ly = (0); ly <= (min(y, 1)); ++ly) {
            double prob = lx * probx + ly * proby - lx * ly * probx * proby;
            dp[t][x][y] = max(dp[t][x][y], prob + dp[1 - t][x - lx][y - ly]);
          }
      }
  }
  cout << dp[n % 2][a][b];
  return 0;
}
