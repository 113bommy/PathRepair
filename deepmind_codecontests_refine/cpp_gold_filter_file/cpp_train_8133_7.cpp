#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 3, nBits = 2e8 + 5, MM = (1 << 16), MAX = 1111,
          OO = 0x3f3f3f3f, MOD = 1000000007, inf = 1 << 30;
const double PI = acos(-1);
const long long INF = (long long)1e18, MOOD = 1000000007;
long long GCD(long long a, long long b) { return !b ? a : GCD(b, a % b); }
long long LCM(long long x, long long y) { return (x * y / GCD(x, y)); }
long long fact(long long z) { return (z <= 1) ? 1 : z * fact(z - 1); }
long long n, m, a, b, c, d, k, mi, mx, ans, A[501][501], B[501][501],
    tmp[501][501];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  ans = n * 3;
  if (m != 1 && m != n) ans += min(n - m, m - 1);
  cout << ans << endl;
  return 0;
}
