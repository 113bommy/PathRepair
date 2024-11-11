#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
long long n, m, k, u, v, x, y, t, a, b, ans;
long long C[70][70];
long long f(long long num, int k) {
  if (!k) return 1;
  if (!num || k < 0) return 0;
  int pos = 63 - __builtin_clzll(num);
  return C[pos][k] + f(num ^ (1ll << pos), k - 1);
}
long long get(long long x) { return f(2 * x, k) - f(x, k); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  C[0][0] = 1;
  for (int i = 1; i < 62; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
  }
  cin >> m >> k;
  long long dwn = 1, up = 1e18 + 10;
  while (up - dwn > 1) {
    long long mid = (dwn + up) / 2;
    if (get(mid) < m)
      dwn = mid;
    else
      up = mid;
  }
  return cout << dwn << '\n', 0;
  return 0;
}
