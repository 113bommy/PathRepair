#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-9;
const int N = 2e3 + 5;
const int M = 2e5 + 10;
const int mod = 1e9 + 7;
int m, d, dp[N][N][2], pw[N];
string s;
int add(int a, int b) { return (a + b) % mod; }
int add2(int a, int b) { return (a + b) % m; }
int mul(int a, int b) { return (a * 1ll * b) % m; }
int go(int i, int rem, bool ok) {
  if (i == s.size()) return rem == 0;
  int &ret = dp[i][rem][ok];
  if (ret != -1) return ret;
  ret = 0;
  int x = s[i] - '0';
  if (i % 2 == 0) {
    for (int j = 0; j <= 9; j++) {
      if (j == d) continue;
      if (i == 0 && j == 0) continue;
      if (ok || j < x)
        ret = add(ret, go(i + 1, add2(rem, mul(j, pw[s.size() - i - 1])), 1));
      else if (j == x)
        ret = add(ret, go(i + 1, add2(rem, mul(j, pw[s.size() - i - 1])), ok));
    }
  } else if (d <= x) {
    if (d < x)
      ret = add(ret, go(i + 1, add2(rem, mul(d, pw[s.size() - i - 1])), 1));
    else
      ret = add(ret, go(i + 1, add2(rem, mul(d, pw[s.size() - i - 1])), ok));
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> m >> d >> a >> b;
  pw[0] = 1;
  for (int i = 1; i < N; i++) pw[i] = (pw[i - 1] * 10ll) % m;
  s = a;
  memset(dp, -1, sizeof dp);
  int ans1 = go(0, 0, 0);
  s = b;
  memset(dp, -1, sizeof dp);
  int ans2 = go(0, 0, 0);
  ans2 = (ans2 + mod - ans1) % mod;
  bool ok = 1;
  int rem = 0;
  for (int i = 0; i < a.size(); i++) {
    if ((i % 2 == 0 && a[i] - '0' == d) || (i % 2 && a[i] - '0' != d)) ok = 0;
    rem = add2(rem, mul(a[i] - '0', pw[a.size() - i - 1]));
  }
  if (ok && rem == 0) ans2++;
  ans2 %= mod;
  cout << ans2 << '\n';
  return 0;
}
