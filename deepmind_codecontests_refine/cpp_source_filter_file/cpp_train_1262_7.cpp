#include <bits/stdc++.h>
using namespace std;
long long pow2(int n, int m) {
  long long k = 1;
  for (int i = 0; i < m; i++) {
    k += n;
  }
  return k;
}
int main(void) {
  long long n;
  cin >> n;
  long long prod, primes = 2, powers = 0, prime_p[25], prime_q[25];
  prod = n;
  long long prod2 = prod;
  for (int i = 0; i < 25; i++) prime_q[i] = 0;
  while (pow(prod2, 0.5) >= primes) {
    while (prod % primes == 0) {
      if (prime_q[powers] > 0)
        prime_q[powers]++;
      else {
        prime_p[powers] = primes;
        prime_q[powers]++;
      }
      prod /= primes;
      if (prod % primes != 0) powers++;
    }
    primes++;
  }
  powers--;
  if (prod != 1) {
    powers++;
    prime_p[powers] = prod;
    prime_q[powers]++;
  }
  long long m = 1, prime_q2[25];
  for (int i = 0; i <= powers; i++) {
    prime_q2[i] = prime_q[i];
    m *= (prime_q[i] + 1);
  }
  long long x = 1, ans[5000];
  for (int i = 0; i < m; i++) {
    ans[i] = 1;
    for (int j = 0; j <= powers; j++) {
      ans[i] *= pow2(prime_p[j], prime_q2[j]);
    }
    int k = powers;
    prime_q2[k]--;
    while (prime_q2[k] == -1) {
      prime_q2[k] = prime_q[k];
      k--;
      prime_q2[k]--;
    }
  }
  sort(ans, ans + m);
  for (int i = 0; i < m; i++) {
    if (ans[i] == n)
      ans[i] = 1;
    else
      ans[i] = ((n + 2 - ans[i]) * n) / (2 * ans[i]);
  }
  sort(ans, ans + m);
  for (int i = 0; i < m; i++) cout << ans[i] << " ";
}
