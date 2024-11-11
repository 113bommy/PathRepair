#include <bits/stdc++.h>
using namespace std;
long long fastpower(long a, long b, long long n = 1000000007) {
  long res = 1;
  while (b > 0) {
    if ((b & 1) != 0) {
      res = (res % n * a % n) % n;
    }
    a = (a % n * a % n) % n;
    b = b >> 1;
  }
  return res;
}
long long checkPrime(long long n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  long long cprime = 0;
  for (long long p = 2; p <= n; p++)
    if (prime[p]) cprime++;
  return cprime;
}
long long gcd(long long a, long long b) {
  long long c = a % b;
  while (c != 0) {
    a = b;
    b = c;
    c = a % b;
  }
  return b;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    char arr[n][m];
    for (long long i = 0; i < n; i++)
      for (long long j = 0; j < m; j++) cin >> arr[i][j];
    long long ans = 0;
    for (long long i = 0; i < m - 1; i++) {
      if (arr[n - 1][i] == 'D') ans++;
    }
    for (long long i = 0; i < n - 1; i++)
      if (arr[i][m - 1] == 'R') ans++;
    cout << ans << "\n";
  }
  return 0;
}
