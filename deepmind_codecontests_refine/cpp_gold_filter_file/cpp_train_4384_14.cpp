#include <bits/stdc++.h>
using namespace std;
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
vector<long long> primes;
bool prime[10005];
void seive() {
  memset(prime, 1, sizeof(prime));
  prime[0] = 0;
  prime[1] = 0;
  for (long long i = 2; i <= 10000; i++) {
    if (prime[i] == 1) {
      for (long long j = i * i; j <= 10000; j += i) prime[j] = 0;
    }
  }
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b % 2 == 1) ans = (ans % 1000000007 * a % 1000000007) % 1000000007;
    a = (a * a) % 1000000007;
    b = b / 2;
  }
  return ans;
}
void solve() {
  long long w, h, k;
  cin >> w >> h >> k;
  long long ans = 0;
  long long i, j;
  for (i = 1; i <= k; i++) {
    ans += (2 * w) + (2 * (h - 2));
    w -= 4;
    h -= 4;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  bool codechef = 0;
  long long t = 1;
  if (codechef) cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
