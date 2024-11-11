#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const long long MOD = 1e9 + 7;
struct point {
  long long x, y;
  long long operator*(const point& c) const { return x * c.y - y * c.x; }
  point operator-(const point& c) const {
    point u;
    u.x = x - c.x;
    u.y = y - c.y;
    return u;
  }
} p[N];
int n;
long long dp[N][N];
void init() {
  scanf("%d", &n);
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) scanf("%lld %lld", &p[i].x, &p[i].y);
  long long tmp = 0;
  p[n] = p[0];
  for (int i = 0; i < n; i++) tmp = p[i] * p[i + 1];
  if (tmp < 0) reverse(p, p + n);
}
long long solve(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  long long& ans = dp[l][r];
  ans = 0;
  if (r - l == 1) return ans = 1;
  for (int i = l + 1; i < r; i++) {
    if ((p[l] - p[r]) * (p[i] - p[r]) > 0)
      ans = (ans + solve(l, i) * solve(i, r)) % MOD;
  }
  return ans;
}
int main() {
  init();
  printf("%lld\n", solve(0, n - 1));
  return 0;
}
