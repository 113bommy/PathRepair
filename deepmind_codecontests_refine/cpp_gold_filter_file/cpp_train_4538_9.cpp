#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
void preprocess(void) {
  vector<int> sieve(1000007, 0);
  for (int i = 2; i < 1000007; i++) {
    if (sieve[i]) {
      continue;
    } else {
      sieve[i] = 1;
      primes.push_back(i);
    }
    for (int j = 2 * i; j < 1000007; j += i) {
      sieve[j] = 1;
    }
  }
  return;
}
int main(void) {
  preprocess();
  int t;
  t = 1;
  for (int z = 1; z <= t; z++) {
    long long n, k;
    scanf("%lld", &n), scanf("%lld", &k);
    k = (k + 1LL) / 2LL;
    while (k > 0) {
      long long etf = n;
      for (int i = 0; i < (int)primes.size(); i++) {
        if (n % primes[i] == 0) {
          etf /= primes[i];
          etf *= (primes[i] - 1);
          while (n % primes[i] == 0) {
            n /= primes[i];
          }
        }
      }
      if (n != 1) {
        etf /= n;
        etf *= (n - 1);
      }
      if (etf == 1LL) {
        printf("%d\n", 1);
        exit(0);
      }
      n = etf;
      k--;
    }
    printf("%lld\n", n % 1000000007);
  }
  return 0;
}
