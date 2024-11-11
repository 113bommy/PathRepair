#include <bits/stdc++.h>
using namespace std;
int n, m;
int moves(int x, int y, int fx, int fy, int a, int b) {
  int dx = abs(fx - x), dy = abs(fy - y);
  if ((dx > 0 || dy > 0) &&
      (x + a > n && x - a < 1 || y + b > n && y - b < 1)) {
    return 1e9;
  }
  if (dx % a != 0 || dy % b != 0) {
    return 1e9;
  }
  if (dx / a % 2 != dy / b % 2) {
    return 1e9;
  }
  return max(dx / a, dy / b);
}
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout.setf(ios_base::fixed);
  cout.precision(28);
  int x, y, a, b, ans = 1e9;
  cin >> n >> m >> x >> y >> a >> b;
  ans = min(ans, moves(x, y, 1, 1, a, b));
  ans = min(ans, moves(x, y, 1, m, a, b));
  ans = min(ans, moves(x, y, n, 1, a, b));
  ans = min(ans, moves(x, y, n, m, a, b));
  if (ans == 1e9) {
    cout << "Poor Inna and pony!";
  } else {
    cout << ans;
  }
  return 0;
}
