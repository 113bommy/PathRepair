#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int maxn = 1005;
string s;
int n, a[maxn], dp[2][maxn][maxn][2];
bool ok[maxn];
void readf() {
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      a[i + 1] = 2;
      continue;
    }
    a[i + 1] = s[i] - '0';
  }
}
int f(int id, int pos, int i, int type) {
  int &rs = dp[id][pos][i][type];
  if (rs != -1) return rs;
  if (id) {
    ok[i] = ok[n + 1 - i] = 1;
    if (i == n + 1 - i) return 1;
    if (n + 1 - i < pos)
      return (rs = (a[n + 1 - i] == 2 || a[n + 1 - i] == type));
    if (a[n + 1 - i] < 2) return rs = f(0, pos, n + 1 - i, type ^ a[n + 1 - i]);
    return (rs = (f(0, pos, n + 1 - i, 0) + f(0, pos, n + 1 - i, 1)) % mod);
  }
  ok[i] = ok[n + pos - i] = 1;
  if (n + pos - i == pos && type == 0) return 0;
  if (i == n + pos - i) return 1;
  if (a[n + pos - i] < 2)
    return rs = f(1, pos, n + pos - i, type ^ a[n + pos - i]);
  return (rs = (f(1, pos, n + pos - i, 0) + f(1, pos, n + pos - i, 1)) % mod);
}
void solve() {
  memset(dp, -1, sizeof(dp));
  int mid = n + 1 >> 1, ans = 0;
  for (int pos = 2; pos <= n; ++pos) {
    memset(ok, 0, sizeof(ok));
    int rs = 1;
    for (int i = 1; i <= n; ++i)
      if (!ok[i])
        if (a[i] == 2)
          rs = 1LL * rs * (f(1, pos, i, 0) + f(1, pos, i, 1)) % mod;
        else
          rs = rs * f(1, pos, i, a[i]) % mod;
    ans = (ans + rs) % mod;
  }
  cout << ans << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  readf();
  solve();
}
