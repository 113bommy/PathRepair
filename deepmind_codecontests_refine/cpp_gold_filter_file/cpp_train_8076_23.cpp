#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-2;
const long double PI = acos(-1.0);
const long double dx[] = {cos(PI / 6),     cos(PI / 2),     cos(5 * PI / 6),
                          cos(7 * PI / 6), cos(3 * PI / 2), cos(11 * PI / 6)};
const long double dy[] = {sin(PI / 6),     sin(PI / 2),     sin(5 * PI / 6),
                          sin(7 * PI / 6), sin(3 * PI / 2), sin(11 * PI / 6)};
inline bool check(long double x, long double y, long double k) {
  for (int i = 0; i < 6; i++) {
    long double nx = x + dx[i];
    long double ny = y + dy[i];
    if (nx * nx + ny * ny > k * k + eps) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  int k;
  cin >> k;
  long long ans = 0;
  long double x = 0.0;
  long double y = 0.0;
  long double nx = 2 * dx[0] * cos(PI / 3);
  long double ny = 2 * dx[0] * sin(PI / 3);
  while (check(x + 2 * dx[0], y, k)) {
    int l = 1, r = k;
    while (l < r) {
      int m = l + (r - l + 1) / 2;
      if (check(x + 2 * m * dx[0], y, k))
        l = m;
      else
        r = m - 1;
    }
    ans += l;
    x += nx;
    y += ny;
  }
  ans *= 6;
  ans += 1;
  cout << ans;
  return 0;
}
