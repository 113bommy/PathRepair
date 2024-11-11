#include <bits/stdc++.h>
using namespace std;
const int N = 101;
const double EPS = 1e-7;
int n, k;
double eps;
int x[N], y[N];
double p[N];
double dp[N][N];
double solve(int pos = 1, int cnt = 0) {
  if (pos > n) return cnt >= k;
  double &ret = dp[pos][cnt];
  if (!isnan(ret)) return ret;
  ret = p[pos] * solve(pos + 1, cnt + 1);
  ret += (1.0 - p[pos]) * solve(pos + 1, cnt);
  return ret;
}
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
bool ck(double r) {
  for (long long i = 1; i <= n; ++i) {
    double d = dist(x[i], y[i], x[0], y[0]);
    if (d + EPS <= r)
      p[i] = 1.0;
    else
      p[i] = exp(1 - ((d * d) / (r * r)));
  }
  memset(dp, -1, sizeof(dp));
  return solve() >= eps + EPS;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k >> eps;
  eps /= 1000.0;
  eps = 1.0 - eps;
  cin >> x[0] >> y[0];
  double mx = 0.0;
  for (long long i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    mx = max(mx, dist(x[i], y[i], x[0], y[0]));
  }
  cout << fixed << setprecision(10);
  double l = 0.0, r = mx;
  double R = 0.0;
  while (l + EPS <= r) {
    double mid = (l + r) / 2.0;
    if (ck(mid)) {
      r = mid;
      R = mid;
    } else {
      l = mid;
    }
  }
  cout << R;
  return 0;
}
