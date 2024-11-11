#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979323846;
const double eps = (1e-10);
int isGreater(long double x, long double y) {
  if (abs(x - y) < eps) return 0;
  if (x > y) return 1;
  return -1;
}
int n, h, l, r;
const int MAX_N = 2003;
int a[MAX_N], mem[MAX_N][MAX_N];
int add(int x, int y) {
  x += y;
  while (x >= h) x -= h;
  while (x < 0) x += h;
  return x;
}
bool good(int x) { return x >= l && x <= r; }
int solve(int i, int cur) {
  if (i == n) return 0;
  int &ret = mem[i][cur];
  if (~ret) return ret;
  ret = solve(i + 1, add(add(cur, a[i]), h)) + good(add(cur, a[i]));
  ret = max(
      ret, solve(i + 1, add(h, add(cur, a[i] - 1))) + good(add(cur, a[i] - 1)));
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> h >> l >> r;
  for (int i = 0; i < n; ++i) cin >> a[i];
  memset(mem, -1, sizeof(mem));
  cout << solve(0, 0);
  return 0;
}
