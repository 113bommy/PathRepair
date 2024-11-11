#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
const double PI = 2 * acos(0.0);
const long double eps = 1e-6;
const int infi = 1e9;
const long long Linfi = (long long)9e18;
const long long MOD = 1000000007;
int n, m;
double p[5005], dp[5005][5005];
int t[5005];
void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0][0] = 1;
  p[n + 1] = 0;
  t[n + 1] = 1000000;
  for (int i = 0; i <= n; i++) {
    double q = pow(1 - p[i + 1], t[i + 1]);
    for (int j = m; j >= 1; j--) {
      if (j - t[i + 1] >= 0) {
        dp[i + 1][j] += dp[i][j - t[i + 1]] * q;
        dp[i][j] -= dp[i][j - t[i + 1]] * q;
      }
    }
    for (int j = 1; j <= m; j++) {
      if (j >= 1) {
        dp[i + 1][j] += dp[i][j - 1] * p[i + 1];
        dp[i][j] += dp[i][j - 1] * (1 - p[i + 1]);
      }
    }
  }
  double ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[i][m] * i;
  for (int j = 1; j <= m - 1; j++) ans += dp[n][j] * n;
  cout << fixed << setprecision(6);
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x >> t[i];
    p[i] = x / 100.0;
  }
  solve();
  return 0;
}
