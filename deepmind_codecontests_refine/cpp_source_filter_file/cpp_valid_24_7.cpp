#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const long long maxN = 1e5 + 5;
void debug(vector<long long> vec) {
  long long n = vec.size();
  for (long long i = 0; i < n; i++) cout << vec[i] << " ";
  cout << endl;
  return;
}
long long gcd(long long a, long long b) {
  if (b > a) {
    return gcd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
void solve() {
  long long n;
  cin >> n;
  long long ans = n / 10;
  if (n % 9 == 0) {
    cout << ans + 1 << endl;
  } else {
    cout << ans << endl;
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
