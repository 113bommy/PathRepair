#include <bits/stdc++.h>
using namespace std;
int n;
struct point {
  long long x, y;
  point(long long X = 0, long long Y = 0) { x = X, y = Y; }
} p[310];
point V(point s, point e) { return point(e.x - s.x, e.y - s.y); }
long long crossP(point a, point b) { return a.x * b.y - a.y * b.x; }
const long long mod = 1000000007;
bool vis[310][310];
long long f[310][310];
long long dp(int l, int r) {
  long long &x = f[l][r];
  if (vis[l][r]) return x;
  if (l + 1 == r) return x = 1;
  vis[l][r] = true;
  for (int i = l + 1; i <= r - 1; i++) {
    if (crossP(V(p[r], p[l]), V(p[r], p[i])) < 0)
      x = (x + dp(l, i) * dp(i, r)) % mod;
  }
  return x;
}
int main(int argc, char *argv[]) {
  cin >> n;
  int area = 0;
  for (int i = 1; i <= n; i++) cin >> p[i].x >> p[i].y;
  p[n + 1] = p[1];
  for (int i = 1; i <= n; i++) area += crossP(p[i], p[i + 1]);
  if (area > 0)
    for (int i = 1; 2 * i <= n; i++) swap(p[i], p[n - i + 1]), p[n + 1] = p[1];
  cout << dp(1, n) << endl;
  return 0;
}
