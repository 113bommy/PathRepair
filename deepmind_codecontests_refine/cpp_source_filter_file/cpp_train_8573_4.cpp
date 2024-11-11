#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
long long n, m;
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) {
      res = (res * x) % mod;
    }
    x = (x * x) % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n >> m;
  long long ans = 1;
  long long res = binpow(2ll, m);
  for (long long i = 1; i <= n; ++i) {
    long long cur = (res - i) % mod;
    cur = (cur + mod) % mod;
    ans = (ans * cur) % mod;
  }
  cout << ans << endl;
}
