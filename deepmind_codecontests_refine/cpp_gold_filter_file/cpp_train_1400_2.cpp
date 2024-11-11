#include <bits/stdc++.h>
using namespace std;
const int maxn = 200 + 10;
const int mod = 1000000007;
struct Point {
  long long x, y;
  Point(long long x = 0, long long y = 0) : x(x), y(y) {}
  Point operator-(const Point& A) { return Point(x - A.x, y - A.y); }
};
Point v[maxn];
long long Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
bool Isclockwise(int n) {
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += Cross(v[i], v[i + 1]);
  return ans < 0;
}
int n;
long long d[maxn][maxn];
long long dp(int l, int r) {
  if (d[l][r] != -1) return d[l][r];
  long long& ans = d[l][r];
  ans = 0;
  if (r == l + 1) return ans = 1;
  for (int i = l + 1; i < r; i++) {
    if (Cross(v[r] - v[l], v[i] - v[l]) > 0)
      ans = (ans + dp(l, i) * dp(i, r)) % mod;
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &v[i].x, &v[i].y);
  v[n + 1] = v[1];
  if (!Isclockwise(n)) reverse(v + 1, v + n + 1);
  memset(d, -1, sizeof(d));
  long long ans = dp(1, n);
  printf("%I64d\n", ans);
  return 0;
}
