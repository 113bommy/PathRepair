#include <bits/stdc++.h>
using namespace std;
long long dx4[4] = {0, 1, 0, -1};
long long dy4[4] = {1, 0, -1, 0};
long long dy8[8] = {1, 1, 1, 0, -1, -1, -1, 0};
long long dx8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
long long power(long long b, long long p) {
  if (p == 0) return 1;
  long long t = power(b, p / 2);
  t = t * t;
  if (p % 2 == 1) t = t * b;
  return t;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long x, y;
  cin >> x >> y;
  long long k;
  cin >> k;
  int ans = 0;
  while (k--) {
    long long dx, dy;
    cin >> dx >> dy;
    long long mx, my;
    if (dx > 0)
      mx = (n - x) / dx;
    else if (dx < 0)
      mx = (1 - x) / dx;
    else
      mx = 10e9;
    if (dy > 0)
      my = (m - y) / dy;
    else if (dy < 0)
      my = (1 - y) / dy;
    else
      my = 10e9;
    long long m = min(mx, my);
    x = x + m * dx;
    y = y + m * dy;
    ans += m;
  }
  cout << ans;
  return 0;
}
