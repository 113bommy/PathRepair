#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
std::istream& operator>>(std::istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& out, pair<T1, T2>& a) {
  out << a.first << " " << a.second;
  return out;
}
string a, c;
long long b, d;
long long dp[10205][105];
long long calc(long long x, long long y) {
  if (y == (long long)((c).size())) return 0;
  if (x == 10200) return 1000000007;
  long long& ans = dp[x][y];
  if (ans != -1) return ans;
  ans = 1 + calc(x + 1, y);
  if (a[x % (long long)((a).size())] == c[y])
    ans = min(ans, 1 + calc(x + 1, y + 1));
  return ans;
}
long long r[105];
long long s[105];
void solve() {
  cin >> b >> d >> a >> c;
  long long l = (long long)((a).size()) * b;
  memset(dp, -1, sizeof(dp));
  memset(r, -1, sizeof(r));
  long long p = 0, op = 0, z = 0;
  while (1) {
    r[p] = op;
    s[p] = z;
    long long k = calc(p, 0);
    if (k >= 1000000007) {
      cout << 0;
      return;
    }
    op += k;
    if (op > l) break;
    z++;
    p += k;
    p %= (long long)((a).size());
    if (r[p] != -1) {
      long long x = (op - r[p]), y = (z - s[p]);
      while (op + 100000 * x < l) op += 100000 * x, z += 100000 * y;
      while (op + 10000 * x < l) op += 10000 * x, z += 10000 * y;
      while (op + 1000 * x < l) op += 1000 * x, z += 1000 * y;
      while (op + 100 * x < l) op += 100 * x, z += 100 * y;
      while (op + x <= l) op += x, z += y;
    }
  }
  cout << z / d;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
