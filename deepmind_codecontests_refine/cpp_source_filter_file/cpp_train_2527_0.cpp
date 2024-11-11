#include <bits/stdc++.h>
using namespace std;
long long Min(long long a, long long b) { return (a < b) ? a : b; }
long long Max(long long a, long long b) { return (a < b) ? b : a; }
long long gcd(long long m, long long n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
long long mod = 1e9 + 7;
long long add(long long x, long long y) { return (x + y) % mod; }
long long mul(long long x, long long y) { return (x * y) % mod; }
long long d[500005][4][4];
long long th[500005] = {
    1,
};
void solve() {
  long long n, cnt = 0;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') cnt++;
  }
  for (int i = 1; i <= n; i++) {
    th[i] = mul(th[i - 1], 3);
  }
  d[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      for (int k = 0; k < 4; k++) {
        if (d[i][j][k] == 0) continue;
        d[i + 1][j][k] = add(d[i][j][k], d[i + 1][j][k]);
        if (s[i] == '?') {
          if (k + 1 < 4) {
            d[i + 1][j + 1][k + 1] = add(d[i + 1][j + 1][k + 1], d[i][j][k]);
          }
        } else if (s[i] - 'a' == j) {
          if (k + 1 < 4) {
            d[i + 1][j + 1][k] = add(d[i][j][k], d[i + 1][j + 1][k]);
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 3; i++) {
    if (cnt - i >= 0) ans = add(ans, mul(d[n][3][i], th[cnt - i]));
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tc = 1;
  while (tc--) solve();
  exit(0);
}
