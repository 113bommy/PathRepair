#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
const char E = '\n';
const int N = 100005;
const ll mod = 1e9 + 7;
const int lim = 1e5;
mt19937_64 mt_rnd_64(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll l, ll r) { return (mt_rnd_64() % (r - l + 1)) + l; }
int n;
double pi = 3.14159265359;
struct P {
  int x, y;
};
P a, b[N];
double mx = -1e9, mn = 1e9, ans;
double cv(double x) { return x * x; }
double dist(P x, P y) { return sqrt(cv(x.x - y.x) + cv(x.y - y.y)); }
double areatriangle(P x, P y, P c) {
  return ((y.x - x.x) * (c.y - x.y) - (y.y - x.y) * (c.x - x.x));
}
double dist(P x, P y, P c) {
  double v1, v2, v3;
  v1 = dist(x, y);
  v2 = dist(x, c);
  v3 = dist(y, c);
  if (cv(v1) > cv(v2) + cv(v3) || cv(v2) > cv(v1) + cv(v3) || fabs(v3) < 1e-8)
    return min(v1, v2);
  double S = areatriangle(x, y, c);
  return (fabs(S / v3));
}
double Sarea(double x, double y) { return pi * (cv(x) - cv(y)); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a.x >> a.y;
  bool z = 0;
  for (int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y;
  b[n + 1] = b[1];
  for (int i = 1; i <= n; i++) {
    mx = max(mx, dist(b[i], a));
    mn = min(mn, dist(b[i], a));
    mn = min(mn, dist(a, b[i], b[i + 1]));
  }
  ans = Sarea(mx, mn);
  cout << fixed << setprecision(10) << ans;
  return 0;
}
