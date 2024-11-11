#include <bits/stdc++.h>
using namespace std;
long long dx[] = {1, 0, -1, 0};
long long dy[] = {0, 1, 0, -1};
long long gcd(long long x, long long y) {
  if (y == 0)
    return x;
  else
    return gcd(y, x % y);
}
long long expo(long long n, long long m, long long p) {
  long long r = 1;
  n = n % p;
  while (m > 0) {
    if (m % 2) r = (r * n) % p;
    n = (n * n) % p;
    m = m / 2;
  }
  return r % p;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long n;
const long long N = 1000005;
bool isp[N];
vector<long long> fac[N];
vector<long long> prime;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  memset(isp, true, sizeof(isp));
  for (long long i = 2; i * i < N; i++) {
    if (isp[i]) {
      for (long long j = 2 * i; j < N; j += i) {
        isp[j] = false;
      }
    }
  }
  for (long long i = 1; i < N; i++) {
    if (isp[i]) prime.push_back(i);
  }
  for (long long i = 0; i < prime.size(); i++) {
    for (long long j = 2 * prime[i]; j < N; j += prime[i]) {
      fac[j].push_back(prime[i]);
    }
  }
  long long ans = (1LL << 61);
  for (long long i = 3; i < n; i++) {
    bool ok = false;
    for (long long j = 0; j < fac[n].size(); j++) {
      long long m = i / fac[n][j];
      if (i % fac[n][j]) m++;
      m = m * fac[n][j];
      if (m == n) ok = true;
    }
    if (ok) {
      for (long long j = 0; j < fac[i].size(); j++) {
        long long m = i / fac[i][j];
        ans = min(ans, (m - 1) * fac[i][j] + 1);
      }
    }
  }
  cout << ans << '\n';
}
