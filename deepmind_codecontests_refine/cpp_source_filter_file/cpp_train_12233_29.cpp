#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const int MOD = INF + 7;
const int MAXN = 100010;
bool sieve[MAXN];
int main() {
  vector<long long> primes;
  long long p = 1LL;
  memset(sieve, 1, sizeof sieve);
  for (int i = 2; i < MAXN; i++) {
    if (sieve[i]) {
      for (int j = (i << 1); j < MAXN; j += i) {
        sieve[j] = 0;
      }
      primes.push_back(i);
    }
  }
  long long n;
  while (cin >> n) {
    long long ans = 1LL;
    for (long long p : primes) {
      if (n % p == 0) {
        ans *= p;
        while (n % p == 0) {
          n /= p;
        }
      }
    }
    if (n > 1) {
      ans *= n;
    }
    cout << ans << endl;
  }
  return 0;
}
