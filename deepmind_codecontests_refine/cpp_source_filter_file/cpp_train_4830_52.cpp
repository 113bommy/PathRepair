#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);
  int n;
  cin >> n;
  if (n < 5) {
    cout << "No solution\n";
    return 0;
  }
  long double ag = 2.0 * acos(-1.0) / n;
  long double l = 100, now = 0, x = 0, y = 0;
  cout << x << ' ' << y << '\n';
  for (int i = 2; i < n; i++) {
    now += ag;
    x += l * cos(now);
    y += l * sin(now);
    l += 0.01;
    cout << x << ' ' << y << '\n';
  }
  now += ag;
  long double fin = x - y / tan(now);
  cout << fin << ' ' << 0;
  return 0;
}
