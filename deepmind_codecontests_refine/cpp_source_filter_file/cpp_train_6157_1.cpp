#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long x0, y0, x1, y1;
  cin >> x0 >> y0 >> x1 >> y1;
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long delta_x = 0;
  long long delta_y = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'U') delta_y++;
    if (s[i] == 'D') delta_y--;
    if (s[i] == 'R') delta_x++;
    if (s[i] == 'L') delta_x--;
    if (abs(x1 - x0 - delta_x) + abs(y1 - y0 - delta_y) <= i + 1) {
      cout << i + 1;
      return 0;
    }
  }
  long long l = 1;
  long long r = 1e18;
  while (r - l > 1) {
    long long mid = (l + r) / 2;
    if (mid * n < abs(x1 - x0 - delta_x * mid) + abs(y1 - y0 - delta_y * mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }
  delta_x *= l;
  delta_y *= l;
  for (long long i = 0; i < n; i++) {
    if (s[i] == 'U') delta_y++;
    if (s[i] == 'D') delta_y--;
    if (s[i] == 'R') delta_x++;
    if (s[i] == 'L') delta_x--;
    if (abs(x1 - x0 - delta_x) + abs(y1 - y0 - delta_y) <= i + 1 + n * l) {
      cout << i + 1 + n * l;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
