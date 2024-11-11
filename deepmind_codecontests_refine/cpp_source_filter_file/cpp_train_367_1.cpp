#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int maxd = 11, maxn = 1111;
long long P;
long long dp[maxn][maxn][maxd], t[maxn];
long long fact[maxn], tcaf[maxn];
long long deg(long long x, long long d) {
  d %= P - 1;
  if (d < 0) d += P - 1;
  long long y = 1;
  while (d) {
    if (d & 1) y *= x, y %= P;
    x *= x, x %= P;
    d /= 2;
  }
  return y;
}
void add(long long &x, long long y) {
  x += y;
  x %= P;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n, d;
  cin >> n >> d >> P;
  if (n <= 2) {
    cout << 1 << '\n';
    return 0;
  }
  fact[0] = 1;
  for (int i = 1; i <= (int)(n); ++i) fact[i] = fact[i - 1] * i % P;
  for (int i = 0; i < (int)(n + 1); ++i) tcaf[i] = deg(fact[i], -1);
  t[1] = 1;
  dp[0][0][0] = 1;
  for (int i = 1; i <= (int)(n); ++i) {
    for (int k = 0; k < (int)(d + 1); ++k)
      for (int q = 0; q < (int)(d - k + 1); ++q) {
        long long w = 1;
        for (int r = 0; r < (int)(q); ++r) w *= t[i] + r;
        w %= P;
        w *= tcaf[q];
        w %= P;
        for (int s = 0; s < (int)(n + 1); ++s) {
          int ss = s + q * i;
          if (ss > n) break;
          if (!dp[s][i - 1][k]) continue;
          add(dp[ss][i][k + q], dp[s][i - 1][k] * w);
        }
      }
    t[i + 1] = dp[i][i][d - 1];
  }
  long long ans = dp[n - 1][(n - 1) / 2][d];
  if (n % 2 == 0) {
    long long w = dp[n / 2 - 1][n / 2 - 1][d - 1];
    add(ans, w * (w + 1) % P * (P + 1) / 2);
  }
  if (ans < 0) ans += P;
  cout << ans << '\n';
  return 0;
}
