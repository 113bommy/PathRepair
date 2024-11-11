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
struct P {
  double x, y;
};
P a, b[N];
double mx, mn = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> a.x >> a.y;
  bool z = 0;
  double pi = 3.14159265359;
  for (int i = 1; i <= n; i++) cin >> b[i].x >> b[i].y;
  for (int i = 1; i <= n; i++) {
    double v =
        (b[i].x - a.x) * (b[i].x - a.x) + (b[i].y - a.y) * (b[i].y - a.y);
    if (v > mx) mx = v;
    if (v < mn) mn = v;
  }
  b[n + 1] = b[1];
  for (int i = 1; i <= n; i++) {
    double p, v1, v2, v3, S;
    if ((a.x - b[i].x) * (b[i + 1].x - b[i].x) +
            (a.y - b[i].y) * (b[i + 1].y - b[i].y) <
        0)
      continue;
    if ((a.x - b[i + 1].x) * (b[i].x - b[i + 1].x) +
            (a.y - b[i + 1].y) * (b[i].y - b[i + 1].y) <
        0)
      continue;
    v1 = (b[i].x - b[i + 1].x) * (b[i].x - b[i + 1].x) +
         (b[i].y - b[i + 1].y) * (b[i].y - b[i + 1].y);
    v2 = (a.x - b[i + 1].x) * (a.x - b[i + 1].x) +
         (a.y - b[i + 1].y) * (a.y - b[i + 1].y);
    v3 = (b[i].x - a.x) * (b[i].x - a.x) + (b[i].y - a.y) * (b[i].y - a.y);
    v1 = sqrt(v1), v2 = sqrt(v2), v3 = sqrt(v3);
    p = (v1 + v2 + v3) / 2.0;
    S = p * (p - v1) * (p - v2) * (p - v3);
    S = sqrt(S);
    v1 = (2.0 * S) / v1;
    if (mn > v1) mn = v1, z = 1;
  }
  mx = sqrt(mx);
  mn = ((!z) ? sqrt(mn) : mn);
  mx = pi * (mx * mx - mn * mn);
  cout << fixed << setprecision(10) << mx;
  return 0;
}
