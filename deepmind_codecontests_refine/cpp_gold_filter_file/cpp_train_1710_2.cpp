#include <bits/stdc++.h>
using namespace std;
vector<int> SieveOfEratosthenes(int n) {
  vector<bool> prime(n + 1, true);
  for (int p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  vector<int> primes;
  for (int p = 2; p <= n; p++)
    if (prime[p]) primes.push_back(p);
  return primes;
}
int main() {
  vector<int> primes = SieveOfEratosthenes(3200);
  int primesSize = primes.size();
  int n;
  scanf("%d", &n);
  vector<int> divCount(primes.size(), 0);
  map<int, int> newPrimes;
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    for (int j = 0; j < primesSize; ++j) {
      bool div = false;
      while (d % primes[j] == 0) {
        d /= primes[j];
        div = true;
      }
      divCount[j] += div;
    }
    if (d != 1) {
      newPrimes[d]++;
    }
  }
  for (auto p : newPrimes) {
    primes.push_back(p.first);
    divCount.push_back(p.second);
  }
  primesSize = primes.size();
  for (int i = 1; i < primesSize; ++i) divCount[i] += divCount[i - 1];
  int mxPrime = primes.back();
  int mnPrime = 2;
  int m;
  scanf("%d", &m);
  while (--m >= 0) {
    int l, r;
    scanf("%d %d", &l, &r);
    int i = 0, j = primesSize - 1, mid;
    while (i <= j) {
      mid = (i + j) >> 1;
      if (primes[mid] > r)
        j = mid - 1;
      else
        i = mid + 1;
    }
    int ri = i - 1;
    i = 0;
    j = primesSize - 1;
    while (i <= j) {
      mid = (i + j) >> 1;
      if (primes[mid] < l)
        i = mid + 1;
      else
        j = mid - 1;
    }
    int li = j + 1;
    int res = divCount[ri];
    res -= li > 0 ? divCount[li - 1] : 0;
    printf("%d\n", res);
  }
}
