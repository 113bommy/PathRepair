#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll OO = 1e8;
int di[8] = {0, 0, 1, -1, -1, 1, -1, 1};
int dj[8] = {1, -1, 0, 0, 1, 1, -1, -1};
string ys = "YES", no = "NO";
const long double dgr = acos(-1) / 180, dg = 180 / acos(-1);
const int mod = 1e18, N = 2e5, M = 50000;
string s;
int z;
int dp[N][3][2];
int solve(int idx, int rem, bool ok) {
  if (idx == s.size()) {
    return rem % 3 == 0 && ok ? 0 : -OO;
  }
  int &ret = dp[idx][rem][ok];
  if (ret != -1) return ret;
  ret = -OO;
  if ((!ok && s[idx] != '0') || (ok))
    ret = max(ret, solve(idx + 1, (rem + s[idx] - '0') % 3, 1) + 1);
  ret = max(ret, solve(idx + 1, rem, ok));
  return ret;
}
void build(int idx, int rem, bool ok) {
  if (idx == s.size()) return;
  if ((!ok && s[idx] != '0') || (ok))
    if (solve(idx + 1, (rem + s[idx] - '0') % 3, 1) + 1 == dp[idx][rem][ok]) {
      cout << s[idx];
      build(idx + 1, (rem + s[idx] - '0') % 3, 1);
      return;
    }
  if (solve(idx + 1, rem, ok) == dp[idx][rem][ok]) {
    build(idx + 1, rem, ok);
    return;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  memset(dp, -1, sizeof dp);
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    z += (s[i] == '0');
  }
  int ret = solve(0, 0, 0);
  if (ret <= 0) return cout << (z ? 0 : 1), 0;
  build(0, 0, 0);
  return 0;
}
