#include <bits/stdc++.h>
using namespace std;
set<long long int> s[100005];
long long int d[100005];
vector<char> prime(100000 + 1, true);
void sieve(long long int n) {
  prime[0] = prime[1] = false;
  for (long long int i = 2; i <= n; ++i) {
    if (prime[i]) {
      s[i].insert(i);
      for (long long int j = 2 * i; j <= n; j += i) {
        prime[j] = false;
        s[j].insert(i);
      }
    }
  }
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int fastpowMOD(long long int a, long long int p, long long int MOD) {
  if (p == 0) return 1;
  long long int z = fastpowMOD(a, p / 2, MOD);
  z = (z * z) % MOD;
  if (p % 2) z = (z * a) % MOD;
  return z;
}
long long int fastpow(long long int a, long long int p) {
  if (p == 0) return 1;
  long long int z = fastpow(a, p / 2);
  z = (z * z);
  if (p % 2) z = (z * a);
  return z;
}
long long int a, b;
long long int search1(long long int a[], long long int f, long long int n) {
  long long int left = 1;
  long long int right = n + 1;
  while (right - left > 1) {
    long long int mid = left + (right - left) / 2;
    if (a[mid] < f) {
      left = mid;
    } else
      right = mid;
  }
  return a[left];
}
long long int p = 1e9 + 7;
int main() {
  long long int n, i, j, T;
  cin >> n >> T;
  long long int t[n], g[n];
  for (i = 0; i < n; i++) {
    cin >> t[i] >> g[i];
  }
  long long int dp[(1 << n)][n];
  bool bdp[(1 << n)][n];
  memset(dp, 0, sizeof(dp));
  memset(bdp, 0, sizeof(bdp));
  for (i = 0; i < n; i++) dp[0][i] = 1;
  for (long long int mask = 0; mask < (1 << n) - 1; mask++) {
    if (mask == 0) {
      for (i = 0; i < n; i++) {
        dp[mask | (1 << i)][i] = (dp[mask | (1 << i)][i] + 1) % p;
      }
      continue;
    }
    for (i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (j = 0; j < n; j++) {
          if (!(mask & (1 << j)) && g[j] != g[i]) {
            dp[mask | (1 << j)][j] = (dp[mask | (1 << j)][j] + dp[mask][i]) % p;
          }
        }
      }
    }
  }
  long long int totsum = 0;
  for (long long int mask = 0; mask < (1 << n); mask++) {
    long long int cnt = 0;
    for (i = 0; i < n; i++) {
      if (mask & (1 << i)) cnt += t[i];
    }
    if (cnt == T) {
      for (i = 0; i < n; i++) (totsum = totsum + dp[mask][i]) % p;
    }
  }
  cout << totsum % p << endl;
  return 0;
}
