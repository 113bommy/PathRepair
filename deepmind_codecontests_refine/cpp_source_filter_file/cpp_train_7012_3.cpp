#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10, mod = 1e9 + 7, maxa = 1e6 + 100;
long long sta = 0;
const long long inf = 2e18 + 13;
long long max(long long x, long long y) { return (x > y ? x : y); }
long long min(long long x, long long y) { return (x < y ? x : y); }
long long pw(long long x, long long y) {
  if (!y) {
    return 1;
  }
  long long res = pw(x, y / 2);
  res *= res;
  res %= mod;
  if (y & 1) {
    res *= x;
  }
  return res % mod;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  long long ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = ans * (pw(2, m) - i);
    ans += mod;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
