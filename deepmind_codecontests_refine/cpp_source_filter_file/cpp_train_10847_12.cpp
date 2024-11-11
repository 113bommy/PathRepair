#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 20 + 5;
const long long MAX2 = 11;
const long long MOD = 1000000007;
const long long MOD2 = 1000005329;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 2000;
long long tc, z, l, r, dp[30][2][2][2][2], ans;
long long f(int pos, bool x, bool y, bool a, bool b) {
  if (pos < 0) return 1;
  long long &ret = dp[pos][x][y][a][b];
  if (ret != -1) return ret;
  ret = 0;
  if (r & (1 << pos)) {
    if (l & (1 << pos)) {
      if (a & b) ret += f(pos - 1, 1, 1, a, b);
      if (b) ret += f(pos - 1, 1, 1, a, b);
      if (a) ret += f(pos - 1, 1, 1, a, b);
    } else {
      ret += f(pos - 1, 1, 1, a, b);
      ret += f(pos - 1, x, 1, 1, b);
      ret += f(pos - 1, 1, y, a, 1);
    }
  } else {
    if (l & (1 << pos)) {
      if (a & b) ret += f(pos - 1, x, y, a, b);
      if (b & x) ret += f(pos - 1, x, y, a, b);
      if (a & y) ret += f(pos - 1, x, y, a, b);
    } else {
      ret += f(pos - 1, x, y, a, b);
      if (x) ret += f(pos - 1, x, y, 1, b);
      if (y) ret += f(pos - 1, x, y, a, 1);
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> tc;
  while (tc--) {
    cin >> l >> r;
    memset(dp, -1, sizeof dp);
    cout << f(29, 0, 0, 0, 0) << '\n';
  }
  return 0;
}
