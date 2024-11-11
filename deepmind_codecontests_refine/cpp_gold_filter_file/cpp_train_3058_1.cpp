#include <bits/stdc++.h>
using namespace std;
class Math {
 public:
  long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
  }
  long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
  void set_sieve(vector<bool> &sieve, long long n) {
    for (long long i = 2; i * i <= n; i++)
      if (sieve[i])
        for (long long j = i * i; j <= n; j += i) sieve[j] = false;
  }
  long long pow(long long x, long long n) {
    if (n == 0) return 1;
    long long h = pow(x, n / 2);
    if (n & 1) return h * h * x;
    return h * h;
  }
  long long pow(long long x, long long n, long long m) {
    if (n == 0) return 1;
    long long h = pow(x, n / 2) % m;
    if (n & 1) return (h * h * x) % m;
    return (h * h) % m;
  }
} Math;
void solve() {
  long long a, b, n;
  cin >> a >> b >> n;
  a *= 10;
  long long flag = 0;
  for (long long i = 0; i < 10; i++) {
    if ((a + i) % b == 0) {
      a += i;
      flag = 1;
      break;
    }
  }
  n--;
  if (!flag) {
    cout << "-1"
         << "\n";
    return;
  }
  cout << a;
  while (n--) {
    cout << "0";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
