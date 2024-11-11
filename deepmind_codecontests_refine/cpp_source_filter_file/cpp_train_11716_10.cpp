#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long double pi = acos(-1);
const int MOD = 1e18 + 9;
pair<int, int> ponto[100010];
double dp[100010][4];
double dist(pair<int, int> a, pair<int, int> b) {
  double deltax = a.first - b.first;
  double deltay = a.second - b.second;
  return sqrt(deltax * deltax + deltay * deltay);
}
int main() {
  cout << setprecision(8) << fixed;
  pair<int, int> c1, c2, t;
  int n;
  cin >> c1.first >> c1.second >> c2.first >> c2.second >> t.first >> t.second;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ponto[i].first >> ponto[i].second;
  dp[0][0] = INF;
  dp[0][1] = dist(ponto[0], c2) + dist(ponto[0], t);
  dp[0][2] = dist(ponto[0], c1) + dist(ponto[0], t);
  dp[0][3] = 2 * dist(ponto[0], t);
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][1] + dist(ponto[i], c1) + dist(ponto[i], t);
    dp[i][0] =
        min(dp[i][0], dp[i - 1][2] + dist(ponto[i], c2) + dist(ponto[i], t));
    dp[i][0] = min(dp[i - 1][0] + 2 * dist(ponto[i], t), dp[i][0]);
    dp[i][1] = min(dp[i - 1][1] + 2 * dist(ponto[i], t),
                   dp[i - 1][3] + dist(ponto[i], c2) + dist(ponto[i], t));
    dp[i][2] = min(dp[i - 1][2] + 2 * dist(ponto[i], t),
                   dp[i - 1][3] + dist(ponto[i], c1) + dist(ponto[i], t));
    dp[i][3] = dp[i - 1][3] + 2 * dist(ponto[i], t);
  }
  double r = 1e18;
  ;
  for (int i = 0; i < 3; i++) r = min(r, dp[n - 1][i]);
  cout << r << "\n";
  return 0;
}
