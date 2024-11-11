#include <bits/stdc++.h>
using namespace std;
const double e = 2.7182818284590452353602874713527;
int main() {
  int n;
  cin >> n;
  vector<double> dist;
  int k;
  double eps;
  cin >> k >> eps;
  eps = 1 - eps / 1000;
  int cx, cy;
  cin >> cx >> cy;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    dist.push_back((x - cx) * (x - cx) + (y - cy) * (y - cy));
  }
  sort(dist.begin(), dist.end());
  double lo = 0;
  double hi = 3000;
  double prob = -1;
  double ans = 0;
  double opt[101][101];
  while (hi - lo > 1e-9) {
    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        opt[i][j] = 0;
      }
    }
    opt[0][0] = 1;
    double t3 = prob;
    ans = (lo + hi) / 2;
    prob = 0;
    for (int i = 0; i < n; i++) {
      double t2 = min(1.0, pow(e, 1 - dist[i] / (ans * ans)));
      for (int j = 1; j <= i; j++)
        opt[i + 1][j] = opt[i][j - 1] * t2 + opt[i][j] * (1 - t2);
      opt[i + 1][0] = opt[i][0] * (1 - t2);
      opt[i + 1][i + 1] = opt[i][i] * t2;
    }
    for (int i = k; i <= n; i++) prob += opt[n][i];
    if (prob < eps) {
      lo = ans;
    } else {
      hi = ans;
    }
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
