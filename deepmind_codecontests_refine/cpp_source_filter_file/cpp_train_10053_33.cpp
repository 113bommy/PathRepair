#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 7, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const double eps = 1e-10;
int n, a, b, mx = 50;
double p[maxn], u[maxn], dp[maxn];
int na[maxn], nb[maxn];
double ansa, ansb;
void solve(double ca, double cb) {
  dp[0] = 0.0;
  na[0] = nb[0] = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    na[i] = na[i - 1];
    nb[i] = nb[i - 1];
    if (dp[i] < dp[i - 1] + p[i] - ca - eps) {
      dp[i] = dp[i - 1] + p[i] - ca;
      na[i] = na[i - 1] + 1;
      nb[i] = nb[i - 1];
    }
    if (dp[i] < dp[i - 1] + u[i] - cb - eps) {
      dp[i] = dp[i - 1] + u[i] - cb;
      na[i] = na[i - 1];
      nb[i] = nb[i - 1] + 1;
    }
    if (dp[i] < dp[i - 1] + p[i] + u[i] - ca - cb - p[i] * u[i] - eps) {
      dp[i] = dp[i - 1] + p[i] + u[i] - ca - cb - p[i] * u[i];
      na[i] = na[i - 1] + 1;
      nb[i] = nb[i - 1] + 1;
    }
  }
}
void checkb(double co) {
  double l = 0, r = 1, mid;
  for (int i = 1; i <= mx; ++i) {
    mid = (l + r) / 2;
    solve(co, mid);
    if (nb[n] >= b)
      l = (ansb = mid);
    else
      r = mid;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= n; ++i) cin >> u[i];
  double l = 0, r = 1, mid;
  for (int i = 1; i <= mx; ++i) {
    mid = (l + r) / 2;
    checkb(mid);
    if (na[n] >= a)
      l = (ansa = mid);
    else
      r = mid;
  }
  solve(ansa, ansb);
  cout << fixed << setprecision(4) << dp[n] + ansa * a + ansb * b << '\n';
  return 0;
}
