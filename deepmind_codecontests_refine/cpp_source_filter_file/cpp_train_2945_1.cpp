#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  a %= 1000000007;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return res;
}
vector<long long> primes;
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
void Prime(long long n) {
  for (long long i = 2; i <= n; i++) {
    if (isPrime(i)) primes.push_back(i);
  }
}
int32_t main() {
  long long t1;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  Prime(1000);
  long long dp[1000];
  dp[0] = 0;
  for (long long i = 0; i < 1000; i++) {
    dp[i] = dp[i - 1] + 2 * (i + 2);
  }
  cin >> t1;
  while (t1--) {
    long long n;
    cin >> n;
    auto it = lower_bound(primes.begin(), primes.end(), n);
    long long x = it - primes.begin();
    if (primes[x] == n) {
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          cout << 1 << " ";
        }
        cout << '\n';
      }
    } else {
      long long x = dp[n - 1] + 1;
      vector<long long> ans;
      for (long long i = 0; i < n - 1; i++) {
        ans.push_back(2 * (i + 2));
      }
      ans.push_back(1);
      auto it = lower_bound(primes.begin(), primes.end(), x);
      ans[0] += *it - x;
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
          cout << ans[(i + j) % n] << " ";
        }
        cout << '\n';
      }
    }
  }
}
