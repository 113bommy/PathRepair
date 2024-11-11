#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6, nBits = 2e8 + 5, MM = (1 << 16), MAX = 1111,
          OO = 0x3f3f3f3f, MOD = 1e9 + 7, inf = 1 << 30;
const long long INF = (long long)1e18;
long long GCD(long long a, long long b) { return !b ? a : GCD(b, a % b); }
long long LCM(long long x, long long y) { return (x * y / GCD(x, y)); }
long long fact(long long z) { return (z <= 1) ? 1 : z * fact(z - 1); }
long long n, m;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  cout << (n / 2) * ((n + 1) / 2) * (m / 2) * ((m + 1) / 2) << endl;
  return 0;
}
