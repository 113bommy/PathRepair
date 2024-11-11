#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int mod = 1e9 + 7;
long long f[2][N][N];
int n, tot;
struct point {
  long long x, y;
  point(long long _x = 0, long long _y = 0) {
    x = _x;
    y = _y;
  }
  point operator-(const point &rhs) const {
    return point(x - rhs.x, y - rhs.y);
  }
} p[N], p2[N];
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
long long dp(int i, int j, int op, point p[]) {
  if (f[op][i][j] != -1) return f[op][i][j];
  if (j - i < 2) return 1;
  f[op][i][j] = 0;
  for (int k = i + 1; k <= j - 1; k++) {
    if (cross(p[k] - p[i], p[j] - p[i]) > 0) {
      f[op][i][j] += (dp(i, k, op, p) * dp(k, j, op, p)) % mod;
      f[op][i][j] %= mod;
    }
  }
  return f[op][i][j];
}
int main() {
  memset(f, -1, sizeof(f));
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    p2[n - i - 1].x = p[i].x;
    p2[n - i - 1].y = p[i].y;
  }
  long long ans1, ans2;
  ans1 = dp(0, n - 1, 0, p);
  ans2 = dp(0, n - 1, 1, p2);
  printf("%lld\n", max(ans1, ans2));
  return 0;
}
