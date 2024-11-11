#include <bits/stdc++.h>
using namespace std;
const int N = int(1001);
int dp[N][11];
struct bul {
  int a, b, c, d;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m, c0, d0;
  cin >> n >> m >> c0 >> d0;
  double cost = (1.0 * d0) / c0;
  vector<bul> p(m + 1);
  vector<pair<double, int> > vec;
  vec.push_back({cost, -1});
  for (int i = 0; i < m; i++) {
    cin >> p[i].a >> p[i].b >> p[i].c >> p[i].d;
    double c1 = 1.0 * p[i].d / p[i].c;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < m; j++) {
      for (int z = 0; i >= p[j].c * z && z <= p[j].a / p[j].b; z++) {
        dp[i][j] = max(dp[i][j], dp[i - p[j].c * z][j - 1] + p[j].d * z);
      }
    }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i][m - 1] + (n - i) / c0 * d0);
  }
  cout << ans;
}
