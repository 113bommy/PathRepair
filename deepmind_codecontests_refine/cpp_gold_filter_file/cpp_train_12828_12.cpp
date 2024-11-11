#include <bits/stdc++.h>
using namespace std;
long long powMod(long long x, long long y) {
  long long res = 1;
  x = x % 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
vector<long long> sieve(long long n) {
  vector<long long> prime(n + 1);
  fill(prime.begin(), prime.end(), 1);
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == 1) {
      for (long long i = p * p; i <= n; i += p) prime[i] = 0;
    }
  }
  return prime;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    long long n, x, y;
    cin >> n >> x >> y;
    long long ma = min(n, x + y - 1);
    long long mi = max((long long)1, min(n, x + y - n + 1));
    cout << mi << " " << ma << endl;
  }
}
