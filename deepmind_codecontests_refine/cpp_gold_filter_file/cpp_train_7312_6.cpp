#include <bits/stdc++.h>
using namespace std;
struct hash_pair {
  template <class T1, class T2>
  size_t operator()(const pair<T1, T2>& p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);
    return hash1 ^ hash2;
  }
};
bool prime[10000001];
long long P = 1000000007 - 2;
long long factorial[10000001] = {0};
long long powerFunction(long long x, long long y) {
  long long res = 1;
  long long p = 1000000007;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void sieveFunction(long long maxLimit) {
  memset(prime, true, sizeof(prime));
  prime[0] = prime[1] = false;
  for (long long i = 2; maxLimit >= i; i++) {
    if (prime[i]) {
      for (long long j = 2 * i; maxLimit >= j; j += i) prime[j] = false;
    }
  }
}
void factorialFunction(long long maxLimit) {
  factorial[0] = 1;
  for (long long i = 1; i <= maxLimit; i++)
    factorial[i] = (factorial[i - 1] * i) % 1000000007;
  return;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long arr[n][m];
    for (long long i = 0; n > i; i++) {
      for (long long j = 0; m > j; j++) {
        cin >> arr[i][j];
      }
    }
    long long ans = INT64_MAX;
    for (long long r = 0; n > r; r++) {
      for (long long c = 0; m > c; c++) {
        long long dp[n][m];
        memset(dp, -1, sizeof(dp));
        long long init = arr[r][c] - (r + c + 1) + 1;
        if (init > arr[0][0]) {
          continue;
        }
        dp[0][0] = arr[0][0] - init;
        for (long long i = 1; n > i; i++) {
          long long ht = init + i;
          if (ht > arr[i][0]) {
            break;
          }
          dp[i][0] = dp[i - 1][0] + (arr[i][0] - ht);
        }
        for (long long j = 1; m > j; j++) {
          long long ht = init + j;
          if (ht > arr[0][j]) {
            break;
          }
          dp[0][j] = dp[0][j - 1] + (arr[0][j] - ht);
        }
        for (long long i = 1; n > i; i++) {
          for (long long j = 1; m > j; j++) {
            long long ht = init + i + j;
            if (ht > arr[i][j]) {
              continue;
            }
            long long temp = INT64_MAX;
            if (dp[i][j - 1] != -1) {
              temp = min(temp, dp[i][j - 1] + arr[i][j] - ht);
            }
            if (dp[i - 1][j] != -1) {
              temp = min(temp, dp[i - 1][j] + arr[i][j] - ht);
            }
            if (temp == INT64_MAX) {
              dp[i][j] = -1;
            } else {
              dp[i][j] = temp;
            }
          }
        }
        if (dp[n - 1][m - 1] != -1) {
          ans = min(dp[n - 1][m - 1], ans);
        }
      }
    }
    cout << ans << "\n";
  }
}
