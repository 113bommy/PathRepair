#include <bits/stdc++.h>
using namespace std;
int const INF = numeric_limits<int>::max();
long long const MOD = 1e9 + 7;
long long powm(long long a, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) {
      r *= a;
      r %= MOD;
      p--;
    } else {
      a *= a;
      a %= MOD;
      p >>= 1;
    }
  }
  return r;
}
long long solve(long long n, long long m, long long k) {
  if (k == -1 && (n % 2 == 0 && m % 2 == 1 || n % 2 == 1 && m % 2 == 0))
    return 0;
  long long ans = powm(2, n - 1);
  ans = powm(ans, m - 1);
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  long long n, m, k;
  cin >> n >> m >> k;
  cout << solve(n, m, k) << endl;
  return 0;
}
