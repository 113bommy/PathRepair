#include <bits/stdc++.h>
using namespace std;
const int range = 5000000;
int spf[range + 1];
bitset<range + 1> isPrime;
void sieve() {
  spf[1] = 0;
  for (long long i = 2; i <= range; i += 2) {
    spf[i] = 2;
  }
  for (long long i = 3; i <= range; i += 2) {
    if (isPrime[i] == false) {
      spf[i] = i;
      for (long long j = i; j * i <= range; j += 2) {
        if (isPrime[i * j] == false) {
          isPrime[i * j] = true;
          spf[i * j] = i;
        }
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();
  long long t, l, r;
  cin >> t >> l >> r;
  long long dp[r + 1], ans = 0, curr = 1;
  dp[1] = 0;
  for (long long i = 2; i <= r; i++) {
    dp[i] =
        (((i * (spf[i] - 1)) / 2) % 1000000007 + dp[i / spf[i]]) % 1000000007;
    if (l <= i) {
      ans = (ans + curr * dp[i]) % 1000000007;
      curr = (curr * t) % 1000000007;
    }
  }
  cout << ans;
  return 0;
}
